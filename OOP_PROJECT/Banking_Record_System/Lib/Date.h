#ifndef DATE_H
#define DATE_H
#include <ctime>
#include <sstream>
#include "Tokenizer.h"

class Date
{
	private:
		tm* now;
	public:
		Date();
		Date(int, int, int);
		string toString();
		Date parse(string);
		bool tryParse(string, Date);
		bool isValid(string);
		bool isLeapYear(int);
};

#endif
