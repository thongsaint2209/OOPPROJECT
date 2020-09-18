#include"Tokenizer.h"


int main() {
	string haystack = "HELLO WORLD WAR 3";
	string seporator = " W";

	Tokenizer t;

	vector<string> tokens=t.split(haystack, seporator);

	for (int i = 0;i < tokens.size();i++) {
		cout << tokens[i] << endl;
	}

	return 0;
}