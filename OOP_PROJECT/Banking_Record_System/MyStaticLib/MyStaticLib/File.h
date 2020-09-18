#pragma once
#include"Student.h"
class File
{
private:
	string _FileName;
public:
	File(string filename);
	void writeFile();
	
	void showTop5Student();
};

