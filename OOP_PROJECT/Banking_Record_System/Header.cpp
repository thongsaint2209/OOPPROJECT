#include "Header.h";

Account::Account()
{
	this->_username = "";
	this->_password = "";
	this->_passwordLv2 = "";
}

Account& Account::operator=(const Account& a)
{
	this->_username = a._username;
	this->_password = a._password;
	this->_passwordLv2 = a._passwordLv2;

	return *this;
}

int Account::login(const string& username, const string& password, const string& password2)
{
	this->_username = username;
	this->_password = password;
	this->_passwordLv2 = password2;

	fstream f;
	string buffer1 = "";
	string buffer2 = "";
	string buffer3 = "";

	//check director
	f.open("DirectorAccounts.txt", ios::in);

	if (!f.is_open())
		cout << "Cannot open DirectorAccounts.txt\n";

	while (!f.eof())
	{
		getline(f, buffer1, '\n');
		getline(f, buffer2, '\n');
		getline(f, buffer3, '\n');
		f.ignore(1, '\n');

		if (buffer1 == this->_username && buffer2 == this->_password && buffer3 == this->_passwordLv2)
		{
			f.close();
			return 1;
		}
	}

	f.close();

	//check manager
	f.open("ManagerAccounts.txt", ios::in);

	if (!f.is_open())
		cout << "Cannot open ManagerAccounts.txt\n";

	while (!f.eof())
	{
		getline(f, buffer1, '\n');
		getline(f, buffer2, '\n');
		f.ignore(1, '\n');

		if (buffer1 == this->_username && buffer2 == this->_password && this->_passwordLv2 == "")
		{
			f.close();
			return 2;
		}
	}

	f.close();

	//check employee
	f.open("EmployeeAccounts.txt", ios::in);

	if (!f.is_open())
		cout << "Cannot open EmployeeAccounts.txt\n";

	while (!f.eof())
	{
		getline(f, buffer1, '\n');
		getline(f, buffer2, '\n');
		f.ignore(1, '\n');

		if (buffer1 == this->_username && buffer2 == this->_password && this->_passwordLv2 == "")
		{
			f.close();
			return 3;
		}
	}
	f.close();

	//check Customer
	f.open("CustomerAccounts.txt", ios::in);

	if (!f.is_open())
		cout << "Cannot open CustomerAccounts.txt\n";

	while (!f.eof())
	{
		getline(f, buffer1, '\n');
		getline(f, buffer2, '\n');
		f.ignore(1, '\n');

		if (buffer1 == this->_username && buffer2 == this->_password && this->_passwordLv2 == "")
		{
			f.close();
			return 4;
		}
	}
	f.close();

	return 0; //cannot find account's role
}

void Account::changePassword(const string& password)
{
	this->_password = password;
}

void Account::changePasswordLv2(const string& password)
{
	this->_passwordLv2 = password;
}

void Account::logout()
{
	this->_username = "";
	this->_password = "";
	this->_passwordLv2 = "";
}

Request::Request()
{
	this->_id = "";
	this->_type = "";
	this->_money = 0;
	this->_approvalStatus = 0;
}

Request::Request(const string& id, const string& type, int money, int status)
{
	this->_id = id;
	this->_type = type;
	this->_money = money;
	this->_approvalStatus = status;
}

//string Request::viewRequest()
//{
//	return this->_detail;
//}
string Request::getId()
{
	return this->_id;
}

string Request::getType()
{
	return this->_type;
}

int Request::getMoney()
{
	return this->_money;
}

void Request::approveRequest()
{
	this->_approvalStatus = 1;
}

void Request::denyRequest()
{
	this->_approvalStatus = -1;
}

int Request::approvalStatus()
{
	return this->_approvalStatus;
}

Profile::Profile()
{
	this->_fullname = "";
	this->_ID = "";
	this->_merit = 0;
}

void Support::checkValid(int _mode) {
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please only enter number!" << endl;
			cout << "Enter again: ";
			cin >> _mode;
		}
		if (!cin.fail())
			break;
	}
}

vector<string> ones{ "","one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
vector<string> teens{ "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen" };
vector<string> tens{ "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

string Support::readNumber(int number) {
	if (number < 10) 
		return ones[number];
	else if (number < 20) 
		return teens[number - 10];
	else if (number < 100) 
		return tens[number / 10] + ((number % 10 != 0) ? " " + readNumber(number % 10) : "");
	else if (number < 1000) 
		return readNumber(number / 100) + " hundred" + ((number % 100 != 0) ? " " + readNumber(number % 100) : "");
	else if (number < 1000000) 
		return readNumber(number / 1000) + " thousand" + ((number % 1000 != 0) ? " " + readNumber(number % 1000) : "");
	else if (number < 1000000000)
		return readNumber(number / 1000000) + " million" + ((number % 1000000 != 0) ? " " + readNumber(number % 1000000) : "");
	else if (number < 1000000000000) 
		return readNumber(number / 1000000000) + " billion" + ((number % 1000000000 != 0) ? " " + readNumber(number % 1000000000) : "");
	return "error";
}

void Support::readMoney(int number)
{
	string s = readNumber(number);
	s += " VND";
	cout << s;
}