#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;
//
struct Date {
	int Date;
	int Month;
	int Year;
};
struct Database {
	int ID;
	string name;
	Date Birth;// ngày sinh
	string sex;
};


void openFileToInput(const char* filename, fstream& fs)
{
	fs.open(filename, ios::in);
	if (fs.fail())
	{
		return;
	}
}

void openFileToOutput(const char* filename, fstream& fs)
{
	fs.open(filename, ios::out);
	if (fs.fail())
	{
		return;
	}
}

void ReturnClass(fstream& f, Database& info, fstream& ofs)
{
	int count = 0;
	while (!f.eof() && (count != 90))
	{
		string ID;
		getline(f, ID, ',');
		info.ID = atoi(ID.c_str());
		if (info.ID == 0) break;
		ofs << info.ID << ',';
		getline(f, info.name, ',');
		ofs << info.name << ',';
		string date, month, year;
		getline(f, date, ',');
		info.Birth.Date = atoi(date.c_str());
		ofs << info.Birth.Date << ',';
		getline(f, month, ',');
		info.Birth.Month = atoi(month.c_str());
		ofs << info.Birth.Month << ',';
		getline(f, year, ',');
		info.Birth.Year = atoi(year.c_str());
		ofs << info.Birth.Year << ',';
		f >> info.sex;
		ofs << info.sex << endl;
		count += 1;
	}
}

void ListClass()
{
	Database info;
	fstream ifs;
	fstream ofs1, ofs2, ofs3, ofs4, ofs5;
	openFileToInput("file_save/infor_student.csv", ifs);
	openFileToOutput("file_save/20CTT1.csv", ofs1);
	ReturnClass(ifs, info, ofs1);
	openFileToOutput("file_save/20CTT2.csv", ofs2);
	ReturnClass(ifs, info, ofs2);
	openFileToOutput("file_save/20CTT3.csv", ofs3);
	ReturnClass(ifs, info, ofs3);
	openFileToOutput("file_save/20CTT4.csv", ofs4);
	ReturnClass(ifs, info, ofs4);
	openFileToOutput("file_save/20CTT5.csv", ofs5);
	ReturnClass(ifs, info, ofs5);
}
