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
				cout << "1.ViewAndSolvingRequests.\n";
				cout << "2. .\n";
				cout << "3. .\n";
				cout << "4. .\n";
				cout << "5. .\n";
				cout << "6. .\n";
				cout << "7. .\n";
				cout << "8. .\n";
				cout << "9. Create new account \n";
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
				//	this->ViewAndSolvingRequests();
					break;
				case 2:
				//	this->searchCustomer();
					break;
				case 3:
				//	this->Resign();
					break;
				case 4:
				//	this->reportManager();
					break;
				case 5:
				//	this->ncreaseMerit();
					break;
				case 6:
				//	this->Promote();
					break;
				case 7:
				//	viewInfoAllCustomer();
					break;
				case 8:
				//	tradeHistory(type, name, money);
				case 9:
				
					_c.newAccount();
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