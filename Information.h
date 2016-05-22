#pragma once
#include<vector>
#include<iostream>
using namespace std;



class Information
{
protected:
	int size;
	char *name;
public:
	Information(int size, char *name);
	~Information();
	void GetParam();
	
};

class Exe :public Information
{
protected:
	char *format;
public:
	Exe(char *name, int  size, char* format);
	~Exe();
	void AddExe();
	void DeleteExe();
	void OpenExe();
	void Format();
	void GetParam();
};