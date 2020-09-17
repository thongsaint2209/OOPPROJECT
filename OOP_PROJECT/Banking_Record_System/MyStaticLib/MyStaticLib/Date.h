#pragma once
#ifndef _DATE_H_
#define _DATE_H_

#include"Time.h"
class Date
{
private:
	int _day;
	int _month;
	int _year;
	friend class FakeBirthday;
	friend class Student;
public:
	Date();
	Date(int, int, int);
	string toString();
	Date parse(string);
	bool tryParse(string, Date&);
	bool isValid(string);
	bool isLeapYear(int);
};

#endif // !_DATE_H_