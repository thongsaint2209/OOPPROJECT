#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include".\\MyStaicLib\Date.h"
#include"BankAccount.h"

class Employee
{
private:
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

