#include "Employee.h"
#include "AllRole.h"

void Employee::showMenu()
{
	while (true)
	{
		system("cls");
		cout << "\n==========EMPLOYEE-MENU==========\n";
		cout << "1. View profile's information.\n";
		cout << "2. Change password.\n";
		cout << "3. Employee's authority.\n";
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
		{
			while (true)
			{
				system("cls");
				cout << "\n==========EMPLOYEE'S-AUTHORITY-MENU==========\n";
				cout << "1. View And Solving Customer's Requests.\n";
				cout << "2. Search Customers .\n";
				cout << "3. Resign .\n";
				cout << "4. Report Manager .\n";
				cout << "5. Promote .\n";
				cout << "6. View Information of all Customers .\n";
				cout << "7. Solving Manager's Requests .\n";
				cout << "8. Create new account \n";
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
					this->ViewAndSolvingReCus();
					break;
				case 2:
					this->searchCustomer();
					break;
				case 3:
					this->Resign();
					break;
				case 4:
					this->reportManager();
					break;
				case 5:
					this->Promote();
					break;
				case 6:
					this->viewInfoAllCustomer();
					break;
				case 7:
					this->SolvingReManager();
					break;
				case 8:
					this->_c.newAccount();
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
		}
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

void Employee::viewProfile()
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

	f.open("Employee.txt", ios::in);

	if (!f.is_open())
	{
		cout << "Cannot find Employee.txt.\n";
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

void Employee::changePassword()
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
		f.open("EmployeeAccounts.txt", ios::in);
		if (!f.is_open())
			cout << "Cannot open EmployeeAccounts.txt\n";
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
		f.open("EmployeeAccounts.txt", ios::out);
		if (!f.is_open())
			cout << "Cannot open EmployeeAccounts.txt\n";
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

void Employee::ViewAndSolvingReCus() {
	ifstream f1;
	string id;
	string type;
	float money;
	int status;

	f1.open("EmployeeRequestsList.txt", ios::in);

	if (!f1.is_open())
		cout << "Cannot open EmployeeRequestsList.txt\n";
	vector<Request> requestList;
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

		requestList.push_back(temp);

		
		count1++;
	}

	f1.close();
	for (int i = 0;i < requestList.size();i++) {
		cout << requestList[i].getId() << " " << requestList[i].getType() << " " << requestList[i].getMoney() << endl;
	}

	ifstream f2;

	string id1;
	string	name;
	string date;
	string	address;

	string phone;
	string mail;
	string acctype;

	float balance;

	int	duration;
	int	period;
	f2.open("Customer.txt", ios::in);


	if (!f2.is_open())
		cout << "cannot open Customer.txt\n";

	vector<Customer> a;
	int count = 0;
	while (f2.good())
	{
		f2>> id1;
		f2.ignore();
		getline(f2, name);

		getline(f2, date);


		getline(f2, address);

		getline(f2, phone);

		getline(f2, mail);

		getline(f2, acctype);

		f2 >> balance;
		f2 >> duration;
		f2 >> period;

		if (f2.eof())
			break;
		Customer temp(id1, name, date, address, phone, mail, acctype, balance, duration, period);
		a.push_back(temp);
		f2.ignore(1, '\n');
		count++;

	}
	f2.close();

	for (int i = 0;i < a.size();i++) {
		cout << a[i].getId()<<" "  << a[i].getBalance()<<" " << a[i].getbirth()<<endl;
	}
	for (int i = 0;i < requestList.size(); i++) {
		for (int j = 0;j < a.size();j++) {
			if (requestList[i].getId() == a[j].getId()) {
				if (requestList[i].getType() == "Deposit") {
					a[j]._balance += a[j].ClacInrest() + requestList[i].getMoney();
					a[j]._duration =0 ;
					tradeHistory("Deposit", a[j].getname(), requestList[i].getMoney());
				}
				if (requestList[i].getType() == "Withdraw") {
					a[j]._balance += a[j].ClacInrest();
					if (a[j]._balance > requestList[i].getMoney()) {
						a[j]._balance -= requestList[i].getMoney();
						a[j]._duration = 0;
						tradeHistory("Withdraw", a[j].getname(), requestList[i].getMoney());
					}
					

				}
				IncreaseMerit();
				
			}
		}
	}
		

		ofstream f;

		f.open("EmployeeRequestList.txt", ios::out);

		if (!f.is_open())
			cout << "Cannot open EmployeeRequestList.txt\n";

		for (int i = 0; i < requestList.size(); i++)
		{

			f << requestList[i].getId() << endl;
			f << requestList[i].getType() << endl;
			f << requestList[i].getMoney() << endl;
			f << requestList[i].approvalStatus() << endl;
			if (i != requestList.size() - 1)
				f << endl;
		}

		f.close();
		
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

		cout << "Saved successfully\n";
	

}
void Employee::searchCustomer() {
	ifstream f1;
	vector<Customer> a;
	string id;
	string	name;
	string date;
	string	address;

	string phone;
	string mail;
	string Acctype;

	float balance;

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
		a.push_back(temp);
		f1.ignore(1, '\n');
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		cout << "id :" << a[i].getId() << endl;
		cout << endl;
	}
	cin.ignore(1);
	cout << "Choose id you want to dind information about customer   ";
	getline(cin, id);


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
		}
	}
	f1.close();
}
void Employee::Resign() {
	string reason;
	cin.ignore(1);
	cout << "Please describe the reasons for resignation \n ";
	getline(cin, reason);
	fstream f3;
	vector<string> id;
	vector<string> r;
	f3.open("ResignList.txt", ios::in);
	if (!f3.is_open())
		cout << "Cannot open ResignList.txt\n";

	while (f3.good())
	{
		string s1, s2;
		getline(f3, s1);
		getline(f3, s2);
		if (f3.eof()) 
			break;
		id.push_back(s1);
		r.push_back(s2);
	}
	id.push_back(this->_account.username());
	r.push_back(reason);
	fstream f4;
	f4.open("ResignList.txt", ios::out);
	if (!f4.is_open())
		cout << "Cannot open ResignList.txt\n";
	else {
		for (int i = 0; i < id.size(); i++)
		{
			f4 << id[i] << endl;
			f4 << r[i] << endl;
			if (i != id.size() - 1)
				f4 << endl;
		}
			
	}
	f4.close();

	string _id;
	string name;
	string DoB;
	string address;
	string phone;
	string email;
	string merit;
	vector<Employee> temp;

	fstream f;

	f.open("Employee.txt", ios::in);

	if (!f.is_open())
	{
		cout << "Cannot find Employee.txt.\n";
	}

	while (!f.eof())
	{
		getline(f, _id, '\n');
		getline(f, name, '\n');
		getline(f, DoB, '\n');
		getline(f, address, '\n');
		getline(f, phone, '\n');
		getline(f, email, '\n');
		getline(f, merit, '\n');
		f.ignore(1, '\n');

		Employee buffer(_id, name, DoB, address, phone, email, stoi(merit));
		temp.push_back(buffer);
	}
	f.close();


	f.open("Employee.txt", ios::out);

	if (!f.is_open())
	{
		cout << "Save change failed.\n";
	}
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].getId() == _account.username())
		{
			temp.erase(temp.begin() + i);
			break;
		}	
	}
	for (int i = 0; i < temp.size(); i++)
	{
		f << temp[i].getId() << endl;
		f << temp[i].getname() << endl;
		f << temp[i].getbirth() << endl;
		f << temp[i].getaddress() << endl;
		f << temp[i].getphone() << endl;
		f << temp[i].getmail() << endl;
		f << temp[i].getmerit() << endl;
		if (i != temp.size() - 1)
			f << endl;
	}
	f.close();

	cout << "Saved successfully.\n";
}
void Employee::reportManager() {
	string reason;
	string id;

	cin.ignore(1, '\n');

	cout << "Please submit the id who wants to report \n ";
	getline(cin, id);
	cout << "Please describe the reasons for resignation \n ";
	getline(cin, reason);
	fstream f3;
	vector<string> _id;
	vector<string> r;
	f3.open("ReportList.txt", ios::in);
	if (!f3.is_open())
		cout << "Cannot open ReportList.txt\n";

	while (f3.good())
	{
		string s1, s2;
		getline(f3, s1);
		getline(f3, s2);
		if (f3.eof())
			break;

		_id.push_back(s1);
		r.push_back(s2);
	}
	_id.push_back(_account.username());
	r.push_back(reason);

	fstream f4;
	f4.open("ReportList.txt", ios::out);
	if (!f4.is_open())
		cout << "Cannot open ReportList.txt\n";
	else {
		for (int i = 0; i < _id.size(); i++)
		{
			f4 << _id[i] << endl;
			f4 << r[i] << endl;

			if (i != _id.size() - 1)
				f4 << endl;
		}
	}
	f4.close();
}
void Employee::IncreaseMerit() {
	_merits += 10;
}
void Employee::Promote() {
	vector<Account> account;
	vector<Employee> e;
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
		e.push_back(temp);
		f2.ignore(1, '\n');

	}
	f2.close();
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
		account.push_back(temp);

		count++;
	}
	f1.close();

	
	
	f2.open("Manager.txt", ios::in);

	vector<Employee> m;
	if (!f2.is_open())
		cout << "Cannot open Manager.txt\n";

	

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
		m.push_back(temp);
		f2.ignore(1, '\n');

	}
	

	f1.open("ManagerAccounts.txt", ios::in);

	if (!f1.is_open())
		cout << "Cannot open ManagerAccounts.txt\n";
	vector<Account> acc;
	
	int count1 = 0;
	while (f1.good())
	{
		f1 >> username;

		f1 >> password;



		if (f1.eof())
			break;
		Account temp(username, password);
		acc.push_back(temp);

		count1++;
	}
	f1.close();

	for (int i = 0; i < e.size(); i++) {
		if (e[i].getmerit() == 100){
			acc.push_back(account[i]);
			Employee temp(e[i].getId(), e[i].getname(), e[i].getbirth(), e[i].getaddress(), e[i].getphone(), e[i].getmail(), e[i].getmerit());
			
			m.push_back(temp);
			e.erase(e.begin() + i);
			account.erase(account.begin() + i);
		}
	}

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
	
	f4.open("Manager.txt", ios::out);
	if (!f4.is_open())
		cout << "Manager.txt\n";

	for (int l = 0; l < m.size(); l++)
	{

		f4 << m[l].getId() << endl;
		f4 << m[l].getname() << endl;
		f4 << m[l].getbirth() << endl;
		f4 << m[l].getaddress() << endl;
		f4 << m[l].getphone() << endl;

		f4 << m[l].getmail() << endl;

		f4 << m[l].getmerit() << endl;
		f4 << endl;

	}
	f4.close();

	fstream f3;
	f3.open("EmployeeAccounts.txt", ios::out);
	if (!f3.is_open())
		cout << "EmployeeAccounts.txt\n";

	for (int j = 0; j < account.size(); j++)
	{

		f3 << account[j].username() << endl;

		f3 << account[j].password() << endl;


		f3 << endl;

	}
	f3.close();

	;
	f3.open("ManagerAccounts.txt", ios::out);
	if (!f3.is_open())
		cout << "ManagerAccounts.txt\n";

	for (int j = 0; j <acc.size(); j++)
	{

		f3 << acc[j].username() << endl;

		f3 << acc[j].password() << endl;


		f3 << endl;

	}
	f3.close();
	account.clear();
	e.clear();
}
void Employee::viewInfoAllCustomer() {
	ifstream f1;
	vector<Customer> a;
	string id;
	string	name;
	string date;
	string	address;

	string phone;
	string mail;
	string Acctype;

	float balance;

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
		a.push_back(temp);
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
	
}

void Employee::tradeHistory(string type,string name,float money){
	fstream f4;
	f4.open("TransactDate.txt", ios::out);
	if (!f4.is_open())
		cout << "Cannot open TransactDate.txt\n";
	else {
		Date d;
		f4 << d.toString() << endl <<name << endl << type << endl << money << endl;

	}
	f4.close();
	
}

void Employee::SolvingReManager() {
	ifstream f1;

	string id;
	string type;
	int money;
	int status;


	f1.open("ManagerRequestList.txt", ios::in);


	if (!f1.is_open())
		cout << "Cannot open ManagerRequestList.txt\n";
	vector<Request> requestList;
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

		requestList.push_back(temp);


		count1++;
	}

	f1.close();

	ifstream f2;

	string id1;
	string	name;
	string date;
	string	address;

	string phone;
	string mail;
	string Acctype;

	float	balance;

	int	duration;
	int	period;
	f2.open("Customer.txt", ios::in);


	if (!f2.is_open())
		cout << "Cannot open Customer.txt\n";

	vector<Customer> a;
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
		Customer temp(id1, name, date, address, phone, mail, Acctype, balance, duration, period);
		a.push_back(temp);
		f2.ignore(1, '\n');
		count++;

	}
	f2.close();
	for (int i = 0;i < requestList.size();i++) {
		if (requestList[i].approvalStatus() == -1) {
			requestList.erase(requestList.begin() + i);
		}
		else if (requestList[i].approvalStatus() == 1) {
			for (int j = 0;j < a.size();j++) {
				if (requestList[i].getId() == a[j].getId()) {
					if (requestList[i].getType() == "Deposit") {
						a[j]._balance += a[j].ClacInrest() + money;
						a[i]._duration = 0;
						tradeHistory("Deposit", a[j].getname(), requestList[i].getMoney());
					}
					if (requestList[i].getType() == "Withdraw") {
						a[j]._balance += a[j].ClacInrest();
						if (a[j]._balance > money) {
							a[j]._balance -= money;
							a[j]._duration = 0;
							tradeHistory("Withdraw", a[j].getname(), requestList[i].getMoney());
						}
						

					}
					IncreaseMerit();
					requestList.erase(requestList.begin() + i);
				}
			}
		}
	}
		fstream f;

		f.open("ManagerRequestList.txt", ios::out);

		if (!f.is_open())
			cout << "Cannot open ManagerRequestList.txt\n";

		for (int i = 0; i < requestList.size(); i++)
		{

			f << requestList[i].getId() << endl;
			f << requestList[i].getType() << endl;
			f << requestList[i].getMoney() << endl;
			f << requestList[i].approvalStatus() << endl;
			if (i != requestList.size() - 1)
				f << endl;
		}

		f.close();
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

		cout << "Saved successfully\n";
		
}

Employee::Employee(Account acc)
{
	this->_account = acc;
	string id;
	string name;
	string birth;
	string address;
	string phone;
	string mail;
	string merit;
	vector<Employee> temp;

	fstream f;
	f.open("Employee.txt", ios::in);
	if (!f.is_open())
		cout << "Cannot open Employee.txt \n";
	while (f.good())
	{
		getline(f, id);
		getline(f, name);
		getline(f, birth);
		getline(f, address);
		getline(f, phone);
		getline(f, mail);
		getline(f, merit);
		
		if (f.eof())
			break;

		Employee buffer(id, name, birth, address, phone, mail, stoi(merit));
		temp.push_back(buffer);
		f.ignore(1, '\n');
	}
	f.close();

	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].getname() == _account.username())
		{
			_id = temp[i].getId();
			_name = temp[i].getname();
			_birth = temp[i].getbirth();
			_address = temp[i].getaddress();
			_phone = temp[i].getphone();
			_mail = temp[i].getmail();
			_merits = temp[i].getmerit();
			break;
		}
	}
}


