#include "Director.h"
#include "Customer.h"
#include "Employee.h"
#include "Manager.h"

DirectorMenu::DirectorMenu(Account acc)
{
	fstream f;

	f.open("DirectorRequestsList.txt", ios::in);

	if (!f.is_open())
		cout << "Cannot open DirectorRequestsList.txt\n";

	string id;
	string type;
	int money;
	int status;
	while (f.good())
	{
		f >> id;

		f >> type;

		f >> money;

		f >> status;

		if (f.eof())
			break;
		Request temp(id, type, money, status);
		this->_requestList.push_back(temp);
	}

	f.close();

	this->_account = acc;
	this->_mode = -1;
}

void DirectorMenu::showMenu()
{
	while (true)
	{
		system("cls");
		cout << "\n==========DIRECTOR-MENU==========\n";
		cout << "1. View requests list.\n";
		cout << "2. Edit requests list.\n";
		cout << "3. View total money.\n";
		cout << "4. View total customer.\n";
		cout << "5. View VIP customer.\n";
		cout << "6. Fire manager/employee.\n";
		cout << "7. View report/feedback.\n";
		cout << "8. Search manager/employee/customer.\n";
		cout << "9. View manager/employee/customer.\n";
		cout << "0. Exit.\n";
		cout << "=================================\n";
		cout << "-> Select mode: ";
		cin >> this->_mode;

		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please only enter number!" << endl;
				cout << "Enter again: ";
				cin >> this->_mode;
			}
			if (!cin.fail())
				break;
		}

		if (this->_mode == 0)
			break;

		switch (this->_mode)
		{
		case 1:
			this->viewRequest();
			break;
		case 2:
			this->editRequest();
			break;
		case 3:
		{
			cout << "=================================\n";
			cout << "Total Money In Bank: ";
			cout << this->getTotalMoney() << endl;
			cout << "=================================\n";
			break;
		}
		case 4:
		{
			cout << "=================================\n";
			cout << "Total Bank's Customer: ";
			cout << this->getTotalCustomer() << endl;
			cout << "=================================\n";
			break;
		}
		case 5:
			this->viewVIPCustomer();
			break;
		case 6:
			this->showFireMenu();
			break;
		case 7:
			this->viewFeedBack();
			break;
		case 8:
			this->searchEmployee();
			break;
		case 9:
			this->viewEmployee();
			break;
		default:
		{
			cout << "Please only enter number from 0 to 9!\n";
			break;
		}
		}
		system("pause");
	}
}

void DirectorMenu::viewRequest()
{
	cout << "\n==========REQUESTS-LIST==========\n";
	for (int i = 0; i < this->_requestList.size(); i++)
	{
		cout << "Request #" << i + 1 << endl;
		cout << this->_requestList[i].getId() << endl;
		cout << this->_requestList[i].getType() << endl;
		cout << this->_requestList[i].getMoney() << endl;
		if (this->_requestList[i].approvalStatus() == -1)
			cout << "Denied\n";
		if (this->_requestList[i].approvalStatus() == 0)
			cout << "Pending\n";
		if (this->_requestList[i].approvalStatus() == 1)
			cout << "Approved\n";
		cout << endl;
	}
	cout << "=================================\n";
}

void DirectorMenu::editRequest()
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

			if (index > -1 && index < this->_requestList.size())
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
				this->_requestList[index].denyRequest();
				break;
			}

			if (temp == 1)
			{
				this->_requestList[index].approveRequest();
				break;
			}

			cout << "Wrong mode.\n";
		}
	}

	fstream f;

	f.open("DirectorRequestsList.txt", ios::out);

	if (!f.is_open())
		cout << "Cannot open DirectorRequestsList.txt\n";

	for (int i = 0; i < this->_requestList.size(); i++)
	{
		f << this->_requestList[i].getId() << endl;
		f << this->_requestList[i].getType() << endl;
		f << this->_requestList[i].getMoney() << endl;
		f << this->_requestList[i].approvalStatus() << endl;
		if (i != this->_requestList.size() - 1)
			f << endl;
	}

	f.close();

	cout << "Saved successfully.\n";
}

string DirectorMenu::getTotalMoney()
{
	//local variables
	vector<Customer> temp;
	//read file buffers
	string id;
	string name;
	string date;
	string address;
	string phone;
	string mail;
	string Acctype;
	string balance;
	string duration;
	string period;
	fstream f;

	f.open("Customer.txt", ios::in);

	if (!f.is_open())
		cout << "Cannot open Customer.txt\n";

	while (f.good())
	{
		f >> id;
		f.ignore();
		getline(f, name);
		getline(f, date);
		getline(f, address);
		getline(f, phone);
		getline(f, mail);
		getline(f, Acctype);
		getline(f, balance);
		getline(f, duration);
		getline(f, period);

		if (f.eof())
			break;

		Customer temp1(id, name, date, address, phone, mail, Acctype, stoi(balance), stoi(duration), stoi(period));
		temp.push_back(temp1);
		f.ignore(1, '\n');
	}
	f.close();

	//calc total money
	float sum = 0;
	for (int i = 0; i < temp.size(); i++)
		sum += temp[i].getBalance();

	return to_string((int)sum);
}

int DirectorMenu::getTotalCustomer()
{
	//local variables
	vector<Customer> temp;
	//read file buffers
	string id;
	string name;
	string date;
	string address;
	string phone;
	string mail;
	string Acctype;
	string balance;
	string duration;
	string period;
	fstream f;

	f.open("Customer.txt", ios::in);

	if (!f.is_open())
		cout << "Cannot open Customer.txt\n";

	while (f.good())
	{
		f >> id;
		f.ignore();
		getline(f, name);
		getline(f, date);
		getline(f, address);
		getline(f, phone);
		getline(f, mail);
		getline(f, Acctype);
		getline(f, balance);
		getline(f, duration);
		getline(f, period);

		if (f.eof())
			break;

		Customer temp1(id, name, date, address, phone, mail, Acctype, stoi(balance), stoi(duration), stoi(period));
		temp.push_back(temp1);
		f.ignore(1, '\n');
	}
	f.close();

	return temp.size();
}

void DirectorMenu::viewVIPCustomer()
{
	//local variables
	vector<Customer> temp;
	//read file buffers
	string id;
	string name;
	string date;
	string address;
	string phone;
	string mail;
	string Acctype;
	string balance;
	string duration;
	string period;
	fstream f;

	f.open("Customer.txt", ios::in);

	if (!f.is_open())
		cout << "Cannot open Customer.txt\n";

	while (f.good())
	{
		f >> id;
		f.ignore();
		getline(f, name);
		getline(f, date);
		getline(f, address);
		getline(f, phone);
		getline(f, mail);
		getline(f, Acctype);
		getline(f, balance);
		getline(f, duration);
		getline(f, period);

		if (f.eof())
			break;

		Customer temp1(id, name, date, address, phone, mail, Acctype, stoi(balance), stoi(duration), stoi(period));
		temp.push_back(temp1);
		f.ignore(1, '\n');
	}
	f.close();

	int count = 0;
	system("cls");
	cout << "\n==========VIP-CUSTOMER==========\n";
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].getBalance() > 99999999)
		{
			cout << "#" << ++count << endl;
			cout << "ID          : " << temp[i].getId() << endl;
			cout << "Name        : " << temp[i].getname() << endl;
			cout << "DoB         : " << temp[i].getbirth() << endl;
			cout << "Address     : " << temp[i].getaddress() << endl;
			cout << "Phone Number: " << temp[i].getphone() << endl;
			cout << "Email       : " << temp[i].getmail() << endl;
			cout << "Account Type: " << temp[i].getacctype() << endl;
			cout << "Balance     : " << temp[i].getBalance() << endl;
			if (i != temp.size() - 1)
				cout << endl;
		}
	}
	cout << "================================\n";
	cout << "Press anykey to go back.\n";
}

void DirectorMenu::searchEmployee()
{
	while (true)
	{
		int mode = -1;
		system("cls");
		cout << "\n==========SEARCH-MENU==========\n";
		cout << "1. Search Manager.\n";
		cout << "2. Search Employee.\n";
		cout << "3. Search Customer.\n";
		cout << "0. Exit.\n";
		cout << "===============================\n";
		cout << "-> Select mode: ";
		cin >> mode;
		cin.ignore(1);

		if (mode == 0)
			return;

		if (mode == 1)
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
				continue;
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

			string idTemp = "";
			cout << "===============================\n";
			cout << "-> Enter ID to search: ";
			getline(cin, idTemp);
			cout << "===============================\n";

			for (int i = 0; i < temp.size(); i++)
			{
				if (temp[i].getId() == idTemp)
				{
					cout << "ID          : " << temp[i].getId() << endl;
					cout << "Name        : " << temp[i].getname() << endl;
					cout << "DoB         : " << temp[i].getbirth() << endl;
					cout << "Address     : " << temp[i].getaddress() << endl;
					cout << "Phone Number: " << temp[i].getphone() << endl;
					cout << "Email       : " << temp[i].getmail() << endl;
					cout << "Merit       : " << temp[i].getmerit() << endl;
					cout << "===============================\n";
					goto SHORTCUT;
				}
			}

			cout << "No manager with ID <" << idTemp << ">.\n";
			cout << "===============================\n";
			goto SHORTCUT;
		}

		if (mode == 2)
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
				continue;
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

			string idTemp = "";
			cout << "===============================\n";
			cout << "-> Enter ID to search: ";
			getline(cin, idTemp);
			cout << "===============================\n";

			for (int i = 0; i < temp.size(); i++)
			{
				if (temp[i].getId() == idTemp)
				{
					cout << "ID          : " << temp[i].getId() << endl;
					cout << "Name        : " << temp[i].getname() << endl;
					cout << "DoB         : " << temp[i].getbirth() << endl;
					cout << "Address     : " << temp[i].getaddress() << endl;
					cout << "Phone Number: " << temp[i].getphone() << endl;
					cout << "Email       : " << temp[i].getmail() << endl;
					cout << "Merit       : " << temp[i].getmerit() << endl;
					cout << "===============================\n";
					goto SHORTCUT;
				}
			}

			cout << "No employee with ID <" << idTemp << ">.\n";
			cout << "===============================\n";
			goto SHORTCUT;
		}

		if (mode == 3)
		{
			//local variables
			vector<Customer> temp;
			//read file buffers
			string id;
			string name;
			string date;
			string address;
			string phone;
			string mail;
			string Acctype;
			string balance;
			string duration;
			string period;
			fstream f;

			f.open("Customer.txt", ios::in);

			if (!f.is_open())
				cout << "Cannot open Customer.txt\n";

			while (f.good())
			{
				f >> id;
				f.ignore();
				getline(f, name);
				getline(f, date);
				getline(f, address);
				getline(f, phone);
				getline(f, mail);
				getline(f, Acctype);
				getline(f, balance);
				getline(f, duration);
				getline(f, period);

				if (f.eof())
					break;

				Customer temp1(id, name, date, address, phone, mail, Acctype, stoi(balance), stoi(duration), stoi(period));
				temp.push_back(temp1);
				f.ignore(1, '\n');
			}
			f.close();

			string idTemp = "";
			cout << "===============================\n";
			cout << "-> Enter ID to search: ";
			getline(cin, idTemp);
			cout << "===============================\n";

			for (int i = 0; i < temp.size(); i++)
			{
				if (temp[i].getId() == idTemp)
				{
					cout << "ID          : " << temp[i].getId() << endl;
					cout << "Name        : " << temp[i].getname() << endl;
					cout << "DoB         : " << temp[i].getbirth() << endl;
					cout << "Address     : " << temp[i].getaddress() << endl;
					cout << "Phone Number: " << temp[i].getphone() << endl;
					cout << "Email       : " << temp[i].getmail() << endl;
					cout << "===============================\n";
					goto SHORTCUT;
				}
			}

			cout << "No customer with ID <" << idTemp << ">.\n";
			cout << "===============================\n";
			goto SHORTCUT;
		}
SHORTCUT:
		system("pause");
	}
}

void DirectorMenu::viewEmployee()
{
	while (true)
	{
		int mode = -1;
		system("cls");
		cout << "\n==========VIEW-MENU==========\n";
		cout << "1. View Manager List.\n";
		cout << "2. View Employee List.\n";
		cout << "3. View Customer List.\n";
		cout << "0. Exit.\n";
		cout << "===============================\n";
		cout << "-> Select mode: ";
		cin >> mode;
		cin.ignore(1);

		if (mode == 0)
			return;

		if (mode == 1)
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
				continue;
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

			cout << "===============================\n";
			for (int i = 0; i < temp.size(); i++)
			{
				cout << "#" << i + 1 << endl;
				cout << "ID          : " << temp[i].getId() << endl;
				cout << "Name        : " << temp[i].getname() << endl;
				cout << "DoB         : " << temp[i].getbirth() << endl;
				cout << "Address     : " << temp[i].getaddress() << endl;
				cout << "Phone Number: " << temp[i].getphone() << endl;
				cout << "Email       : " << temp[i].getmail() << endl;
				cout << "Merit       : " << temp[i].getmerit() << endl;
				if (i != temp.size() - 1)
					cout << endl;
			}
			cout << "===============================\n";
			goto SHORTCUT;
		}

		if (mode == 2)
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
				continue;
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

			cout << "===============================\n";
			for (int i = 0; i < temp.size(); i++)
			{
				cout << "#" << i + 1 << endl;
				cout << "ID          : " << temp[i].getId() << endl;
				cout << "Name        : " << temp[i].getname() << endl;
				cout << "DoB         : " << temp[i].getbirth() << endl;
				cout << "Address     : " << temp[i].getaddress() << endl;
				cout << "Phone Number: " << temp[i].getphone() << endl;
				cout << "Email       : " << temp[i].getmail() << endl;
				cout << "Merit       : " << temp[i].getmerit() << endl;
				if (i != temp.size() - 1)
					cout << endl;
			}
			cout << "===============================\n";
			goto SHORTCUT;
		}

		if (mode == 3)
		{
			//local variables
			vector<Customer> temp;
			//read file buffers
			string id;
			string name;
			string date;
			string address;
			string phone;
			string mail;
			string Acctype;
			string balance;
			string duration;
			string period;
			fstream f;

			f.open("Customer.txt", ios::in);

			if (!f.is_open())
				cout << "Cannot open Customer.txt\n";

			while (f.good())
			{
				f >> id;
				f.ignore();
				getline(f, name);
				getline(f, date);
				getline(f, address);
				getline(f, phone);
				getline(f, mail);
				getline(f, Acctype);
				getline(f, balance);
				getline(f, duration);
				getline(f, period);

				if (f.eof())
					break;

				Customer temp1(id, name, date, address, phone, mail, Acctype, stoi(balance), stoi(duration), stoi(period));
				temp.push_back(temp1);
				f.ignore(1, '\n');
			}
			f.close();

			cout << "===============================\n";
			for (int i = 0; i < temp.size(); i++)
			{
				cout << "#" << i + 1 << endl;
				cout << "ID          : " << temp[i].getId() << endl;
				cout << "Name        : " << temp[i].getname() << endl;
				cout << "DoB         : " << temp[i].getbirth() << endl;
				cout << "Address     : " << temp[i].getaddress() << endl;
				cout << "Phone Number: " << temp[i].getphone() << endl;
				cout << "Email       : " << temp[i].getmail() << endl;
				if (i != temp.size() - 1)
					cout << endl;
			}
			cout << "===============================\n";
			goto SHORTCUT;
		}
SHORTCUT:
		system("pause");
	}
}

void DirectorMenu::viewFeedBack()
{
	cout << "Coming soon...\n";
	return;
}

void DirectorMenu::showFireMenu()
{
	while (true)
	{
		int mode;
		system("cls");
		cout << "\n==========FIRE-MENU==========\n";
		cout << "1. Fire Manager.\n";
		cout << "2. Fire Employee.\n";
		cout << "0. Exit.\n";
		cout << "=============================\n";
		cout << "-> Select mode: ";
		cin >> mode;

		if (mode == 1)
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
				continue;
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

			int index = -2;
LOOP:
			system("cls");
			cout << "\n==========MANAGER-LIST==========\n";
			for (int i = 0; i < temp.size(); i++)
			{
				cout << "#" << i + 1 << endl;
				cout << "ID          : " << temp[i].getId() << endl;
				cout << "Name        : " << temp[i].getname() << endl;
				cout << "DoB         : " << temp[i].getbirth() << endl;
				cout << "Address     : " << temp[i].getaddress() << endl;
				cout << "Phone Number: " << temp[i].getphone() << endl;
				cout << "Email       : " << temp[i].getmail() << endl;
				cout << "Merit       : " << temp[i].getmerit() << endl;
				if (i != temp.size() - 1)
					cout << endl;
			}
			cout << "================================\n";
TRY:
			cout << "-> Select manager that you want to fire (Enter -1 To Save Change And Go Back): ";
			cin >> index;
			if (index == -1)
			{
				f.open("Manager.txt", ios::out);

				if (!f.is_open())
				{
					cout << "Save change failed.\n";
					continue;
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
				continue;
			}

			index--;
			if (index < 0 || index > temp.size() - 1)
				goto TRY;

			temp.erase(temp.begin() + index);
			goto LOOP;
		}

		if (mode == 2)
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
				continue;
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

			int index = -2;
LOOP1:
			system("cls");
			cout << "\n==========EMPLOYEE-LIST==========\n";
			for (int i = 0; i < temp.size(); i++)
			{
				cout << "#" << i + 1 << endl;
				cout << "ID          : " << temp[i].getId() << endl;
				cout << "Name        : " << temp[i].getname() << endl;
				cout << "DoB         : " << temp[i].getbirth() << endl;
				cout << "Address     : " << temp[i].getaddress() << endl;
				cout << "Phone Number: " << temp[i].getphone() << endl;
				cout << "Email       : " << temp[i].getmail() << endl;
				cout << "Merit       : " << temp[i].getmerit() << endl;
				if (i != temp.size() - 1)
					cout << endl;
			}
			cout << "=================================\n";
TRY1:
			cout << "-> Select employee that you want to fire (Enter -1 To Save Change And Go Back): ";
			cin >> index;
			if (index == -1)
			{
				f.open("Employee.txt", ios::out);

				if (!f.is_open())
				{
					cout << "Save change failed.\n";
					continue;
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
				continue;
			}

			index--;
			if (index < 0 || index > temp.size() - 1)
				goto TRY1;

			temp.erase(temp.begin() + index);
			goto LOOP1;
		}

		if (mode == 0)
			return;

		cout << "Wrong Mode.\n";
		system("pause");
	}
}
