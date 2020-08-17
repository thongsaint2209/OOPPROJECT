#include "AllRole.h"

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

		if (buffer1 == this->_username && buffer2 == this->_password)
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

		if (buffer1 == this->_username && buffer2 == this->_password)
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

void Menu::loginMenu()
{
	string user = "";
	string pass = "";
	string pass2 = "";
	int role = 0;
	int loginTimes = 0;

OPTION:
	if (loginTimes == 10)
	{
		cout << "You have reached maximum login times. Please try again later.\n";
		return;
	}
	cout << "\n==========LOGIN==========\n";
	cout << "-> Username: ";
	getline(cin, user);
	pass.clear();
	cout << "-> Password: ";
	getPassword(pass);
	pass2.clear();
	cout << "-> Password level 2 (enter if don't have): ";
	getPassword(pass2);
	cout << "\n=========================\n";

	role = this->_account.login(user, pass, pass2);

	if (role == 0)
	{
		cout << "Wrong account. Please try again.\n";
		loginTimes++;
		goto OPTION;
	}

	cout << "Login successfully.\n";
	return;
}
<<<<<<< Updated upstream
=======

string Menu::getPassword(string& password)
{
	char temp = 0;
	cout << endl;
	while (true)
	{
		temp = _getch();
		if (temp == 13)
			break;
		if ((int)temp == 8) {
			password = password.substr(0, password.length() - 1);
		}
		else {
			password = password + temp;
		}
		cout << '\r';
		for (int i = 0; i <= password.length(); i++)
			cout << ' ';
		cout << '\r';
		for (int i = 0; i < password.length(); i++)
			cout << '*';
	}
	cout << endl;
	return password;
}

Request::Request()
{
	this->_detail = "";
	this->_approvalStatus = false;
}

Request::Request(const string& detail, bool status)
{
	this->_detail = detail;
	this->_approvalStatus = status;
}

string Request::viewRequest()
{
	return this->_detail;
}

void Request::approveRequest()
{
	this->_approvalStatus = true;
}

void Request::denyRequest()
{
	this->_approvalStatus = false;
}

bool Request::approvalStatus()
{
	return this->_approvalStatus;
}
>>>>>>> Stashed changes
