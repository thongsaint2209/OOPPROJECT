#include "Customer.h"
#include"Header.h"
#include"Lib/Date.h"
#include"Lib/Time.h"
#include"AllRole.h"

vector <Customer> Customer::a;

float Customer::_TermRate = 0.07;
float Customer::_DemandRate = 0.01;

void Customer::newAccount()
{
	string username;
	string password;

	a.clear();
	account.clear();
	fstream f1;

	f1.open("CustomerAccounts.txt", ios::in);

	if (!f1.is_open())
		cout << "Cannot open CustomerAccounts.txt\n";



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
	cin.ignore();

	do {
		cout << "Enter your id : ";
		getline(cin, username);
		int k;
		for (k = 0; k < account.size(); k++)
		{
			if (username == account[k].username())
			{
				break;
			}
		}
		if (k == account.size())
			break;
	} while (true);

	cout << "Enter your password : ";
	getline(cin, password);

	Account temp1(username, password);

	account.push_back(temp1);
	count++;
	ofstream f2;
	f2.open("CustomerAccounts.txt", ios::out);
	if (!f2.is_open())
		cout << "Cannot open Customer.txt\n";

	for (int i = 0; i < count; i++)
	{

		f2 << account[i].username() << endl;

		f2 << account[i].password() << endl;

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
		a.push_back(temp);
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
	a.push_back(temp2);

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
	a.clear();
	account.clear();
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
	a.clear();
	account.clear();
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
	for (int h = 0; h < a.size(); h++)
	{
		if (a[h]._id == _account.username())
		{

			cout << "id :" << a[h]._id << endl;
			cout << "name :" << a[h]._name << endl;
			cout << "birthday :" << a[h]._birth << endl;
			cout << "address :" << a[h]._address << endl;
			cout << "phone :" << a[h]._phone << endl;
			cout << "mail:" << a[h]._mail << endl;
			cout << "Acc type :" << a[h]._acctype << endl;
			cout << "balance :" << a[h]._balance << endl;
			cout << "duration :" << a[h]._duration << endl;
			cout << "period :" << a[h]._period << endl;
			cout << endl;
		}
	}
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
			if (a[i]._id == _account.username())
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



				Customer temp2(_account.username(), name, date, address, phone, mail, Acctype, a[i]._balance, a[i]._duration, a[i]._period);



				a[i]._name = temp2._name;
				a[i]._birth = temp2._birth;
				a[i]._address = temp2._address;
				a[i]._phone = temp2._phone;
				a[i]._mail = temp2._mail;
				a[i]._acctype = temp2._acctype;




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
	a.clear();
}

void Customer::deleteAccount()
{
	string username;
	string password;
	a.clear();
	account.clear();
	fstream f1;

	f1.open("CustomerAccounts.txt", ios::in);

	if (!f1.is_open())
		cout << "Cannot open CustomerAccounts.txt\n";

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
		f2 >> duration;
		f2 >> period;

		if (f2.eof())
			break;
		Customer temp(id, name, date, address, phone, mail, Acctype, balance, duration, period);
		this->a.push_back(temp);
		f2.ignore(1, '\n');
		count1++;

	}
	f2.close();




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
			if (account[i].username() == _account.username())
			{

				this->account.erase(account.begin() + i);

				fstream f3;
				f3.open("CustomerAccounts.txt", ios::out);
				if (!f3.is_open())
					cout << "Cannot open CustomerAccounts.txt\n";

				for (int m = 0; m < this->account.size(); m++)
				{

					f3 << account[m].username() << endl;

					f3 << account[m].password() << endl;

					f3 << endl;


				}
				f3.close();

			}

		}

		for (int j = 0; j < this->a.size(); j++)
		{
			if (a[j]._id == _account.username())
			{
				this->a.erase(a.begin() + j);

				fstream f4;
				f4.open("Customer.txt", ios::out);
				if (!f4.is_open())
					cout << "Cannot open Customer.txt\n";

				for (int k = 0; k < this->a.size(); k++)
				{
					f4 << a[k]._id << endl;
					f4 << a[k]._name << endl;
					f4 << a[k]._birth << endl;
					f4 << a[k]._address << endl;
					f4 << a[k]._phone << endl;
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
	a.clear();
	account.clear();
	exit(1);
}


void Customer::showMenu()
{
	while (true)
	{
		system("cls");
		cout << "\n==========CUSTOMER-MENU==========\n";
		cout << "1. View profile information.\n";
		cout << "2. Change password.\n";
		cout << "3. Customer's authority.\n";
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
				cout << "\n==========CUSTOMER'S-AUTHORITY-MENU==========\n";
				
				cout << "1. Edit information customer.\n";
				cout << "2. Delete account\n";
				cout << "3. View Trade History\n";
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
					this->Editprofile();
					break;
				case 2:
					this->deleteAccount();
					break;
				case 3:
					//this->viewTradeHistory();
					break;
				case 5:
					break;
				case 6:
					break;
				case 7:

					break;
				default:
				{
					cout << "Please only enter number from 0 to 4!\n";
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

//Time - deposit account(1), Demand Edeposit account(2), payment acc(3)
int Customer::gettype() {
	if (_acctype == "Time deposit account") return 1;
	if (_acctype == "Demand deposit account") return 2;
	if (_acctype == "Payment account") return 3;
	return 0;
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


void Customer::withdraw(int money, string id1) {
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


	for (int i = 0; i < a.size(); i++)
	{
		if (a[i]._id == id1)
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
				}
				else if (a[i].gettype() == 1 || a[i].gettype() == 2) {
					fstream f4;
					f4.open("EmployeeRequestsList.txt", ios::out);
					if (!f4.is_open())
						cout << "Cannot open EmployeeRequestsList.txt\n";
					else {
						f4 << endl << a[i].getId() << endl << "Withdraw" << endl << money << endl << 0;
					}
				}

			}


			else {
				fstream f5;
				f5.open("ManagerRequestList.txt", ios::out);
				if (!f5.is_open())
					cout << "Cannot open ManagerRequestsList.txt\n";
				else {
					f5 << endl << endl << "Withdraw" << endl << a[i].getId() << endl << money << endl << 0;
				}
			}
			break;
		}
	}
}

void Customer::viewProfile()
{
	string id;
	string name;
	string DoB;
	string address;
	string phone;
	string email;
	string merit;
	string _acctype;
	string _balance;
	string _duration;
	string _period;
	vector<Customer> temp;

	fstream f;

	f.open("Customer.txt", ios::in);

	if (!f.is_open())
	{
		cout << "Cannot find Customer.txt.\n";
	}

	while (!f.eof())
	{
		getline(f, id, '\n');
		getline(f, name, '\n');
		getline(f, DoB, '\n');
		getline(f, address, '\n');
		getline(f, phone, '\n');
		getline(f, email, '\n');
		getline(f, _acctype, '\n');
		getline(f, _balance, '\n');
		getline(f, _duration, '\n');
		getline(f, _period, '\n');
		f.ignore(1, '\n');

		Customer buffer(id, name, DoB, address, phone, email, _acctype, stoi(_balance), stoi(_duration), stoi(_period));
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
			cout << "Account type: " << temp[i].getacctype() << endl;
			cout << "Balance " << temp[i].getBalance() << endl;
			cout << "Duration  " << temp[i].getDuration() << endl;
			cout << "Period " << temp[i].getPeriod() << endl;
		}
	}
}


void Customer::deposit(int money, string id2) {
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



	for (int i = 0; i < a.size(); i++)
	{

		if (a[i]._id == id2)
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
						//	Date d;
							//f4 << d.toString() << endl << a[i].getname() << endl << "Deposit" << endl << money << endl;

					}
					f4.close();

				}
				else if (a[i].gettype() == 1 || a[i].gettype() == 2) {
					fstream f5;
					f5.open("EmployeeRequestsList.txt", ios::out);
					if (!f5.is_open())
						cout << "Cannot open EmployeeRequestsList.txt\n";
					else {
						f5 << endl << endl << "Deposit" << endl << a[i].getId() << endl << money << endl << 0;
					}
					f5.close();

				}


			}
			else {
				fstream f6;
				f6.open("ManagerRequestList.txt", ios::out);
				if (!f6.is_open())
					cout << "Cannot open ManagerRequestsList.txt\n";
				else {
					f6 << endl << endl << "Deposit" << endl << a[i].getId() << endl << money << endl << 0;
				}
			}
			break;
		}

	}

}

/*void Customer::saveTradeHistory(string id, string type, int money)
{
	string _time;
	string _id;
	string _type;
	string _money;
	vector<TradeHistory> temp;
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
		

		TradeHistory buffer(_time, _id, _type, stof(_money));
		temp.push_back(buffer);
		f.ignore(1, '\n');
		
	}
	f.close();

	Time t;
	Date d;
	stringstream s;
	s << t.toString() << " " << d.toString();

	TradeHistory a(s.str(), id, type, money);
	temp.push_back(a);

	f.open("TransactDate.txt", ios::out);


	for (int i = 0; i < temp.size(); i++)
	{
		f << temp[i].getTime() << endl;
		f << temp[i].getId() << endl;
		f << temp[i].getType() << endl;
		f << temp[i].getMoney() << endl;
		if (i != temp.size() - 1)
			f << endl;
	}
	cout << "Saved successfully.\n";
	f.close();
}

void Customer::viewTradeHistory()
{
	string _time;
	string _id;
	string _type;
	string _money;
	vector<TradeHistory> temp;
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
		temp.push_back(buffer);

		if (f.eof())
			break;
	}
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].getId() == this->_account.username())
		{
			cout << "===YOUR-TRADE-HISTORY===" << endl;
			cout << temp[i].getTime() << endl;
			cout << temp[i].getId() << endl;
			cout << temp[i].getType() << endl;
			cout << temp[i].getMoney() << endl;
		}
	}
	f.close();
}
*/
void Customer::changePassword()
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
		f.open("CustomerAccounts.txt", ios::in);
		if (!f.is_open())
			cout << "Cannot open CustomerAccounts.txt\n";
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
		f.open("CustomerAccounts.txt", ios::out);
		if (!f.is_open())
			cout << "Cannot open CustomerAccounts.txt\n";
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