#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "Header.h"

class ManagerMenu
{
private:
	int _option;
	Account _account;
	vector<Request> _requestList;
public:
	ManagerMenu(Account acc);

	void showMenu();

	void viewRequest();

	void editRequest();
};

class Customer
{
private:
	
		string id;
		string	name;
		string	address;
		float	withdraw;
		float	balance;
		
	
	vector<Request> _requestList;
public:
	void viewlistReDirector();
	void viewcustomer();
};

#endif