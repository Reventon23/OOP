#include<conio.h>
#include<windows.h>
#include "Interface.h"
#include<iostream>

using namespace std;

int main()
{
	//setlocale(LC_ALL, "Russian");
	//SetConsoleCP(1251);
//SetConsoleOutputCP(1251);
	Interface Screen ;
	Screen.mainmenu();
	_getch();
	return 0;
}

