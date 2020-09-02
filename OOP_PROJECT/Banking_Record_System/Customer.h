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
public:

	string _id;
	string	_name;
	string	_address;
	int	_balance;

	vector<Request> _requestList;
public:
	Customer(string id, string name, string address, int balance)
	{
		this->_id = id;
		this->_name = name;
		this->_address = address;
		this->_balance = balance;
	}
	void viewlistReDirector();
	void viewcustomer();
};

#endif
