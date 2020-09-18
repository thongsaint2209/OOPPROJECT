#pragma once
#include <vector>
#include<iostream>
#include<string>
using namespace std;
class Tokenizer
{
public:

	static vector<string> split(string haystack, string separator ) {
		vector<string> results;
		int startPos = 0;
		while (true) {
			size_t foundPos = haystack.find(separator, startPos);
			if (foundPos != string::npos) {
				string token = haystack.substr(startPos, foundPos - startPos);
				results.push_back(token);
				startPos = separator.length() + foundPos;
			}
			else {
				string result = haystack.substr(startPos, haystack.length() - startPos);
				results.push_back(result);
				break;
			}
		}
		return results;
	}

};

