#include "AllRole.h"

void Menu::redirect()
{
	if (this->_role == 1)
	{
		DirectorMenu m(this->_account);

		m.viewRequest();
	}
	//continue...
}

void Menu::loginMenu()
{
	string user = "";
	string pass = "";
	string pass2 = "";
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
	cout << "-> Password: ";
	getline(cin, pass);
	cout << "-> Password level 2 (enter if don't have): ";
	getline(cin, pass2);
	cout << "\n=========================\n";

	this->_role = this->_account.login(user, pass, pass2);

	if (this->_role == 0)
	{
		cout << "Wrong account. Please try again.\n";
		loginTimes++;
		goto OPTION;
	}

	cout << "Login successfully.\n";
	return;
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
