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

	
	int _option;
	Account _account;
	
	vector<Request> _requestList1;
	vector<Request> _requestList2;
	vector<Customer> a;
	
	vector<Account> account;
	vector<Employee> e;
public:
	ManagerMenu()  {};
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



