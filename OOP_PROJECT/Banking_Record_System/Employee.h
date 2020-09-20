#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
#include "Customer.h"

using namespace std;

class Employee
{
private:

	string _id;
	string	_name;
	string _birth;
	string	_address;
	string _phone;
	string _mail;
	int _merits;
	float _TermRate;
	float _DemandRate;
	int _option;
	Account _account;
	Support _s;
	Customer _c;
	vector<Request> _requestList;
	vector<Account> account;
	vector<Employee> e;
	vector<Customer> a;
public:
	Employee(Account acc) { this->_account = acc; }
	Employee() {
		this->_id = "";
		this->_name = "";
		this->_birth = "";
		this->_address = "";
		this->_phone = "";
		this->_mail = "";
		this->_merits = 0;
	}
	void setId(string id)
	{
		_id = id;
	}
	void setname(string name)
	{
		_name = name;
	}
	void setaddress(string address)
	{
		_address = address;
	}
	void setMerit(int point)
	{
		this->_merits = point;
	}
	string getId()
	{
		return _id;
	}
	string getname()
	{
		return _name;
	}
	string getbirth()
	{
		return _birth;
	}
	string getaddress()
	{
		return _address;
	}
	string getphone()
	{
		return _phone;
	}
	string getmail()
	{
		return _mail;
	}
	int getmerit()
	{
		return _merits;
	}
	
	Employee(string id, string name, string birth, string address, string phone, string mail,  int merits)
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

	
};

#endif


