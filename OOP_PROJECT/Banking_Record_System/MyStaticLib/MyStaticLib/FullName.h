#pragma once
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class FullName
{
private:
	string _firstName;
	string _middleName;
	string _lastName;
	friend class FakeName;
	friend class FakeEmail;
	friend class Student;
public:
	string toString() {
		stringstream writer;
		writer << _firstName << " " << _middleName << " " << _lastName;

		return writer.str();
	}
	
};

