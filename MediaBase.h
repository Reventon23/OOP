#pragma once
#include <iostream>
#include <cstring>
#include"Information.h"
class Media
{
protected:
	long Size;
	long balanceSize;
	int ReadSpeed;
	int WriteSpeed;
	char* Vendor;
	char* Data;
	static int Count;
public:
	 Media(long Size, int ReadSpeed, int WriteSpeed);
	virtual ~Media();

	virtual char* Read();
	virtual void Write(char* buffer);
	void Format();
	virtual int operator~ () { return 1; };
	//set 
	void SetVendor(char* Vendor);
	//get
	static int GetCount() { return Count; };
	virtual void GetParametr() ;
	
};
//========================================
class USB :public Media
{
protected:
	static int Count;
	char *type;
	char *weight;
	vector<Exe>exe;
public:
	static int GetCount() { return Count; };
	USB(long Size, int ReadSpeed, int WriteSpeed, char *type,char *weight);
	~USB();
	void AddExe(int size, char *name,char* format);
	void deletExe(int i);
	void GetParamExe(int i);
	void FormatExe();

virtual void GetParametr();
};
//========================================
class Disk :public USB
{
protected:
	static int Count;
	char*Rewritable;
	char *DataSave;
public:
	void copy();
	void write();
	Disk(long Size, int ReadSpeed, int WriteSpeed, char *type, char *weight, char *Rewritable,char *DataSave);
	~Disk();
	static int GetCount() { return Count; };
	void GetParametr();
};
//=====================================
class HDD :public Media
{
protected:
	static int Count;
	char *Interface;
	int PartitionNum;
public:
	HDD(long Size, int ReadSpeed, int WriteSpeed, char *Interface,int PartitionNum);
	~HDD();
	static int GetCount() { return Count; };
	void Format();
	int FormatInt();
	void GetParametr();

};
//==========================================
class SSD :public Media
{
protected:
	char *status;
	int SpeedRotation;
	static int Count;
public:
	SSD(long Size, int ReadSpeed, int WriteSpeed, int SpeedRotation);
	~SSD();
	void printStatus();
	static int GetCount() { return Count; };
	void GetParametr();
};

class SSHD :public SSD, public HDD
{
protected:
	static int Count;
	int Number;
public:
	SSHD(long Size, int ReadSpeed, int WriteSpeed, char *Interface, int PartitionNum, int Number);
	~SSHD();
	static int GetCount() { return Count; };
	void Writen();
	void GetParametr();
};