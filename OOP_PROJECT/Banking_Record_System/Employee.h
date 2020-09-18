#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
#include "..\MyStaicLib\Date.h"
#include"BankAccount.h"

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

	vector<Request> _requestList;
	vector<Account> account;
	vector<Employee> e;
public:
	Employee() {};
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

	void showMenu();
	int _creditScore;
	vector<Date> _history;
public:
	//return 1 if functions perform and 0 if it don't 
	bool withdraw(BankAccount client,float money);
	bool deposit(BankAccount client, float money);

	float CalcInterest(BankAccount client);
	void ShowRequestList();
	bool resign();
	bool accuse();

	void increaseCredit();
	void promote();
	void TransactionHistory();

};

#endif

