#pragma once
#ifndef _FAKEEMAIL_H_
#define _FAKEEMAIL_H_


#include<iostream>
#include<memory>
#include<vector>
#include "FakeName.h"
using namespace std;

class FakeEmail
{
private:

	FakeName _fkname;
	vector<string> _companyDomand = { "gmail.com", "microsoft.com", "apple.com", "amazon.com" };
	friend class Student;
public:
	
	string next();
	
};
#endif // !_FAKEEMAIL_H_
