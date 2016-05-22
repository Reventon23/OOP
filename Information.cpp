#include "Information.h"



Information::Information(int size, char* name)
{
	this->size = size;
	this->name = name;
	
}


Information::~Information()
{
	//delete[] name;
}

void Information::GetParam()
{
	cout << this->name << endl;
	cout << this->size << endl;
}




//======================================================================================================
Exe::Exe(char* name,int  size,char *format):Information( size, name)
{
	this->format = format;
}

Exe::~Exe()
{
	
}

void Exe::AddExe()
{
}

void Exe::DeleteExe()
{
}

void Exe::OpenExe()
{
}

void Exe::Format()
{
}

void Exe::GetParam()
{
	Information::GetParam();
	cout << this->format << endl;
}

