#pragma once
#include<sstream>
#include<vector>
#include<fstream>
#include"FakeAddress.h"
#include"FakeName.h"
#include"FakeEmail.h"
#include"FakeBirthday.h"
#include"FakeTel.h"
#include"Random.h"
class Student
{
private:
	/*class StudentPrivate;
	unique_ptr<StudentPrivate> _piml;*/
	string _ID;
	string _fullname;
	Date _birthday;
	Address _addr;
	string _email;
	string _number;
	float _avg;


public:
	Student() {}
	Student(string ID, string fullname, Date birthday, Address addr, string email, string number, float avg);

	Student next();
	string tostring();
	static Student parse(string line);
	float getAVG() {
		return _avg;
	}
};

