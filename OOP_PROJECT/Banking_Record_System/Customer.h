#ifndef _CUSTOMER_H_
#define  _CUSTOMER_H_
#include"Header.h"
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

	int getType();
};

#endif

