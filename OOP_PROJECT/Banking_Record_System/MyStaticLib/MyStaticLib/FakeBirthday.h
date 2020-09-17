#pragma once
#ifndef _FAKEBIRTHDAY_H_
#define _FAKEBIRTHDAY_H_
#include"Date.h"
#include"FakeEmail.h"
class FakeBirthday
{
public:
	Date next();
	Date next(int age);
};

#endif