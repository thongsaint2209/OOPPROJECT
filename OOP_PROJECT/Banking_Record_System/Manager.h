#ifndef _MANAGER_H_
#define _MANAGER_H_

#include "Header.h"

class ManagerMenu
{
private:
	int _mode;
	Account _account;
	vector<Request> _requestList;
public:
	ManagerMenu(Account acc);
	void showMenu();
	void viewRequest();
	void editRequest();
};

#endif