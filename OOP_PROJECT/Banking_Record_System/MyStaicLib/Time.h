#pragma once
#include<iostream>
#include<memory>
#include<ctime>
#include<sstream>
#include<vector>
#include"../MyStaicLib/Mylib/Tokenizer/Tokenizer.h"
#include<iomanip>

using namespace std;
class Time
{
private:
	int _second;
	int _minute;
	int _hour;
public:
	Time();
	Time(int, int, int);
	string toString();
	string toString12hourFormat();
	Time parse(string);
	bool tryParse(string, Time&);
	bool isValid(string);
};

