#pragma once
#ifndef _ADDRESS_H_
#define _ADDRESS_H_


#include<iostream>
using namespace std;
class Address
{
private:
	string _number;
	string _street;
	string _ward;
	string _district;
	string _city;
	friend class FakeAddress;
	friend class Student;
public:
	string toString() {
		
			stringstream writer;
			writer << _number << " " << _street << " " << _ward << " " << _district << " " << _city;

			return writer.str();
		
	}
};

#endif // !_ADDRESS_H_