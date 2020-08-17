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

<<<<<<< HEAD
		if (buffer1 == this->_username && buffer2 == this->_password)
=======
		if (buffer1 == this->_username && buffer2 == this->_password && this->_passwordLv2 == "")
>>>>>>> Minh
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

<<<<<<< HEAD
		if (buffer1 == this->_username && buffer2 == this->_password)
=======
		if (buffer1 == this->_username && buffer2 == this->_password && this->_passwordLv2 == "")
>>>>>>> Minh
		{
			f.close();
			return 3;
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
