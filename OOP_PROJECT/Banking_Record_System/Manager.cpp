#include"Manager.h"
#include"AllRole.h"
ManagerMenu::ManagerMenu(Account acc)
{
	fstream f1;

	f1.open("ManagerRequestList.txt", ios::in);

	if (!f1.is_open())
		cout << "Cannot open ManagerRequestsList.txt\n";
	string id;
	string type;
	int money;
	int status;
	while (f1.good())
	{
		f1 >> id;

		f1 >> type;

		f1 >> money;

		f1 >> status;

		if (f1.eof())
			break;
		Request temp(id, type, money, status);
		this->_requestList1.push_back(temp);


	}

	f1.close();

	this->_account = acc;
	this->_option = -1;
}

void ManagerMenu::showMenu()
{

	while (true)
	{
		system("cls");
		cout << "\n==========MANAGER-MENU==========\n";
		cout << "1. View profile's information.\n";
		cout << "2. Change password.\n";
		cout << "3. Manager's authority.\n";
		cout << "0. Logout.\n";
		cout << "=================================\n";
		cout << "-> Select option: ";
		cin >> this->_option;

		_s.checkValid(this->_option);

		if (this->_option == 0)
			break;

		switch (this->_option)
		{
		case 1:
			this->viewProfile();
			break;
		case 2:
			this->changePassword();
			break;
		case 3:
			while (true)
			{
				system("cls");
				cout << "\n==========MANAGER'S-AUTHORITY-MENU==========\n";
				cout << "1. View requests list.\n";
				cout << "2. Edit requests list.\n";
				cout << "3. View list of accepting requests and processing from director\n";
				cout << "4. View list of customer.\n";
				cout << "5. View list of employee.\n"; 
				cout << "6. Search information customer\n";
				cout << "7. Search information employee\n";

				cout << "8. Fire employee\n";

				
				cout << "9. View Non-VIP trade history\n";

				cout << "0. Exit.\n";
				cout << "=================================\n";
				cout << "-> Select option: ";
				cin >> this->_option;
				_s.checkValid(this->_option);

				if (this->_option == 0)
					break;

				switch (this->_option)
				{
				case 1:
					this->viewRequest();
					break;
				case 2:
					this->editRequest();
					break;
				case 3:
					//this->viewlistReDirector();
					this->SolvingReDirector();

					break;
				case 4:
					this->viewcustomer();
					break;
				case 5:
					this->viewemployee();
					break;
				case 6:
					this->searchcustomer();
					break;
				case 7:
					this->searchemployee();
					break;
				case 8:
					 this->FireEmployee();
					break;
				case 9:
					//Employee::viewTradeHistory();
					break;
				default:
				{
					cout << "Please only enter number from 0 to 8!\n";
					break;
				}
				}
				system("pause");
			}
			break;
		default:
		{
			cout << "Please only enter number from 0 to 3!\n";
			break;
		}

		}
		system("pause");
	}
	system("cls");
	cin.ignore(1);

	Menu m;
	m.loginMenu();
	m.redirect();
}

void ManagerMenu::viewRequest()
{
	cout << "\n==========REQUESTS-LIST==========\n";
	for (int i = 0; i < this->_requestList1.size(); i++)
	{
		cout << "Request #" << i + 1 << endl;
		cout << this->_requestList1[i].getId() << endl;
		cout << this->_requestList1[i].getType() << endl;
		cout << this->_requestList1[i].getMoney() << endl;
		if (this->_requestList1[i].approvalStatus() == -1)
			cout << "Denied\n";
		if (this->_requestList1[i].approvalStatus() == 0)
			cout << "Pending\n";
		if (this->_requestList1[i].approvalStatus() == 1)
			cout << "Approved\n";
		cout << endl;
	}
	cout << "=================================\n";
	//	_requestList1.clear();
}

void ManagerMenu::editRequest()
{
	while (true)
	{
		system("cls");
		this->viewRequest();

		int index = 0;
		cout << endl;

		while (true)
		{
			cout << "-> Select request to edit (Enter -1 to exit and save change): ";
			cin >> index;

			if (index == -1)
				break;

			index--;

			if (index > -1 && index < this->_requestList1.size())
				break;

			cout << "Cannot find request #" << index + 1 << endl;
		}

		if (index == -1)
			break;

		while (true)
		{
			int temp = -1;
			cout << "-> 0: Denied.\n";
			cout << "-> 1: Approve.\n";
			cout << "-> Which action do you want?: ";
			cin >> temp;

			if (temp == 0)
			{
				this->_requestList1[index].denyRequest();
				break;
			}

			if (temp == 1)
			{
				this->_requestList1[index].approveRequest();
				break;
			}

			cout << "Wrong mode.\n";
		}
	}

	fstream f;

	f.open("ManagerRequestList.txt", ios::out);

	if (!f.is_open())
		cout << "Cannot open DirectorRequestsList.txt\n";

	for (int i = 0; i < this->_requestList1.size(); i++)
	{

		f << this->_requestList1[i].getId() << endl;
		f << this->_requestList1[i].getType() << endl;
		f << this->_requestList1[i].getMoney() << endl;
		f << this->_requestList1[i].approvalStatus() << endl;
		if (i != this->_requestList1.size() - 1)
			f << endl;
	}

	f.close();

	cout << "Saved successfully\n";
	//_requestList1.clear();
}

void ManagerMenu::IncreaseMerit()
{
	_merits += 10;
}


void ManagerMenu::viewcustomer()
{

	ifstream f1;

	string id;
	string	name;
	string date;
	string	address;

	string phone;
	string mail;
	string Acctype;

	int	balance;

	int	duration;
	int	period;
	f1.open("Customer.txt", ios::in);


	if (!f1.is_open())
		cout << "Cannot open Customer.txt\n";

	int i = 0;
	int count = 0;
	while (f1.good())
	{
		f1 >> id;
		f1.ignore();
		getline(f1, name);

		getline(f1, date);


		getline(f1, address);

		getline(f1, phone);

		getline(f1, mail);

		getline(f1, Acctype);

		f1 >> balance;
		f1 >> duration;
		f1 >> period;

		if (f1.eof())
			break;
		Customer temp(id, name, date, address, phone, mail, Acctype, balance, duration, period);
		this->a.push_back(temp);
		f1.ignore(1, '\n');
		count++;
	}

	for (int i = 0; i < count; i++)
	{
		cout << "Request #" << i + 1 << endl;
		cout << "id :" << a[i].getId() << endl;
		cout << "name :" << a[i].getname() << endl;
		cout << "birthday :" << a[i].getbirth() << endl;
		cout << "address :" << a[i].getaddress() << endl;
		cout << "phone :" << a[i].getphone() << endl;
		cout << "mail:" << a[i].getmail() << endl;
		cout << "Acc type :" << a[i].getacctype() << endl;
		cout << "balance :" << a[i].getBalance() << endl;
		cout << "duration :" << a[i].getDuration() << endl;
		cout << "period :" << a[i].getPeriod() << endl;
		cout << endl;
	}
	f1.close();
	a.clear();
}

void ManagerMenu::searchcustomer()
{

	ifstream f1;

	string id;
	string	name;
	string date;
	string	address;

	string phone;
	string mail;
	string Acctype;

	int	balance;

	int	duration;
	int	period;
	f1.open("Customer.txt", ios::in);


	if (!f1.is_open())
		cout << "Cannot open Customer.txt\n";

	int i = 0;
	int count = 0;
	while (f1.good())
	{
		f1 >> id;
		f1.ignore();
		getline(f1, name);

		getline(f1, date);


		getline(f1, address);

		getline(f1, phone);

		getline(f1, mail);

		getline(f1, Acctype);

		f1 >> balance;
		f1 >> duration;
		f1 >> period;


		if (f1.eof())
			break;
		Customer temp(id, name, date, address, phone, mail, Acctype, balance, duration, period);
		this->a.push_back(temp);
		f1.ignore(1, '\n');
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		cout << "id :" << a[i].getId() << endl;
		cout << endl;
	}
	cout << "Choose id you want to dind information about customer   ";
	while (getchar() != '\n');
	getline(cin, id);

	int dem = 0;
	for (int i = 0; i < count; i++)
	{
		if (a[i].getId() == id)
		{
			cout << "Request #" << i + 1 << endl;
			cout << "id :" << a[i].getId() << endl;
			cout << "name :" << a[i].getname() << endl;
			cout << "birthday :" << a[i].getbirth() << endl;
			cout << "address :" << a[i].getaddress() << endl;
			cout << "phone :" << a[i].getphone() << endl;
			cout << "mail:" << a[i].getmail() << endl;
			cout << "Acc type :" << a[i].getacctype() << endl;
			cout << "balance :" << a[i].getBalance() << endl;
			cout << "duration :" << a[i].getDuration() << endl;
			cout << "period :" << a[i].getPeriod() << endl;
			cout << endl;
			break;
		}
		dem++;
	}
	if (dem == count)
	{
		cout << "ID does not exist " << endl;
	}
	f1.close();
	a.clear();
}

void ManagerMenu::FireEmployee()
{
	fstream f1;

	f1.open("EmployeeAccounts.txt", ios::in);

	if (!f1.is_open())
		cout << "Cannot open EmployeeAccounts.txt\n";

	string username;
	string password;
	int count = 0;
	while (f1.good())
	{
		f1 >> username;

		f1 >> password;



		if (f1.eof())
			break;
		Account temp(username, password);
		this->account.push_back(temp);

		count++;
	}
	f1.close();

	string id;
	string	name;
	string date;
	string	address;

	string phone;
	string mail;


	int	merits;
	fstream f2;
	f2.open("Employee.txt", ios::in);


	if (!f2.is_open())
		cout << "Cannot open Employee.txt\n";
	int i = 0;
	while (f2.good())
	{
		f2 >> id;
		f2.ignore();
		getline(f2, name);

		getline(f2, date);


		getline(f2, address);

		getline(f2, phone);

		getline(f2, mail);




		f2 >> merits;


		if (f2.eof())
			break;
		Employee temp(id, name, date, address, phone, mail, merits);
		this->e.push_back(temp);
		f2.ignore(1, '\n');

	}
	//cout merits <=90;
	cout << "View List employees have merits < 90 : " << endl;
	for (int i = 0; i < e.size(); i++)
	{
		if (e[i].getmerit() < 90)
		{

			cout << "id :" << e[i].getId() << endl;
			cout << "name :" << e[i].getname() << endl;
			cout << "birthday :" << e[i].getbirth() << endl;
			cout << "address :" << e[i].getaddress() << endl;
			cout << "phone :" << e[i].getphone() << endl;
			cout << "mail:" << e[i].getmail() << endl;

			cout << "merits :" << e[i].getmerit() << endl;
			cout << endl;
		}
	}

	cout << "Enter id you want to Delete :";
	while (getchar() != '\n');
	getline(cin, id);



	int option;
	cout << "Do you want to delete this employee?  " << endl;
	cout << "0: Out" << endl;
	cout << "1: Delete" << endl;
	cin >> option;
	int temp_pos;
	switch (option)
	{
	case 0:
	{
		return;
	}
	case 1:
	{
		for (int k = 0; k < e.size(); k++)
		{
			if (e[k].getId() == id)
			{
				temp_pos = k;
				e.erase(e.begin() + k);

				fstream f4;
				f4.open("Employee.txt", ios::out);
				if (!f4.is_open())
					cout << "Employee.txt\n";

				for (int l = 0; l < e.size(); l++)
				{

					f4 << e[l].getId() << endl;
					f4 << e[l].getname() << endl;
					f4 << e[l].getbirth() << endl;
					f4 << e[l].getaddress() << endl;
					f4 << e[l].getphone() << endl;

					f4 << e[l].getmail() << endl;

					f4 << e[l].getmerit() << endl;
					f4 << endl;

				}

				f4.close();
			}

		}

		for (int i = 0; i < this->account.size(); i++)
		{
			if (i == temp_pos)
			{
				this->account.erase(account.begin() + i);

				fstream f3;
				f3.open("EmployeeAccounts.txt", ios::out);
				if (!f3.is_open())
					cout << "EmployeeAccounts.txt\n";

				for (int j = 0; j < this->account.size(); j++)
				{

					f3 << this->account[j].username() << endl;

					f3 << this->account[j].password() << endl;


					f3 << endl;

				}
				f3.close();


			}
		}

		cout << "Delete successfully " << endl;
	}
	default:
	{

		break;
	}
	}
	e.clear();
	account.clear();
}

void ManagerMenu::viewemployee()
{
	e.clear();
	ifstream f1;

	string id;
	string	name;
	string date;
	string	address;

	string phone;
	string mail;
	int merits;
	f1.open("Employee.txt", ios::in);


	if (!f1.is_open())
		cout << "Cannot open Employee.txt\n";

	int i = 0;
	int count = 0;
	while (f1.good())
	{
		f1 >> id;
		f1.ignore();
		getline(f1, name);

		getline(f1, date);


		getline(f1, address);

		getline(f1, phone);

		getline(f1, mail);


		f1 >> merits;

		if (f1.eof())
			break;
		Employee temp(id, name, date, address, phone, mail, merits);
		e.push_back(temp);
		f1.ignore(1, '\n');
		count++;
	}

	for (int i = 0; i < e.size(); i++)
	{

		cout << "id :" << e[i].getId() << endl;
		cout << "name :" << e[i].getname() << endl;
		cout << "birthday :" << e[i].getbirth() << endl;
		cout << "address :" << e[i].getaddress() << endl;
		cout << "phone :" << e[i].getphone() << endl;
		cout << "mail:" << e[i].getmail() << endl;


		cout << "merit :" << e[i].getmerit() << endl;
		cout << endl;
	}
	f1.close();
	e.clear();
}

void ManagerMenu::searchemployee()
{
	e.clear();
	ifstream f1;

	string id;
	string	name;
	string date;
	string	address;

	string phone;
	string mail;
	int merits;
	f1.open("Employee.txt", ios::in);


	if (!f1.is_open())
		cout << "Cannot open Employee.txt\n";

	int i = 0;
	int count = 0;
	while (f1.good())
	{
		f1 >> id;
		f1.ignore();
		getline(f1, name);

		getline(f1, date);


		getline(f1, address);

		getline(f1, phone);

		getline(f1, mail);


		f1 >> merits;



		if (f1.eof())
			break;
		Employee temp(id, name, date, address, phone, mail, merits);
		e.push_back(temp);
		f1.ignore(1, '\n');
		count++;
	}
	for (int i = 0; i < e.size(); i++)
	{
		cout << "id :" << e[i].getId() << endl;
		cout << endl;
	}
	cout << "Choose id you want to dind information about employee   ";
	while (getchar() != '\n');
	getline(cin, id);

	int dem = 0;
	for (int i = 0; i < e.size(); i++)
	{
		if (e[i].getId() == id)
		{
			cout << "id :" << e[i].getId() << endl;
			cout << "name :" << e[i].getname() << endl;
			cout << "birthday :" << e[i].getbirth() << endl;
			cout << "address :" << e[i].getaddress() << endl;
			cout << "phone :" << e[i].getphone() << endl;
			cout << "mail:" << e[i].getmail() << endl;


			cout << "merit :" << e[i].getmerit() << endl;
			cout << endl;
			break;
		}
		dem++;
	}
	if (dem == e.size())
	{
		cout << "id does not exist " << endl;
	}
	f1.close();
	e.clear();
}

void ManagerMenu::viewProfile()
{
	string id;
	string name;
	string DoB;
	string address;
	string phone;
	string email;
	string merit;
	vector<Employee> temp;

	fstream f;

	f.open("Manager.txt", ios::in);

	if (!f.is_open())
	{
		cout << "Cannot find Manager.txt.\n";
	}

	while (!f.eof())
	{
		getline(f, id, '\n');
		getline(f, name, '\n');
		getline(f, DoB, '\n');
		getline(f, address, '\n');
		getline(f, phone, '\n');
		getline(f, email, '\n');
		getline(f, merit, '\n');
		f.ignore(1, '\n');

		Employee buffer(id, name, DoB, address, phone, email, stoi(merit));
		temp.push_back(buffer);
	}
	f.close();

	system("cls");
	cout << "\n==========PROFILE-INFORMATION==========\n";
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].getId() == _account.username())
		{
			cout << "ID          : " << temp[i].getId() << endl;
			cout << "Name        : " << temp[i].getname() << endl;
			cout << "DoB         : " << temp[i].getbirth() << endl;
			cout << "Address     : " << temp[i].getaddress() << endl;
			cout << "Phone Number: " << temp[i].getphone() << endl;
			cout << "Email       : " << temp[i].getmail() << endl;
			cout << "Merit       : " << temp[i].getmerit() << endl;
		}
	}
}

void ManagerMenu::changePassword()
{
	while (getchar() != '\n');
	string cur = "", pass = "";
	vector<Account> a;
	int times = 0;
OPTION:
	if (times == 10)
	{
		cout << "You have reached maximum change password times. Please try again later.\n";
		return;
	}

	cout << "Enter your current password: \n";
	cur.clear();
	getline(cin, cur);
	cout << "Enter your new password: \n";
	pass.clear();
	getline(cin, pass);
	bool flag = 0;

	if (strcmp(_account.password().c_str(), cur.c_str()) == 0)
	{
		_account.changePassword(pass);
		cout << "Change password Successfully!" << endl;

		fstream f;
		f.open("ManagerAccounts.txt", ios::in);
		if (!f.is_open())
			cout << "Cannot open ManagerAccounts.txt\n";
		else
		{
			string _username, _password;

			while (f.good())
			{
				f >> _username;
				f >> _password;

				if (f.eof())
					break;

				Account buffer(_username, _password);
				a.push_back(buffer);
			}
			f.close();
		}
		f.open("ManagerAccounts.txt", ios::out);
		if (!f.is_open())
			cout << "Cannot open ManagerAccounts.txt\n";
		else
		{


			for (int i = 0; i < a.size(); i++)
			{
				if (a[i].username() == _account.username())
				{
					a[i].changePassword(_account.password());
				}
				f << a[i].username() << endl;
				f << a[i].password() << endl;
				if (i != a.size() - 1)
					f << endl;
			}
			f.close();
		}

	}
	else
	{
		cout << "Wrong password. Please try again" << endl;
		times++;
		goto OPTION;
	}
	return;
}

/*void ManagerMenu::viewTradeHistory()
{
	string _time;
	string _id;
	string _type;
	string _money;
	
	

	fstream f;
	f.open("TransactDate.txt", ios::in);
	if (!f.is_open())
		cout << "Cannot open TransactDate.txt\n";
	while (f.good())
	{
		getline(f, _time);
		getline(f, _id);
		getline(f, _type);
		getline(f, _money);
		f.ignore(1, '\n');

		TradeHistory buffer(_time, _id, _type, stof(_money));
		_his.push_back(buffer);

		if (f.eof())
			break;
	}
	cout << "===NON-VIP-TRADE-HISTORY===" << endl;
	for (int i = 0; i < _his.size(); i++)
	{
		if (_his[i].getMoney() < 10000000)
		{
			
			cout << _his[i].getTime() << endl;
			cout << _his[i].getId() << endl;
			cout << _his[i].getType() << endl;
			cout << _his[i].getMoney() << endl;
		}
	}
	f.close();
	_his.clear();
}
*/
void ManagerMenu::SolvingReDirector() {
	string id;
	string id1;
	string	name;
	string date;
	string	address;

	string phone;
	string mail;
	string Acctype;

	float	balance;
	int merits;
	int	duration;
	int	period;
	string type;
	int money;
	int status;
	
	vector<ManagerMenu> _ma;
	_ma.clear();
	ifstream f6;
	f6.open("Manager.txt", ios::in);

	string id3;

	if (!f6.is_open())
		cout << "Cannot open Manager.txt\n";
	while (!f6.eof())
	{
		f6 >> id;
		f6.ignore();
		getline(f6, name);
		
		getline(f6, date);


		getline(f6, address);

		getline(f6, phone);

		getline(f6, mail);

		f6 >> merits;
		
		ManagerMenu temp1(id, name, date, address, phone, mail, merits);
		_ma.push_back(temp1);
		f6.ignore(1, '\n');
		

	}
	_ma.pop_back();
	
	ifstream f1;

	

	vector<Request> _requestList2;
	f1.open("DirectorRequestsList.txt", ios::in);


	if (!f1.is_open())
		cout << "Cannot open DirectorRequestsList.txt\n";
	
	int count1 = 0;
	while (f1.good())
	{
		f1 >> id;

		f1 >> type;

		f1 >> money;

		f1 >> status;

		if (f1.eof())
			break;
		Request temp(id, type, money, status);

		_requestList2.push_back(temp);


		count1++;
	}
	for (int m = 0; m < _requestList2.size(); m++)
	{
		if (_requestList2[m].approvalStatus() == 1 && _requestList2[m].approvalStatus() == status)
		{
			cout << "Request #" << m + 1 << endl;
			cout <<_requestList2[m].getId() << endl;
			cout << _requestList2[m].getType() << endl;
			cout << _requestList2[m].getMoney() << endl;
			cout << _requestList2[m].approvalStatus() << endl;
			cout << endl;
		}
	}
	f1.close();

	ifstream f2;

	
	f2.open("Customer.txt", ios::in);


	if (!f2.is_open())
		cout << "Cannot open Customer.txt\n";

	
	int count = 0;
	while (f2.good())
	{
		f2 >> id1;
		f2.ignore();
		getline(f2, name);

		getline(f2, date);


		getline(f2, address);

		getline(f2, phone);

		getline(f2, mail);

		getline(f2, Acctype);

		f2 >> balance;
		f2 >> duration;
		f2 >> period;

		if (f2.eof())
			break;
		Customer temp4(id1, name, date, address, phone, mail, Acctype, balance, duration, period);
		a.push_back(temp4);
		f2.ignore(1, '\n');
		count++;

	}
	
	

	f2.close();

	int dem=0;
	for (int i = 0; i < _requestList2.size(); i++) {
		if (_requestList2[i].approvalStatus() != 1) {
			_requestList2.erase(_requestList2.begin() + i);
		}
		else if (_requestList2[i].approvalStatus() == 1) {
			for (int j = 0; j < a.size(); j++) 
			{
				if (_requestList2[i].getId() == a[j].getId()) {
					if (_requestList2[i].getType() == "Deposit") {
						a[j]._balance += a[j].ClacInrest() + _requestList2[i].getMoney();
						a[i]._duration = 0;
						Employee::tradeHistory("Deposit", a[j].getname(), _requestList2[i].getMoney());
						//this->_requestList2[i].approvalStatus() == -1;
						dem++;
					}
					if (_requestList2[i].getType() == "Withdraw") {
						a[j]._balance += a[j].ClacInrest();
						if (a[j]._balance > _requestList2[i].getMoney()) {
							a[j]._balance -= _requestList2[i].getMoney();
							a[j]._duration = 0;
							Employee::tradeHistory("Withdraw", a[j].getname(), _requestList2[i].getMoney());
							//this->_requestList2[i].approvalStatus() == -1;
						}
						dem++;

					}
				}
				
				//_requestList2.erase(_requestList2.begin() + i);
			}
		}
		
	}
	_requestList2.clear();
	fstream f;

	//f.open("DirectorRequestsList.txt", ios::out);


	//f.close();

	
	fstream f3;
	f3.open("Customer.txt", ios::out);
	if (!f3.is_open())
		cout << "Cannot open Customer.txt\n";

	for (int i = 0; i < a.size(); i++)
	{
		f3 << a[i]._id << endl;
		f3 << a[i]._name << endl;
		f3 << a[i]._birth << endl;
		f3 << a[i]._address << endl;
		f3 << a[i]._phone << endl;
		f3 << a[i]._mail << endl;
		f3 << a[i]._acctype << endl;
		f3 << a[i]._balance << endl;
		f3 << a[i]._duration << endl;
		f3 << a[i]._period << endl;
		f3 << endl;

	}
	f3.close();

	f6.close();
	fstream f7;
	f7.open("Manager.txt", ios::out);
	if (!f7.is_open())
		cout << "Cannot open Manager.txt\n";

	for (int q = 0; q < _ma.size(); q++)
	{
		if (_ma[q]._id == _account.username())
		{
			for(int g=0;g<dem;g++)
			_ma[q].IncreaseMerit();
		}
		f7 << _ma[q]._id << endl;
		f7 << _ma[q]._name << endl;
		f7 << _ma[q]._birth << endl;
		f7 << _ma[q]._address << endl;
		f7 << _ma[q]._phone << endl;
		f7 << _ma[q]._mail << endl;
		f7 << _ma[q]._merits << endl;

		f7 << endl;

	}
	f7.close();


	cout << "Saved successfully\n";
	a.clear();
	_requestList2.clear();
	_ma.clear();
}
