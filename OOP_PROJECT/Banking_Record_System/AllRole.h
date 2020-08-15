#ifndef _ALLROLE_H_
#define _ALLROLE_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Account
{
private:
	string _username;
	string _password;
	string _passwordLv2;
public:
	/*Login and check account's role
		1: Director
		2: Manager
		3: Employee
		0: Cannot find role (wrong account)
	*/
	int login(const string& username, const string& password, const string& password2);
	void changePassword(const string& password);
	void changePasswordLv2(const string& password);
};

class Menu
{
private:
	int _role;
	Account _account;
public:
	void loginMenu();
};

#endif