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
	int login(const string& username, const string& password, const string& password2);
	void changePassword(const string& password);
	void changePasswordLv2(const string& password);
	void logout();
};


#endif