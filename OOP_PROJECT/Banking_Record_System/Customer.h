#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>

using namespace std;


class Customer
{
private:

	string _id;
	string	_name;
	string _birth;

	string	_address;


	string _phone;
	string _mail;
	string _acctype;
	int _balance;
	int _duration;
	int _period;


	float _TermRate;
	float _DemandRate;

	int _option;
	Account _account;

	vector<Request> _requestList;
	vector<Account> account;
    vector<Customer> a;
public:
	Customer() {};
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
	string getacctype()
	{
		return _acctype;
	}
	int getBalance()
	{
		return _balance;
	}
	int getDuration()
	{
		return _duration;
	}
	int getPeriod()
	{
		return _period;
	}
	Customer(string id, string name, string birth,string address,string phone,string mail,string type, int balance,int duration,int period)
	{
		this->_id = id;
		this->_name = name;
		this->_birth = birth;
		this->_address = address;
		this->_phone = phone;
		this->_mail = mail;
		this->_acctype = type;
		this->_balance = balance;
		this->_duration = duration;
		this->_period=period;
	}
	Customer(string id, string name, string birth, string address, string phone, string mail, string type)
	{
		this->_id = id;
		this->_name = name;
		this->_birth = birth;
		this->_address = address;
		this->_phone = phone;
		this->_mail = mail;
		this->_acctype = type;
		this->_balance = 0;
		this->_duration = 0;
		this->_period = 0;
	}
	void newAccount();

	void showMenu();

    void Editprofile();

	void deleteAccount();
};

#endif

