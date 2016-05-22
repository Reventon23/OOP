//---------------------------------------------------------------------------
#include <ctype.h>
using namespace std;
#include<iostream>
#include "DataFile.h"
//---------------------------------------------------------------------------


const size_t DataFile::Bufsize = 4096;
int DataFile::Count = 0;


DataFile::DataFile(const char *FileName)
{
        this->File.open(FileName, ios::in);
     //  if(!File.is_open()) throw OpenError;
        this->Section = new char [DataFile::Bufsize];
        this->Line = NULL;
        Count++;
}


DataFile::~DataFile()
{
	File.close();
	delete [] this->Section;
        Count--;
}


void DataFile::Open(const char *FileName)
{
        if(File.is_open()) File.close();
        File.open(FileName, ios::in);
       // if(!File.is_open()) throw OpenError(FileName);
}


void DataFile::SetSection(const char *Section)
{
        File.clear(0);
	File.seekg(0);
	do
	{
		File.getline(this->Section, Bufsize, '[');
		File.getline(this->Section, Bufsize, ']');
	//	if (File.eof()) throw SectionNotFound(Section);
	}while (strcmp(this->Section, Section));
        File.get();
        File.getline(this->Section, Bufsize, '[');
}

void DataFile::SetLine(const char *Line)
{
        this->Line = strtok(this->Section, "=");
    //    if(this->Line == NULL) throw LineNotFound(Line);
        while(strcmp(this->Line, Line))
        {
                this->Line = strtok(NULL, "\n");
                this->Line = strtok(NULL, "=");
              //  if(this->Line == NULL) throw LineNotFound(Line);
        }
        this->Line = strtok(NULL, "\n");
}


char* DataFile::GetLine() const
{
        return this->Line;
}

char* DataFile::GetLine(const char *Section, const char *Line)
{
        SetSection(Section);
        SetLine(Line);
        return GetLine();
}

int DataFile::GetNumber(const char *Section, const char *Line)
{
        SetSection(Section);
        SetLine(Line);
        char *digit = this->Line;
        while(*digit != 0)
              //  if(!isdigit(*(digit++)))
                 //       throw WrongData(Section, Line);
        return atoi(GetLine());
}
