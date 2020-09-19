#include "AllRole.h"
#include "Director.h"
#include"Employee.h"

//only use for run the program
int main()
{
	Menu m;

	m.loginMenu();

//m.redirect();
	/*Customer c;
	c.newAccount();*/
	Employee e;
	e.SolvingReManager();
	return 0;
}