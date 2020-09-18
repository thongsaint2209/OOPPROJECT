#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
class Random
{
public:
	Random() {
<<<<<<< Updated upstream
		srand(time(NULL));
=======
		//srand(time(NULL));
>>>>>>> Stashed changes
	}
	int next() {
		return rand();
	}
	int next(int a) {
		return rand() % a;
	}


};

