#include"Customer.h"

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
	string	address;
	int	balance;
	f3.open("Customer.txt", ios::in);


	if (!f3.is_open())
		cout << "Cannot open Customer.txt\n";

	
	int count1 = 0;
	while (f3.good())
	{
		f3 >> id;
		getline(f3, name);
		getline(f3, name);
		getline(f3, address);
		f3 >> balance;

		if (f3.eof())
			break;
		Customer temp(id, name, address, balance);
		this->a.push_back(temp);
		f3.ignore(1, '\n');
		count1++;
		
	}
	cout << "Enter your id : ";
	getline(cin, id);

	cout << "Enter your name : ";
	getline(cin, name);

	cout << "Enter your address : ";
	getline(cin, address);

	cout << "Enter your balance : ";
	cin>> balance;
	cin.ignore();



	Customer temp2(id, name, address, balance);
	this->a.push_back(temp2);

	count1++;
	fstream f4;
	f4.open("Customer.txt", ios::out);
	if (!f4.is_open())
		cout << "Cannot open Customer.txt\n";

	for (int i = 0; i < count1; i++)
	{

		f4<< a[i]._id<<endl;

		f4 << a[i]._name<<endl;

		f4 << a[i]._address<<endl;
		f4 << a[i]._balance << endl;
		f4 << endl;

	}
	f4.close();
}

void Customer::Editprofile()
{
	ifstream f1;

	string id;
	string	name;
	string	address;
	int	balance;
	f1.open("Customer.txt", ios::in);


	if (!f1.is_open())
		cout << "Cannot open Customer.txt\n";


	int count = 0;
	while (f1.good())
	{
		f1 >> id;
		getline(f1, name);
		getline(f1, name);
		getline(f1, address);
		f1>> balance;

		if (f1.eof())
			break;
		Customer temp(id, name, address, balance);
		this->a.push_back(temp);
		f1.ignore(1, '\n');
		count++;

	}
	cout << "Choose id you want to Edit  ";
	while (getchar() != '\n');
	getline(cin, id);

	int flag = 0;

	int option;
	cout << "Do you want to edit this customer?  " << endl;
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
		
		for (int i = 0; i < count; i++)
		{
			if (a[i].getId()==id)
			{
				//tao vector temp 

				

				cout << "Enter your name : ";
				getline(cin, name);

				cout << "Enter your address : ";
				getline(cin, address);

				cout << "Enter your balance : ";
				cin >> balance;
				cin.ignore();



				Customer temp2(id, name, address, balance);

				a[i]._id = temp2._id;
				a[i]._name = temp2._name;
				a[i]._address = temp2._address;
				a[i]._balance = temp2._balance;
			   

				fstream f3;
				f3.open("Customer.txt", ios::out);
				if (!f3.is_open())
					cout << "Cannot open Customer.txt\n";

				for (int i = 0; i < count; i++)
				{
					
						f3 << a[i]._id<<endl;

						f3 << a[i]._name<<endl;

						f3 << a[i]._address<<endl;
						f3 << a[i]._balance << endl;
						f3 << endl;

				}
				f3.close();
			}
		}
	}
	default:
	{
		cout << "Please choose number from 0-2" << endl;
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
	string	address;
	int	balance;
	f2.open("Customer.txt", ios::in);


	if (!f2.is_open())
		cout << "Cannot open Customer.txt\n";


	int count1 = 0;
	while (f2.good())
	{
		f2 >> id;
		getline(f2, name);
		getline(f2, name);
		getline(f2, address);
		f2 >> balance;

		if (f2.eof())
			break;
		Customer temp(id, name, address, balance);
		this->a.push_back(temp);
		f2.ignore(1, '\n');
		count1++;

	}
	f2.close();
	cout << "Choose id you want to delete  ";
	while (getchar() != '\n');
	getline(cin, username);

	int flag = 0;

	int option;
	cout << "Do you want to delete this customer?  " << endl;
	cout << "0: Out" << endl;
	cout << "1: Delete" << endl;
	cin >> option;
	switch (option)
	{
	case 0:
	{
		return;
	}
	case 1:
	{

		for (int i = 0; i < count; i++)
		{
			if (account[i].username() == username)
			{
				//tao vector temp 
				


				this->account.erase(account.begin() + i);
				

				fstream f3;
				f3.open("CustomerAccounts.txt", ios::out);
				if (!f3.is_open())
					cout << "Cannot open CustomerAccounts.txt\n";
				
				for (int i = 0; i < this->account.size(); i++)
				{

					f3 << account[i].username();

					f3 << account[i].password();

					


				}
				f3.close();

				
				
			}
			for (int i = 0; i < count1; i++)
			{
				if (a[i]._id==username)
				{
					this->a.erase(a.begin() + i);
					count1--;
					fstream f4;
					f4.open("Customer.txt", ios::out);
					if (!f4.is_open())
						cout << "Cannot open Customer.txt\n";

					for (int i = 0; i < count1; i++)
					{

						f4 << a[i]._id;

						f4 << a[i]._name;

						f4 << a[i]._address;
						f4 << a[i]._balance << endl;


					}
					f4.close();
				}
			}
		}
	}
	default:
	{
		cout << "Please choose number from 0-2" << endl;
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
			
			break;
		case 2:
			
			break;
		case 3:
			
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