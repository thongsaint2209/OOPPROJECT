#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Tokenizer
{
	public:
		static vector<string> split(string haystack, string separator);
};


#endif
