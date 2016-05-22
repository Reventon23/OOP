#include "Interface.h"
#include"MediaBase.h"
#include<string.h>

using namespace std;

Interface::Interface()
{
	Language = new DataFile(lngFile1);
	Help = new DataFile(HelpFileRus);
	
}
void Interface::mainmenu()
{
	
	int key;
	do
	{	
		cout << setw(60) << right << this->Language->GetLine("Title", "DonNTU") << endl;
		cout << setw(40) << right << this->Language->GetLine("Title", "KNT") << endl;
		cout << this->Language->GetLine("Title", "PMI") << endl;
		cout << this->Language->GetLine("Title", "Subject") << endl;
		cout << this->Language->GetLine("Title", "Student") << endl;
		cout << this->Language->GetLine("Title", "Group") << endl;
		cout << this->Language->GetLine("Title", "Manager1") << endl << endl;
		cout << "1-"<< this->Language->GetLine("Menu", "Main_1") << endl;
		cout << "2-"<< this->Language->GetLine("Menu", "Main_2") << endl;
		cout << "3-" << this->Language->GetLine("Menu", "Main_3") << endl;
		cout << "4-" << this->Language->GetLine("Menu", "Main_4") << endl;
	key = _getch();
	switch (key)
	{
	case'1':
		system("cls");
		menu2();
		break;
	case'2':
		    ChangeLng();
			system("cls");
			mainmenu();
		break;
	case'3':
	{	
	
		system("cls");
		cout << "options" << endl;
		cout << this->Help->GetLine("Information", "Name") << endl;
		cout << "...................." << endl;
		break;
	}
	case'4':
		system("cls");
		cout << "help" << endl;
		break;
	}
	} while (key !='1');
}

void Interface::menu2()
{ 
	int key;
	do {
		cout << endl<< "1-" << this->Language->GetLine("Menu", "Menu2_1") << endl;
		cout  << "2-" << this->Language->GetLine("Menu", "Menu2_2") << endl;
		cout  << "3-" << this->Language->GetLine("Menu", "Menu2_3") << endl;
		key = _getch();
		switch (key)
		{
		case '1':
			system("cls");
			AddElement();
			break;
		case '2':
			system("cls");
			PrintStatus();
			break;
		case '3':
			system("cls");
			mainmenu();
			break;
		}
	} while (key != '3');
}

void Interface::AddElement()
{
	
	
	int size, readspeed, writespeed, partitionNum, speedRotation, number, countUSB = 0, countDisk = 0, countHDD = 0, countSSd = 0, countSSHD = 0;
	char* type="type",*weight="weight", *Rewritable="rewritable", *Interface="interface",
		*DataSave = "DataSave";
	
	
	int key;
	do {
		
		cout << "1-"<< this->Language->GetLine("Menu", "Menu3_1") << endl;
		cout << "2-" << this->Language->GetLine("Menu", "Menu3_2") << endl;
		cout << "3-" << this->Language->GetLine("Menu", "Menu3_3") << endl;
		cout << "4-" << this->Language->GetLine("Menu", "Menu3_4") << endl;
		cout << "5-" << this->Language->GetLine("Menu", "Menu3_5") << endl;
		cout << "6-" << this->Language->GetLine("Menu", "Menu3_6") << endl;
		key = _getch();
		
		switch (key)
		{
		case'1':
		{	
			size = rand() % 500 + 50; 
			writespeed = rand() % 800 + 100;
			readspeed = rand() % 1000 + 200;
			system("cls");
			VectorUsb.push_back(USB(size, writespeed, readspeed, type, weight));
			VectorUsb[countUSB].GetParametr();
			countUSB++;
			menuUSB();
			break;
		}
		case'2':
		{
			size = rand() % 500 + 50;
			writespeed = rand() % 800 + 100;
			readspeed = rand() % 1000 + 200;
			system("cls");
			VectorDisk.push_back(Disk(size, writespeed, readspeed, type, weight, Rewritable, DataSave));
			VectorDisk[countDisk].GetParametr();
			countDisk++;
			menuDisk();
			break;
		}
		case'3':
		{
			size = rand() % 500 + 50; 
			writespeed = rand() % 800 + 100;
			readspeed = rand() % 1000 + 200;
			partitionNum = rand () % 15 + 1;
			system("cls");
			VectorHdd.push_back(HDD(size, writespeed, readspeed, Interface, partitionNum));
			VectorHdd[countHDD].GetParametr();
			countHDD++;
			menuHDD();
			break;
		}
		case'4':
		{
			size = rand() % 500 + 50; 
			writespeed = rand() % 800 + 100;
			readspeed = rand() % 1000 + 200;
			speedRotation= rand() % 2000 + 400;
			system("cls");
			VectorSsd.push_back(SSD(size, writespeed, readspeed, speedRotation));
			VectorSsd[countSSd].GetParametr();
			countSSd++;
			menuSSD();
			break;
		}
		case'5':
		{
			size = rand() % 500 + 50; 
			writespeed = rand() % 800 + 100;
			readspeed = rand() % 1000 + 200;
			partitionNum = rand() % 15 + 1;
			number= rand() % 10 + 1;
			system("cls");
			VectorSshd.push_back(SSHD(size, writespeed, readspeed, Interface, partitionNum, number));
			VectorSshd[countSSHD].GetParametr();
			countSSHD++;
			menuSSHD();
			break;
		}
		case'6':
			system("cls");
			menu2();
			break;
		}
	} while (key != '6');
}

void Interface::PrintStatus()
{
	cout << "общее количество Устройств:" << endl;
	cout <<"Disk: "<< VectorDisk.size() << endl;
	cout << "SSD: " << VectorSsd.size() << endl;
	cout << "HDD: " << VectorHdd.size() << endl;
	cout << "SSHD: " << VectorSshd.size() << endl;
	cout << "USB: " << VectorUsb.size() << endl;
}

void Interface::menuUSB()
{

	int key,i=-1;
	char nameExef[30];//имя exe
	char format[30];//format
	int numberExe;
	int size, number, numberDelete;//size -размер(обьем),number- номер устройства,numberDelet-номер устройства на котором удаляем удаляемого 
	do 
	{
		cout << "1 add" << endl;
		cout << "2 delete" << endl;
		cout << "3 format"<<endl;
		cout << "4 exit" << endl;
		key = _getch();
		switch (key)
		{
		case'1':
		{
			system("cls");
			cout << "vvedi nomer" << endl;
			cin >> number;
			if (!cin||number>VectorUsb.size())
				cout << "lox" << endl;
			else
			{
				number -= 1;
				cout << "vvedi size" << endl;
				cin >> size;
				if (!cin)
					cout << "lox2" << endl;
				cout << "vvedi name" << endl;
				cin >> nameExef;
				cout << "vvedi format" << endl;
				cin >> format;
				VectorUsb[number].AddExe(size, nameExef,format);
				//VectorUsb[number].GetParamExe(i+=1);
				//menuUSB();
			}
		}
			break;
		case'2':
			system("cls");
			cout << "vvedi nomer delete" << endl;
			cin >> numberDelete;
			if (!cin || numberDelete > VectorUsb.size())
				cout << "lox" << endl;
			else
			{
				cout << "numberEXe file" << endl;
				cin >> numberExe;
				if (!cin  )
					VectorUsb[numberDelete].deletExe(numberExe - 1);
			}
			break;
		case'3':
			cout << "vvedi nomer delete" << endl;
			cin >> numberDelete;
			if (!cin || numberDelete > VectorUsb.size())
				cout << "lox" << endl;
			else
			{
				VectorUsb[numberDelete].FormatExe();
			}
			break;
		}
	} while (key != '4');
}

void Interface::menuDisk()
{
}

void Interface::menuHDD()
{
}

void Interface::menuSSD()
{
}

void Interface::menuSSHD()
{
}





Interface::~Interface()
{
	
	delete[] Language;
}


void Interface::ChangeLng()
{
	if (flag == 0)
	{
		flag = 1;
		this->Language->Open(lngFile1);
		this->Help->Open(HelpFileRus);
	}
	else
	{
		flag = 0;
		this->Language->Open(lngFile2);
		this->Help->Open(HelpFileEng);
	}
}

