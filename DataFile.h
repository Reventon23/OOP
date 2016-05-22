//---------------------------------------------------------------------------

#include <fstream> 
using namespace std;
//---------------------------------------------------------------------------
class DataFile
{
protected:
	ifstream File;
	const static size_t Bufsize;
	char *Section;
	char *Line;
	static int Count;
public:
	DataFile(const char *FileName);
	virtual ~DataFile();
	static int GetCount() { return Count; };
	virtual void Open(const char *FileName);
	virtual void SetSection(const char *Section);
	virtual void SetLine(const char *Line);
	char* GetLine() const;
	char* GetLine(const char *Section, const char *Line);
	int GetNumber(const char *Section, const char *Line);

};