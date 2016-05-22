#pragma once
#include "MediaBase.h"
using namespace std;
//= == == == == == == == == == == == == == == == == == == == == == == == == == =
int Media::Count = 0;
int USB::Count = 0;
int HDD::Count = 0;
int SSD::Count = 0;
int Disk::Count = 0;
int SSHD::Count = 0;

Media::Media (long Size, int ReadSpeed, int WriteSpeed)
{
		this->Size = Size;
        this->ReadSpeed = ReadSpeed;
        this->WriteSpeed = WriteSpeed;
        this->Data = new char[Size];
        this->Data[0] = 0;
	Vendor = NULL;
	Count++;
}
Media::~Media()
{
	//if (Vendor) delete [] Vendor;
    //    delete [] Data;
	Count--;
}
char* Media::Read()
{
        return Data;
}
void Media::Write(char* buffer)
{ 
        strncpy(Data, buffer, Size);
}
void Media::Format()
{

	delete[] Data;
	Data = new char[Size];
	Data[0] = 0;
}
void Media::GetParametr() 
{
	cout << "Size: " << this->Size << endl;
	cout << "ReadSpeed: " << this->ReadSpeed << endl;
	cout << "WriteSpeed: " << this->WriteSpeed << endl;
}
void Media::SetVendor(char* Vendor)
{
        if(this->Vendor) delete [] this->Vendor;
	this->Vendor = new char [strlen(Vendor)+1];
	strcpy(this->Vendor, Vendor);
}
//===========================================================
USB::USB(long Size, int ReadSpeed, int WriteSpeed, char *type, char *weight):Media( Size, ReadSpeed,  WriteSpeed)
{
	this->type = type;
	this->weight = weight;
	this->balanceSize = this->Size;
	Count++;
}
USB::~USB()
{
	//delete[] type;
	//delete[] weight;
	Count--;
}

void USB::AddExe(int size, char* name,char* format)
{
	this->balanceSize -= size;
	if (this->balanceSize  < 0)
		cout << "balanseError" << endl;
	else
	{
		exe.push_back(Exe(name, size, format));
	}
}


void USB::deletExe(int i)
{
	if (i > exe.size())
		cout << "lox" << endl;
	else
	exe.erase(exe.begin()+(i - 1));
}

void USB::GetParamExe(int i)
{
	exe[i].GetParam();
}

void USB::FormatExe()
{
	exe.clear();
}

void USB::GetParametr()
{
	Media::GetParametr();
	cout <<"type: "<< this->type << endl;
	cout << "weight: " <<this->weight<< endl;
}

//==========================================================
Disk::Disk(long Size, int ReadSpeed, int WriteSpeed, char * type, char * weight, char * Rewritable,char *DataSave):USB( Size,  ReadSpeed,  WriteSpeed, type, weight)
{
	this->Rewritable = Rewritable;
	this->DataSave = DataSave;
	Count++;
}
Disk::~Disk()
{
	//delete[] Rewritable;
	//delete[] type;
	//delete[] weight;
	//delete[]DataSave;
	Count--;
}
void Disk::GetParametr()
{
USB::GetParametr();
cout << "Rewriteble: " << this->Rewritable << endl;
cout << "DataSave: " << this->DataSave << endl;
}
void Disk::copy()
{
}
void Disk::write()
{
}

//============================================================

HDD::HDD(long Size, int ReadSpeed, int WriteSpeed, char * Interface, int PartitionNum) :Media(Size, ReadSpeed, WriteSpeed)
{
	this->Interface = Interface;
	this->PartitionNum = PartitionNum;
	Count++;
}
HDD::~HDD()
{
	//delete[] Interface;
	Count--;
}
void HDD::Format()
{
}
int HDD::FormatInt()
{
	return 0;
}
void HDD::GetParametr()
{
	Media::GetParametr();
	cout << "PartitionNum: " << this->PartitionNum << endl;
	cout << "Interface: " << this->Interface << endl;
}
//============================================================

SSD::SSD(long Size, int ReadSpeed, int WriteSpeed, int SpeedRotation) :Media(Size, ReadSpeed, WriteSpeed)
{
	this->SpeedRotation = SpeedRotation;
	Count++;
}
SSD::~SSD()
{
	//delete[] status;
	Count--;
}
void SSD::printStatus()
{
}
void SSD::GetParametr()
{
	Media::GetParametr();
	cout << "SpeedRotation: " << this->SpeedRotation << endl;
}
//===================================================================

SSHD::SSHD(long Size, int ReadSpeed, int WriteSpeed, char * Interface, int PartitionNum, int Number)
	:HDD(Size, ReadSpeed,  WriteSpeed,  Interface,  PartitionNum),
	SSD( Size,  ReadSpeed,  WriteSpeed,  SpeedRotation)
{
	this->Number = Number;
	Count++;
}
SSHD::~SSHD()
{
//	delete[]Interface;
	Count--;
}

void SSHD::Writen()
{
	
}

void SSHD::GetParametr()
{
	Media::GetParametr();
	cout << "interface: " << this->Interface << endl;
	cout << "PartitionNum: " << this->PartitionNum << endl;
	cout << "Number: " << this->Number << endl;

}
