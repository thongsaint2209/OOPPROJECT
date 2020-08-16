#pragma once
#include"Time.h"
class Date
{
private:
	int _day;
	int _month;
	int _year;
	friend class FakeBirthday;
public:
	Date();
	Date(int, int, int);
	string toString();
	Date parse(string);
	bool tryParse(string, Date&);
	bool isValid(string);
	bool isLeapYear(int);
};

