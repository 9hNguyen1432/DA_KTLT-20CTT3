#include "ConsoleProcess.h"
#include "Header.h"
#include "AddStudent.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "ListClass.h"

using namespace std;
const string csv_tail = ".csv";

void AddStudentToClass()
{
	drawASCIIMenuView();
	textBgColor(0, 15);
	string YearCourse;
	string Class;
	drawRectangle(35, 11, 60, 5, 11);
	gotoxy(43, 11);
	cout << "Enter School Year:";
	drawRectangle(43, 12, 45, 1, 15);
	gotoxy(43, 12);
	getline(cin, YearCourse);
	fstream file;
	file.open("file_save//year-semester.csv", ios::in);
	string Year;
	string tempSemester;
	bool check = false;
	while (!file.eof())
	{
		getline(file, Year, ',');
		getline(file, tempSemester);
		if (YearCourse == Year)
		{
			check = true;
		}
	}
	if (check == false)
	{
		gotoxy(43, 13);
		cout << "Don't Find School Year " << endl;
		system("pause");
	}
	if (check == true)
	{
		textBgColor(0, 11);
		gotoxy(43, 13);
		cout << "Enter Name Of Class:";
		drawRectangle(43, 14, 45, 1, 15);
		gotoxy(43, 14);
		getline(cin, Class);
		fstream file1;
		bool check1 = false;
		file1.open("file_save//SchoolYear//" + YearCourse + "//class_info.csv", ios::in);
		string stt, NameClass, major, number, year;
		while (!file1.eof())
		{
			getline(file1, stt, ',');
			getline(file1, NameClass, ',');
			getline(file1, major, ',');
			getline(file1, number, ',');
			file1 >> year;
			if (Class == NameClass)
			{
				check1 = true;
			}
		}
		if (check1 == false)
		{
			gotoxy(43, 15);
			cout << "Don't Find Class" << endl;
			system("pause");
		}
		else
		{
			Database data;
			data = Imput();
			system("pause");
			string ClassSem = "file_save//SchoolYear//" + YearCourse + "//" + Class + csv_tail;
			fstream file2;
			int count = CheckRowInFile(ClassSem);
			file2.open(ClassSem, ios::app);
			file2 << count << "," << data.ID << "," << data.name << "," << data.Birth << "," << data.sex << "," << data.IDsocial << endl;
			file2.close();
			fstream file3;
			file3.open("file_save//login_info.csv", ios::app);
			file3 << data.ID << "," << data.ID << "," << "1" << "," << Class << endl;
			file3.close();

		}
	}
}

void AddRandomInfoStudentToClass()
{
	drawASCIIMenuView();
	textBgColor(5, 15);
	string YearCourse;
	string Class;
	drawRectangle(35, 11, 60, 7, 11);
	gotoxy(43, 11);
	cout << "Enter School Year:";
	drawRectangle(43, 12, 45, 1, 15);
	gotoxy(43, 12);
	getline(cin, YearCourse);
	fstream file;
	file.open("file_save//year-semester.csv", ios::in);
	string Year;
	string tempSemester;
	bool check = false;
	while (!file.eof())
	{
		getline(file, Year, ',');
		getline(file, tempSemester);
		if (YearCourse == Year)
		{
			check = true;
		}
	}
	if (check == false)
	{
		gotoxy(43, 13);
		cout << "Don't Find School Year" << endl;
		system("pause");
	}
	if (check == true)
	{
		textBgColor(0, 11);
		gotoxy(43, 13);
		cout << "Enter Name Of Class:";
		drawRectangle(43, 14, 45, 1, 15);
		gotoxy(43, 14);
		getline(cin, Class);
		fstream file1;
		bool check1 = false;
		file1.open("file_save//SchoolYear//" + YearCourse + "//class_info.csv", ios::in);
		string stt, NameClass, major, number, year;
		while (!file1.eof())
		{
			getline(file1, stt, ',');
			getline(file1, NameClass, ',');
			getline(file1, major, ',');
			getline(file1, number, ',');
			file1 >> year;
			if (Class == NameClass)
			{
				check1 = true;
			}
		}
		if (check1 == false)
		{
			gotoxy(43, 15);
			cout << "Don't Find Class" << endl;
			system("pause");
		}
		else
		{
			gotoxy(43, 16);
			cout << "Random Info Student Has Been Imported To Class" << endl;
			fstream ofs, ifs;
			string NameClass = "file_save//SchoolYear//" + YearCourse + "//" + Class + csv_tail;
			ofs.open(NameClass, ios::app);
			ifs.open("file_save//InforNewStudent.csv", ios::in);
			string  NameSt, BirthSt, SexSt, IdSocialSt;
			int count = CheckRowInFile(NameClass);
			int IDSt;
			string CheckYear = { YearCourse };
			string CheckNameYear = { CheckYear[2] , CheckYear[3] };
			long MasoNam;
			MasoNam = atoi(CheckNameYear.c_str()) * 1000000;
			string str = { Class };
			string CheckNameClass = { str[2] , str[3] , str[4] };
			string CheckSTTClass = { str[5] };
			if (CheckNameClass == "CTT")
			{
				if (CheckSTTClass == "1")
				{
					IDSt = MasoNam + 120000;
				}
				if (CheckSTTClass == "2")
				{
					IDSt = MasoNam + 120100;
				}
				if (CheckSTTClass == "3")
				{
					IDSt = MasoNam + 120200;
				}
				if (CheckSTTClass == "4")
				{
					IDSt = MasoNam + 120300;
				}

			}
			if (CheckNameClass == "SHH")
			{
				if (CheckSTTClass == "1")
				{
					IDSt = MasoNam + 150000;
				}
				if (CheckSTTClass == "2")
				{
					IDSt = MasoNam + 150100;
				}
				if (CheckSTTClass == "3")
				{
					IDSt = MasoNam + 150200;
				}
				if (CheckSTTClass == "4")
				{
					IDSt = MasoNam + 150300;
				}
			}
			if (CheckNameClass == "HOH")
			{
				if (CheckSTTClass == "1")
				{
					IDSt = MasoNam + 150000;
				}
				if (CheckSTTClass == "2")
				{
					IDSt = MasoNam + 150100;
				}
				if (CheckSTTClass == "3")
				{
					IDSt = MasoNam + 150200;
				}
				if (CheckSTTClass == "4")
				{
					IDSt = MasoNam + 150300;
				}
			}
			if (CheckNameClass == "TTH")
			{
				if (CheckSTTClass == "1")
				{
					IDSt = MasoNam + 110000;
				}
				if (CheckSTTClass == "2")
				{
					IDSt = MasoNam + 110100;
				}
				if (CheckSTTClass == "3")
				{
					IDSt = MasoNam + 110200;
				}
				if (CheckSTTClass == "4")
				{
					IDSt = MasoNam + 110300;
				}
			}
			while (count != 31)
			{
				fstream finput;
				finput.open("file_save//login_info.csv", ios::app);
				long MSSV = IDSt + count;
				ofs << count << ",";
				ofs << MSSV << ",";
				finput << MSSV << "," << MSSV << "," << "1" << "," << Class << endl;
				getline(ifs, NameSt, ',');
				ofs << NameSt << ",";
				getline(ifs, BirthSt, ',');
				ofs << BirthSt << ",";
				getline(ifs, SexSt, ',');
				ofs << SexSt << ',';
				getline(ifs, IdSocialSt);
				ofs << IdSocialSt << endl;
				count++;
				finput.close();
			}
			ifs.close();
			ofs.close();
		}
	}
}


int RunMenuAddInfoStudentToClass()
{
	char ch;
	int command;
	while (true)
	{
		showPointer();
		system("cls");
		gotoxy(40, 12);
		string MenuAdd[] = { "0. Add One Student To Class",
		"1. Import Info Student From File To Class",
		"2. Exit" };
		drawMenu(MenuAdd, 3, 45, 12, 2, &drawASCIIMenuView);
		command = MoveAndChoose(3, MenuAdd, 45, 12, 2);
		switch (command)
		{
		case 0:
		{
			system("cls");
			AddStudentToClass();
			system("pause");
			system("cls");
			break;
		}
		case 1:
		{
			system("cls");
			AddRandomInfoStudentToClass();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			textBgColor(10, 11);
			printtext("YOU WANT TO EXIT, PRESS ENTER TO BACK TO MENU !!!", 40, 20);
			ch = _getch();
			textBgColor(0, 15);
			return 0;
		}
		}
	}
}