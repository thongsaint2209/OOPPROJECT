#pragma once
#ifndef _FAKENAME_H_
#define _FAKENAME_H_


#include"Random.h"
#include"FullName.h"
#include<memory>
class FakeName
{
private:
	/*class FakeNamePrivate;
	unique_ptr<FakeNamePrivate> _piml;*/
public:
	FullName next();
};

#endif // !_FAKENAME_H_