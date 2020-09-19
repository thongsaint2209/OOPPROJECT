#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
#include <sstream>
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


	static float _TermRate;
	static float _DemandRate;

	int _option;
	Account _account;
	Support _s;

	vector<Request> _requestList;
 vector<Account> account;


    static  vector<Customer> a;
public:
	Customer() {};
	Customer(Account acc) { this->_account = acc; }
	void viewProfile();
	void changePassword();
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
		this->_period = period;
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

    float ClacInrest();


	int gettype();

	static void withdraw(int money,string id1);
	
	static void deposit(int money, string id2);
	void saveTradeHistory(string id, string type, float money);
	void viewTradeHistory();
};

class TradeHistory
{
private:
	string _time;
	string _id;
	string _type;
	float _money;
public:
	TradeHistory(string id, string type, float money) {
		this->_id = id;
		this->_type = type;
		this->_money = money;
	}
	TradeHistory(string time, string id, string type, float money) {
		this->_time = time;
		this->_id = id;
		this->_type = type;
		this->_money = money;
	}
	string getTime() { return _time; }
	string getId() { return _id; }
	string getType() { return _type; }
	float getMoney() { return _money; }
};

#endif

