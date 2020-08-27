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

	string id;
	string	name;
	string	address;
	int	withdraw;
	int	balance;
	int status;

	vector<Request> _requestList;
public:
	void viewlistReDirector();
	void viewcustomer();
};

#endif
