#ifndef _ALLROLE_H_
#define _ALLROLE_H_

#include "Header.h"
#include "Director.h"
#include "Manager.h"
#include "Employee.h"

class Menu
{
private:
	/*
	Account's Role:
		1: Director
		2: Manager
		3: Employee
		4: Customer
	*/
	int _role;
	Account _account;
public:
	void redirect();
	void loginMenu();
	string getPassword(string& );
};

#endif