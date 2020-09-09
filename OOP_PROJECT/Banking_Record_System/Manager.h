#include "Header.h"
#include "Customer.h"

	class ManagerMenu
{
protected:
	int _option;
	Account _account;
	
	vector<Request> _requestList1;
	vector<Request> _requestList2;
	vector<Customer> a;
	
	vector<Account> account;
public:
	
	ManagerMenu(Account acc);

	void showMenu();

	void viewRequest();

	void editRequest();

	void viewlistReDirector();

	void viewcustomer();

	void searchcustomer();

	void FireEmployee();
};



