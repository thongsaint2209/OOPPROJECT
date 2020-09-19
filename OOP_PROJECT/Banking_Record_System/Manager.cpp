#include"Manager.h"

#include"Customer.h"
ManagerMenu::ManagerMenu(Account acc)
{
	fstream f1;

	f1.open("ManagerRequestList.txt", ios::in);

	if (!f1.is_open())
		cout << "Cannot open ManagerRequestsList.txt\n";
	string id ;
	string type ;
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
		
		cout << "1. View requests list.\n";

		cout << "2. Edit requests list.\n";

		cout << "3. View list of accepting requests and processing from director\n";
		cout << "4. View list of customer.\n";
		cout << "5. Edit profile customer).\n";
		
		cout << "6. Fire employee.\n";
		cout << "7. Search information customer\n";
		cout << "8. Search information employee\n";
		cout << "9. View list of employee\n";
		cout << "=================================\n";
		cout << "-> Select option: ";
		cin >> this->_option;

		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please only enter number!" << endl;
				cout << "Enter again: ";
				cin >> this->_option;
			}
			if (!cin.fail())
				break;
		}
		
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
			this->viewlistReDirector();
			break;
		case 4:
			this->viewcustomer();
			break;
		case 5:
			//Customer::Editprofile();
			break;
		case 6:
			this->FireEmployee();
			break;
		case 7:
			this->searchcustomer();
			break;
		case 8:
			this->searchemployee();
			break;
		case 9:
			this->viewemployee();
			break;
		default:
		{
			cout << "Please only enter number from 0 to 7!\n";
			break;
		}
		}
		system("pause");
	}
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
}


//chua xong
void ManagerMenu::viewlistReDirector()
{
	ifstream f1;

	string id;
	string type;
	int money;
	int status;
	
	string	name;
	string	address;
	int	balance;
	f1.open("DirectorRequestsList.txt", ios::in);

	
	if (!f1.is_open())
		cout << "Cannot open DirectorRequestsList.txt\n";

	int i = 0;
	while (f1.good())
	{
		f1 >> id;

		f1 >> type;

		f1 >> money;

		f1 >> status;

		if (f1.eof())
			break;
		Request temp(id, type, money, status);

		this->_requestList2.push_back(temp);
		
		if (this->_requestList2[i].approvalStatus() == 1 && this->_requestList2[i].approvalStatus() == status)
		{
			cout << "Request #" << i + 1 << endl;
			cout << this->_requestList2[i].getId() << endl;
			cout << this->_requestList2[i].getType() << endl;
			cout << this->_requestList2[i].getMoney() << endl;
			cout << endl;
		}
		i++;
	}
	
	f1.close();
	
	
	cout << "Choose id you want to Processing  ";
	while (getchar() != '\n');
	getline(cin, id);

	int flag = 0;
	
			int option;
			cout << "Do you want to  Processing this customer?  " << endl;
			cout << "0: Out" << endl;
			cout << "1: Edit" << endl;
			cin >> option;
			switch (option)
			{
			case 0:
			{
				return;
			}
			case 1:
			{
				int j = 0;

				//tao vector temp 

				while (f1.good())
				{

					if (this->_requestList2[j].getId() == id)
					{
						if (this->_requestList2[j].getType() == "Deposit")
						{
							this->_requestList2[j].getMoney();//goi ham thuc thi



							this->_requestList2.erase(_requestList2.begin() + j);

						}
						else
						{
							this->_requestList2[j].getMoney();

							this->_requestList2.erase(_requestList2.begin() + j);
						}
					}
				}

				ifstream f2;
				f2.open("Customer.txt", ios::in);


				if (!f2.is_open())
					cout << "Cannot open Customer.txt\n";


				int count = 0;
				while (f2.good())
				{
					f2 >> id;
					getline(f2, name);
					getline(f2, name);
					getline(f2, address);
					f2 >> balance;

					if (f1.eof())
						break;
					//Customer temp(id, name, address, balance);
					//this->a.push_back(temp);
					f1.ignore(1, '\n');
					count++;
				}
				f2.close();

				fstream f3;
				f3.open("Customer.txt", ios::out);
				if (!f3.is_open())
					cout << "Cannot open Customer.txt\n";

				for (int i = 0; i < count; i++)
				{

					f3 << a[i].getId();

					f3 << a[i].getname();

					f3 << a[i].getaddress();
					f3 << a[i].getBalance() << endl;

				}
				f3.close();
			}
			default:
			{
				cout << "Please choose number from 0-2" << endl;
				break;
			}
			}
			
	
	

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
		Customer temp(id, name,date, address,phone,mail,Acctype, balance,duration,period);
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


	if (!f1.is_open())
		cout << "Cannot open Custo.txt\n";

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
		f1.ignore(1, '\n');
	
	}
	//cout merits <=90;
	cout << "View List employees have merits < 90 : " << endl;
	for (int i = 0; i < e.size(); i++)
	{
		if (e[i].getmerit()<90)
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
			if(i==temp_pos)
			{
				
				
				this->account.erase(account.begin() + i);

				fstream f3;
				f3.open("EmployeeAccounts.txt", ios::out);
				if (!f3.is_open())
					cout << "EmployeeAccounts.txt\n";

				for (int j = 0; j < this->account.size(); j++)
				{

					f3 << this->account[j].username()<< endl;

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
}

void ManagerMenu::viewemployee()
{

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
}

void ManagerMenu::searchemployee()
{

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
		}
	}
	f1.close();
}

