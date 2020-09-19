#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>

using namespace std;

class Request
{
private:
	string _id;
	string _type;
	int _money;
	/*
	Status:
		-1: Denied
		 0: Pending
		 1: Approved
	*/
	int _approvalStatus;
public:
	Request();
	Request(const string& id, const string& type, int money, int status);
//	string viewRequest();
	string getId();
	string getType();
	int getMoney();
	void approveRequest();
	void denyRequest();
	int approvalStatus();
};

class Profile
{
private:
	string _fullname;
	string _ID;
	//Date _DoB;
	int _merit; //Max = 100
public:
	Profile();
};

class Account
{
private:
	string _username;
	string _password;
	string _passwordLv2;
public:
	Account();
	//operator =
	Account& operator=(const Account& a);
	/*Login and check account's role
		1: Director
		2: Manager
		3: Employee
		0: Cannot find role (wrong account)
	*/
	void username(string username)
	{
		_username = username;
	}
	string username()
	{
		return _username;
	}
	void password(string password)
	{
		_password = password;
	}
	string password()
	{
		return _password;
	}
	string passwordLv2()
	{
		return _passwordLv2;
	}

	Account(const string &username,const  string &name)
	{
		this->_username = username;
		this->_password = name;
	}
	Account(const string& username, const string& pass, const string& passlv2)
	{
		this->_username = username;
		this->_password = pass;
		this->_passwordLv2 = passlv2;
	}
	int login(const string& username, const string& password, const string& password2);
	void changePassword(const string& password);
	void changePasswordLv2(const string& password);
	void logout();
};

class Support
{
public:
	void checkValid(int _mode);
	string readNumber(int number);
	void readMoney(int number);
};
#endif