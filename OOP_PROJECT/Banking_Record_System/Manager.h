#ifndef _MANAGER_H_
#define _MANAGER_H_

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
	Support _s;
	vector<Request> _requestList1;
	vector<Request> _requestList2;
	vector<Customer> a;
	vector<TradeHistory> _his;
	vector<Account> account;
	vector<Employee> e;

	Customer _c;
public:
	ManagerMenu() {}
	ManagerMenu(Account acc);
	void viewProfile();
	void changePassword();

	void showMenu();

	void viewRequest();

	void editRequest();

	void viewlistReDirector();

	void viewcustomer();

	void searchcustomer();

	void FireEmployee();

	void viewemployee();

	void searchemployee();

	void viewTradeHistory();
};

#endif

