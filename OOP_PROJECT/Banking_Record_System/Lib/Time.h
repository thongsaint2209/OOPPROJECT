#ifndef TIME_H
#define TIME_H
#include <ctime>
#include <sstream>
#include "Tokenizer.h"

using namespace std;
class Time
{
	private:
		tm* now;
	public:
		Time();
		Time(int _h, int _m, int _s);
		string toString();
		Time parse(string);
		bool tryParse(string, Time );
		bool isValid(string);

};

#endif
