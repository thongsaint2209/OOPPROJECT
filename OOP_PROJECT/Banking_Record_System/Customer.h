#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>

using namespace std;

class Customer
{
private:

	string _id;
	string	_name;
	string	_address;
	int	_balance;
	
	int _option;
	Account _account;

	vector<Request> _requestList;
	vector<Account> account;
	vector<Customer> a;
public:
	void setId(string id)
	{
		_id = id;
	}
	void setname(string name)
	{
		_name = name;
	}
	void setaddress(string address)
	{
		_address = address;
	}
	string getId()
	{
		return _id;
	}
	string getname()
	{
		return _name;
	}
	string getaddress()
	{
		return _address;
	}
	int getBalance()
	{
		return _balance;
	}
	Customer(string id, string name, string address, int balance)
	{
		this->_id = id;
		this->_name = name;
		this->_address = address;
		this->_balance = balance;
	}
	void newAccount(Account acc);

	void showMenu();

	void Editprofile();

	void deleteAccount();
};

#endif

