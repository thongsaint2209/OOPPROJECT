#ifndef MANAGER_H
#define MANAGER_H

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
	int _merits;
	static float _TermRate;
	static float _DemandRate;

	int	_balance;
	int _option;
	Account _account;
	Support _s;
	vector<Request> _requestList1;
	
	vector<Customer> a;
	//vector<TradeHistory> _his;
	vector<Account> account;
	vector<Employee> e;

	Customer _c;
public:
	ManagerMenu() {}
	ManagerMenu(Account acc);

	ManagerMenu(string id, string name, string birth, string address, string phone, string mail, int merits)
	{
		this->_id = id;
		this->_name = name;
		this->_birth = birth;
		this->_address = address;
		this->_phone = phone;
		this->_mail = mail;
		this->_merits = merits;
	}
	void viewProfile();
	void changePassword();

	void showMenu();

	void viewRequest();

	void editRequest();

	void viewcustomer();

	void searchcustomer();

	void FireEmployee();

	void viewemployee();

	void searchemployee();

	///void viewTradeHistory();

	void SolvingReDirector();

	void IncreaseMerit();
};

#endif

