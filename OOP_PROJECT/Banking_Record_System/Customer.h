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
protected:

	string _id;
	string	_name;
	string	_address;
	int	_withdraw;
	int	_balance;
	int _status;

	vector<Request> _requestList;
public:
	void viewlistReDirector();
	void viewcustomer();
};

#endif
