#pragma once
#ifndef _FAKEADDRESS_H_
#define _FAKEADDRESS_H_


#include"FakeName.h"
#include"Address.h"
#include<memory>
#include<vector>
class FakeAddress
{
private:
	/*class FakeAddressPrivate;
	unique_ptr<FakeAddressPrivate> _piml;*/
	
public:
	Address next();
};

#endif // !_FAKEADDRESS_H_