#include "Header.h"
#include "Customer.h"
#include "Employee.h"
	class ManagerMenu
{
protected:
	string _id;
	string _birth;
	string	_name;
	string	_address;


	string _phone;
	string _mail;
	string _acctype;
	int _duration;
	int _period;
	
	static float _TermRate;
	static float _DemandRate;

	int	_balance;
	int _option;
	Account _account;
	
	vector<Request> _requestList1;
	vector<Request> _requestList2;
	vector<Customer> a;
	
	vector<Account> account;
	vector<Employee> e;
public:
	ManagerMenu()  {};
	ManagerMenu(Account acc);

	void showMenu();

	void viewRequest();

	void editRequest();

	void viewlistReDirector();

	void viewcustomer();

	void searchcustomer();

	void FireEmployee();

	void viewemployee();

	void searchemployee();
};


