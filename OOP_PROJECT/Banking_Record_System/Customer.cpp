#include"Customer.h"
#include"Header.h"

float Customer::_TermRate=0.07;
float Customer::_DemandRate=0.01;
void Customer::newAccount()
{
	fstream f1;

	f1.open("CustomerAccounts.txt", ios::in);

	if (!f1.is_open())
		cout << "Cannot open CustomerAccounts.txt\n";
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
	cout << "Enter your id : ";
	getline(cin, username);

	cout << "Enter your password : ";
	getline(cin, password);

	Account temp1(username, password);

	this->account.push_back(temp1);
	count++;
	ofstream f2;
	f2.open("CustomerAccounts.txt", ios::out);
	if (!f2.is_open())
		cout << "Cannot open Customer.txt\n";

	for (int i = 0; i < this->account.size(); i++)
	{

		f2 << account[i].username()<<endl;

		f2 << account[i].password()<<endl;

		f2 << endl;

	}
	f2.close();
	

	ifstream f3;


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
	f3.open("Customer.txt", ios::in);


	if (!f3.is_open())
		cout << "Cannot open Customer.txt\n";

	
	int count1 = 0;
	while (f3.good())
	{
		f3 >> id;
		f3.ignore();
		getline(f3, name);

		getline(f3, date);


		getline(f3, address);

		getline(f3, phone);

		getline(f3, mail);

		getline(f3, Acctype);

		f3 >> balance;
		f3 >> duration;
		f3 >> period;

		if (f3.eof())
			break;
		Customer temp(id, name, date, address, phone, mail, Acctype, balance, duration, period);
		this->a.push_back(temp);
		f3.ignore(1, '\n');
		count1++;
		
	}
	
	cout << "Enter your name : ";
	getline(cin, name);

	cout << "Enter your date : ";
	getline(cin, date);

	cout << "Enter your address : ";
	getline(cin, address);

	cout << "Enter your phone : ";
	getline(cin, phone);

	cout << "Enter your  mail : ";
	getline(cin, mail);

	cout << "Enter Acc-Type : ";
	getline(cin, Acctype);

	

	
	
	


	Customer temp2(username, name, date, address, phone, mail, Acctype);
	this->a.push_back(temp2);

	count1++;
	fstream f4;
	f4.open("Customer.txt", ios::out);
	if (!f4.is_open())
		cout << "Cannot open Customer.txt\n";

	for (int i = 0; i < count1; i++)
	{


		f4 << a[i]._id << endl;
		f4 << a[i]._name << endl;
		f4 << a[i]._birth << endl;
		f4 << a[i]._address << endl;
		f4 << a[i]._phone << endl;
		f4 << a[i]._mail << endl;
		f4 << a[i]._acctype << endl;
		f4 << a[i]._balance << endl;
		f4 << a[i]._duration << endl;
		f4 << a[i]._period << endl;

		f4 << endl;
		

	}
	f4.close();
	cout << "Add new acc successfully " << endl;
}

void Customer::Editprofile()
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
	cout << "Choose id you want to Edit  ";
	
	getline(cin, id);
	
	int flag = 0;

	int option;
	cout << "Do you want to edit this customer?  " << endl;
	cout << "0: Out" << endl;
	cout << "1: Edit" << endl;
	cin >> option;
	while (getchar() != '\n');
	switch (option)
	{
	case 0:
	{
		return;
	}
	case 1:
	{
		
	for (int i = 0; i < a.size(); i++)
		{
			if (a[i].getId()==id)
			{
				
				cout << "Enter your name : ";
				getline(cin, name);

				cout << "Enter your date : ";
				getline(cin, date);

				cout << "Enter your address : ";
				getline(cin, address);

				cout << "Enter your phone : ";
				getline(cin, phone);

				cout << "Enter your mail : ";
				getline(cin, mail);

				Customer temp2(id, name, date, address, phone, mail, Acctype, balance, duration, period);
				

				a[i]._id = temp2._id;
				a[i]._name = temp2._name;
				a[i]._birth = temp2._birth;
				a[i]._address = temp2._address;
				a[i]._phone = temp2._phone;
				a[i]._mail = temp2._mail;
				a[i]._acctype = temp2._acctype;
				

				a[i]._balance = temp2._balance;
				a[i]._duration = temp2._duration;
				a[i]._period = temp2._period;

				fstream f3;
				f3.open("Customer.txt", ios::out);
				if (!f3.is_open())
					cout << "Cannot open Customer.txt\n";

				for (int i = 0; i < count; i++)
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
			}
		}

		cout << "Edit Successfully" << endl;
	}
	default:
	{
		cout << "HUHU" << endl;
		break;
	}
	}
}

void Customer::deleteAccount()
{
	fstream f1;

	f1.open("CustomerAccounts.txt", ios::in);

	if (!f1.is_open())
		cout << "Cannot open CustomerAccounts.txt\n";
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



	ifstream f2;
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
	f2.open("Customer.txt", ios::in);
	if (!f2.is_open())
		cout << "Cannot open Customer.txt\n";


	int count1 = 0;
	while (f2.good())
	{
		f2 >> id;
		f2.ignore();
		getline(f2, name);

		getline(f2, date);


		getline(f2, address);

		getline(f2, phone);

		getline(f2, mail);

		getline(f2, Acctype);

		f2 >> balance;
		f2>> duration;
		f2 >> period;

		if (f2.eof())
			break;
		Customer temp(id, name, date, address, phone, mail, Acctype, balance, duration, period);
		this->a.push_back(temp);
		f2.ignore(1, '\n');
		count1++;

	}
	f2.close();
	cout << "Enter id you want to Delete :";
	
	getline(cin, id);
	
	

	int option;
	cout << "Do you want to delete this customer?  " << endl;
	cout << "0: Out" << endl;
	cout << "1: Delete" << endl;
	cin >> option;
	while (getchar() != '\n');
	switch (option)
	{
	case 0:
	{
		return;
	}
	case 1:
	{

		for (int i = 0; i < this->account.size(); i++)
		{
			if (account[i].username() == id)
			{

				this->account.erase(account.begin() + i);
	
				fstream f3;
				f3.open("CustomerAccounts.txt", ios::out);
				if (!f3.is_open())
					cout << "Cannot open CustomerAccounts.txt\n";
				
				for (int m = 0; m < this->account.size(); m++)
				{

					f3 << account[m].username()<<endl;

					f3 << account[m].password() << endl;

					f3 << endl;


				}
				f3.close();

			}
			
		}
		
		for (int j = 0; j < this->a.size(); j++)
		{
			if (a[j]._id == id)
			{
				this->a.erase(a.begin() + j);

				fstream f4;
				f4.open("Customer.txt", ios::out);
				if (!f4.is_open())
					cout << "Cannot open Customer.txt\n";

				for (int k = 0; k < this->a.size(); k++)
				{
					f4<< a[k]._id << endl;
					f4 << a[k]._name << endl;
					f4 << a[k]._birth << endl;
					f4 << a[k]._address << endl;
					f4<< a[k]._phone << endl;
					f4 << a[k]._mail << endl;
					f4 << a[k]._acctype << endl;
					f4 << a[k]._balance << endl;
					f4 << a[k]._duration << endl;
					f4 << a[k]._period << endl;
					f4 << endl;

				}
				f4.close();
			}
		}
		cout << "Delete Successfully ";
	}
	default:
	{
		
		break;
	}
	}
}

void Customer::showMenu()
{

	while (true)
	{
		system("cls");
		cout << "\n==========MANAGER-MENU==========\n";
		cout << "1.Create New Account.\n";

		cout << "2. Edit information customer.\n";

		cout << "3. Delete account\n";
		

		
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
			this->newAccount();
			break;
		case 2:
			this->Editprofile();
			break;
		case 3:
			this->deleteAccount();
			break;
		case 4:
			
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			
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


float Customer::ClacInrest() {

	if (gettype() == 1) {
		float TimeInterest = getBalance() * (_duration / _period) * _period * _TermRate / 12;
		float DemandInterest = getBalance() * (_duration % _period) * _DemandRate / 12;
		return TimeInterest + DemandInterest;
	}
	if (gettype() == 2 || gettype() == 3) {
		return  getBalance() * _DemandRate;
	}
}

void Customer::deposit(int money) {
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
	f1.close();
	cout << "Choose id you want to deposit  ";

	getline(cin, id);

	
		for (int i = 0; i < a.size(); i++)
		{

			if (a[i].getId() == id)
			{
				if (money < 10000000) {
				if (a[i].gettype() == 3) {
					a[i]._balance += a[i].ClacInrest() + money;
					a[i]._duration = 0;


					fstream f3;
					f3.open("Customer.txt", ios::out);
					if (!f3.is_open())
						cout << "Cannot open Customer.txt\n";

					for (int i = 0; i < count; i++)
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

					cout << "Deposit Successfully" << endl;
					fstream f4;
					f4.open("TransactDate.txt", ios::out);
					if (!f4.is_open())
						cout << "Cannot open TransactDate.txt\n";
					else {
						Date d;
						f4 << d.toString() << endl << a[i].getname() << endl << "Deposit" << endl << money << endl;

					}
					f4.close();

				}
				else if (a[i].gettype() == 1 || a[i].gettype() == 2) {
					fstream f3;
					f3.open("EmployeeRequestsList.txt", ios::out);
					if (!f3.is_open())
						cout << "Cannot open EmployeeRequestsList.txt\n";
					else {
						f3 << endl << endl << "Deposit" << endl << a[i].getId() << endl << money << endl << 0;
					}
					f3.close();

				}
				
				
			}
				else {
					fstream f3;
					f3.open("ManagerRequestsList.txt", ios::out);
					if (!f3.is_open())
						cout << "Cannot open ManagerRequestsList.txt\n";
					else {
						f3 << endl << endl << "Deposit" << endl << a[i].getId() << endl << money << endl << 0;
					}
				}

				break;
		}

		
		
	}
	
}

void Customer::withdraw(int money) {
	 
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
		f1.close();
		cout << "Choose id you want to withdraw  ";

		getline(cin, id);

		
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i].getId() == id)
			{
				if (money < 10000000) {
					if (a[i].gettype() == 3) {
						a[i]._balance += a[i].ClacInrest();
						if (a[i]._balance > money) {
							a[i]._balance -= money;
							a[i]._duration = 0;
						}


						fstream f3;
						f3.open("Customer.txt", ios::out);
						if (!f3.is_open())
							cout << "Cannot open Customer.txt\n";

						for (int i = 0; i < count; i++)
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

						cout << "Withdraw Successfully" << endl;
						fstream f4;
						f4.open("TransactDate.txt", ios::out);
						if (!f4.is_open())
							cout << "Cannot open TransactDate.txt\n";
						else {
							Date d;
							f4 << d.toString() << endl << a[i].getname() << endl << "Deposit" << endl << money << endl;

						}
						f4.close();
					}
					else if (a[i].gettype() == 1 || a[i].gettype() == 2) {
						fstream f3;
						f3.open("EmployeeRequestsList.txt", ios::out);
						if (!f3.is_open())
							cout << "Cannot open EmployeeRequestsList.txt\n";
						else {
							f3 << endl << endl << "Withdraw" << endl << a[i].getId() << endl << money << endl << 0;
						}
						f3.close();
					}

				}

				else {
					fstream f3;
					f3.open("ManagerRequestsList.txt", ios::out);
					if (!f3.is_open())
						cout << "Cannot open ManagerRequestsList.txt\n";
					else {
						f3 << endl << endl << "Withdraw" << endl << a[i].getId() << endl << money << endl << 0;
					}
				}

				break;
			}
		}
	
}



//Time - deposit account(1), Demand – deposit account(2), payment acc(3)
int Customer::gettype() {
	if (_acctype == "Time - deposit account") return 1;
	if (_acctype == "Demand – deposit account") return 2;
	if (_acctype == "Payment account") return 3;
	return 0;
}