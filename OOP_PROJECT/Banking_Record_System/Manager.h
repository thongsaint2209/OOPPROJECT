#include "Header.h"
#include "Customer.h"

	class ManagerMenu
{
protected:
	string _id;
	string _birth;
	string	_name;
	string	_address;


	string _phone;
	string _mail;
	int _duration;
	int _period;
	string _acctype;
	static float _TermRate;
	static float _DemandRate;

	int	_balance;
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



