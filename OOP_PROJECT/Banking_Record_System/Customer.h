#ifndef _CUSTOMER_H_
<<<<<<< Updated upstream
#define  _CUSTOMER_H_
#include"Header.h"
=======
#define _CUSTOMER_H_
#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
#include"../Banking_Record_System/MyStaticLib/MyStaticLib/Date.h"
using namespace std;


>>>>>>> Stashed changes
class Customer
{
private:
	float _balance;
	Account _Acc;
	int _duration;
	int _period;
	string _acctype;
	static float _TermRate;
	static float _DemandRate;
public:
	Customer(Account acc, float balance, string acctype, int period);
	void newAcc();
	void editInfo(string edit,string detail);
	void deleteAcc();

	float getBalance();
	float CalcInterest();

	void withdraw(float money);
	void deposit(float money);
	void transfer(float money);

<<<<<<< Updated upstream
	int getType();
=======
	void deleteAccount();

	float ClacInrest();

	void deposit(int money);

	void withdraw(int money);

	void tranfer(int money, Customer& cus);

	//Time - deposit account(1),Demand – deposit account(2),payment acc(3)
	int gettype();
>>>>>>> Stashed changes
};

#endif

