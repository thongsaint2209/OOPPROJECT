#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_

#include "Header.h"

class DirectorMenu
{
private:
	string _id;
	string _birth;
	string _name;
	string _address;
	string _phone;
	string _mail;
	int _duration;
	int _period;
	string _acctype;
	static float _TermRate;
	static float _DemandRate;
	int	_balance;
	int _mode;
	Account _account;
	Support _s;
	vector<Request> _requestList;
public:
	DirectorMenu(Account acc);
	void viewProfile();
	void changePassword();
	void showMenu();
	void viewRequest();
	void editRequest();
	string getTotalMoney();
	void showFireMenu();
	int getTotalCustomer();
	void viewVIPCustomer();
	void searchEmployee();
	void viewEmployee();
	void viewFeedBack();
	void bankRupt();
};

#endif