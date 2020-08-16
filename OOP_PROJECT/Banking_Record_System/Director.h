#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_

#include "Header.h"

class DirectorMenu
{
private:
	Account _account;
	vector<Request> _requestList;
public:
	DirectorMenu(Account acc);
	void viewRequest();
};

#endif