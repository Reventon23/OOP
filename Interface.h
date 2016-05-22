#pragma once
#include<iostream>
#include<iomanip>
#include<conio.h>
#include"DataFile.h"
#include"MediaBase.h"
#include<vector>
using namespace std;
class Interface
{
protected:
	DataFile *Language;
	DataFile *Help;
	
	char *lngFile1 = "Russian.ini";
	char *lngFile2 = "English.ini";
	char *HelpFileRus = "Text.ini";
	char *HelpFileEng = "TextEng.ini";
	

	int flag = 1;
public:
	vector<USB> VectorUsb;
	vector<Disk> VectorDisk;
	vector<HDD> VectorHdd;
	vector<SSD> VectorSsd;
	vector<SSHD> VectorSshd;
	void ChangeLng();
	void mainmenu();
	Interface();
	void menu2();
	void AddElement();
	void PrintStatus();
	void menuUSB();
	void menuDisk();
	void menuHDD();
	void menuSSD();
	void menuSSHD();
	~Interface();
};

