#ifndef _ALLROLE_H_
#define _ALLROLE_H_

#include "Header.h"
#include "Director.h"

class Menu
{
private:
	int _role;
	Account _account;
public:
	void redirect();
	void loginMenu();
};

#endif