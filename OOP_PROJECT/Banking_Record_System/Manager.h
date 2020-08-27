#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "Header.h"
#include "Customer.h"
class ManagerMenu :public Customer
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

	void viewlistReDirector();

	void viewcustomer();
};



#endif