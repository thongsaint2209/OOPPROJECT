#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
class Random
{
public:
	Random() {
		srand(time(NULL));
	}
	int next() {
		return rand();
	}
	int next(int a) {
		return rand() % a;
	}


};

