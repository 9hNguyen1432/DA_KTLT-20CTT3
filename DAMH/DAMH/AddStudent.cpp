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
		Sleep(1000);
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
			Sleep(1000);
		}
		else
		{
			Database data;
			data = Imput();
			string ClassSem = "file_save//SchoolYear//" + YearCourse + "//" + Class + csv_tail;
			fstream file2;
			int count = CheckRowInFile(ClassSem);
			file2.open(ClassSem, ios::app);
			file2 <<endl<< count+1 << "," << data.ID << "," << data.name << "," << data.Birth << "," << data.sex << "," << data.IDsocial;
			file2.close();
			fstream file3;
			file3.open("file_save//login_info.csv", ios::app);
			file3 <<endl<< data.ID << "," << data.ID << "," << "1" << "," << Class;
			file3.close();

			string CheckSe = CheckSem();
			fstream F, FILE;
			string S = "file_save//SchoolYear//" + YearCourse + "//Semester" + CheckSe + "//Class//" + Class + csv_tail;
			F.open(S, ios::app);
			F << data.ID << endl;
			int countFile = CheckRowInFile("file_save//InforNewStudent.csv");
			string checkName[1000], checkBirth[1000], checkSex[1000], checkIDso[1000];
			fstream File;
			File.open("file_save//InforNewStudent.csv", ios::in);
			int countRow = 1;
			int Dem = 0;
			while (!File.eof())
			{
				for (int i = 1; i <= countFile; i++)
				{
					getline(File, checkName[i], ',');
					getline(File, checkBirth[i], ',');
					getline(File, checkSex[i], ',');
					File >> checkIDso[i];
					countRow++;
					if (data.IDsocial == checkIDso[i])
					{
						Dem = countRow;
					}
				}
				
			}
			string arr[1000];
			fstream FIle;
			FIle.open("file_save//InforNewStudent.csv", ios::in);
			while (!FIle.eof())
			{
				for (int i = 0; i <= countFile; i++)
				{
					getline(FIle, arr[i]);
				}
			}
			FIle.close();;
			if (Dem != countFile)
			{
				fstream FIle;
				FIle.open("file_save//InforNewStudent.csv", ios::out);
				for (int i = 0; i < Dem-2; i++)
				{
					FIle << arr[i] << endl;
				}
				for (int i = Dem-1 ; i <= countFile; i++)
				{
					FIle << arr[i] << endl;
				}
				FIle.close();
			}
			gotoxy(43, 24);
			cout << "IMPORT INFO STUDENT SUCCESSFUL!!!" << endl;
			Sleep(1000);

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
		Sleep(1000);
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
			Sleep(1000);
		}
		else
		{
			ImportRandom(YearCourse, Class);
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

		string MenuAdd[] = { "1. Add One Student To Class",
		"2. Import Info Student From File To Class",
		"3. Exit" };
		drawMenu(MenuAdd, 3, 45, 12, 1, &drawASCIIMenuView);
		command = MoveAndChoose(3, MenuAdd, 45, 12, 1);

		switch (command)
		{
		case 0:
		{
			system("cls");
			AddStudentToClass();
			system("cls");
			break;
		}
		case 1:
		{
			system("cls");
			AddRandomInfoStudentToClass();
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