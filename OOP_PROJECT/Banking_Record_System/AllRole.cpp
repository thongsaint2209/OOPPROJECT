#include "AllRole.h"

void Menu::redirect()
{
	/*if (this->_role == 1)
	{
		DirectorMenu m(this->_account);

		m.showMenu();
	}*/
	if (this->_role == 2)
	{
		ManagerMenu m(this->_account);
		 m.showMenu();
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
	cout << "-> Username: \n";
	getline(cin, user);
	pass.clear();
	cout << "-> Password: ";
	getPassword(pass);
	pass2.clear();
	cout << "-> Password level 2 (enter if don't have): ";
	getPassword(pass2);
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
