#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <fstream>
#include"ConsoleProcess.h"
#include "Course_function.h"
#include "staffFunction.h"

using namespace std;

const string csv_tail = ".csv";

struct Database {
	string No;
	string ID;
	string name;
	string Birth;
	string sex;
	string IDsocial;
};
void drawASCIIMenuView();
Database Imput()
{
	Database data;
	gotoxy(53, 17);
	cout << "IMPUT INFORMATION STUDENT" << endl;
	cin.ignore();
	gotoxy(58, 18);
	cout << "Mssv:";
	getline(cin, data.ID);
	gotoxy(58, 19);
	cout << "Name:";
	getline(cin, data.name);
	gotoxy(58, 20);
	cout << "Birth:";
	getline(cin, data.Birth);
	gotoxy(58, 21);
	cout << "Sex:";
	getline(cin, data.sex);
	gotoxy(58, 22);
	cout << "IDsocial:";
	getline(cin, data.IDsocial);
	return data;
}

int CheckRowInFile(string filename)
{
	fstream f;
	f.open(filename, ios::in);
	int count = -1;
	string name;
	while (!f.eof())
	{
		getline(f, name);
		count++;
	}
	return count;
}

void CreateNewClass()
{
	string name;
	system("cls");
	drawASCIIMenuView();
	string Year;
	textBgColor(0, 11);
	drawRectangle(35, 12, 60, 12, 11);
	gotoxy(43, 12);
	cout << "Enter School Year:";
	drawRectangle(43, 13, 45, 1, 15);
	gotoxy(43, 13);
	getline(cin, Year);
	fstream fs;
	fs.open("file_save//year-semester.csv", ios::in);
	bool checkYear = false;
	string tempYear;
	string tempSemester;
	while (!fs.eof())
	{
		getline(fs, tempYear, ',');
		getline(fs, tempSemester);
		if (Year == tempYear)
		{
			checkYear = true;
		}
	}
	if (checkYear == false)
	{
		gotoxy(43, 15);
		cout << "SCHOOL YEAR DON'T EXIST!! PLEASE TRY AGAIN" << endl;
		system("pause");
	}
	if (checkYear == true)
	{
		textBgColor(0, 11);
		gotoxy(43, 14);
		cout << "Enter Name Of Class(CTT,HOH,TTH,SHH): ";
		drawRectangle(43, 15, 45, 1, 15);
		gotoxy(43, 15);
		getline(cin, name);
		string str = { name };
		string CheckNameClass = { str[2] , str[3] , str[4] };
		if (CheckNameClass == "CTT" || CheckNameClass == "HOH"
			|| CheckNameClass == "TTH" || CheckNameClass == "SHH")
		{
			fstream file1;
			bool check = true;
			file1.open("file_save//SchoolYear//" + Year + "//class_info.csv", ios::in);
			string stt, NameClass, major, number, year;
			while (!file1.eof())
			{
				getline(file1, stt, ',');
				getline(file1, NameClass, ',');
				getline(file1, major, ',');
				getline(file1, number, ',');
				file1 >> year;
				if (name == NameClass)
				{
					check = false;
				}
			}
			if (check == false)
			{
				gotoxy(43, 16);
				cout << "CLASS EXIST! PLEASE TRY AGAIN" << endl;
			}
			if (check == true)
			{
				string FileName = "file_save//SchoolYear//" + Year + "//" + name + csv_tail;
				fstream f1;
				f1.open(FileName, ios::out);
				f1 << "No" << "," << "ID" << "," << "Name" << "," << "Birth" << "," << "Sex" << "," << "IDSocial" << endl;
				f1.close();
				string NameMajor;
				textBgColor(0, 11);
				gotoxy(43, 16);
				cout << "Enter Name Of Major: ";
				drawRectangle(43, 17, 45, 1, 15);
				gotoxy(43, 17);
				getline(cin, NameMajor);
				int numberStudent, yearStudent;
				textBgColor(0, 11);
				gotoxy(43, 18);
				cout << "Enter Number Of Student: ";
				drawRectangle(43, 19, 45, 1, 15);
				gotoxy(43, 19);
				cin >> numberStudent;
				textBgColor(0, 11);
				gotoxy(43, 20);
				cout << "Enter Year: ";
				drawRectangle(43, 21, 45, 1, 15);
				gotoxy(43, 21);
				cin >> yearStudent;

				fstream file;
				string filename = "file_save//SchoolYear//" + Year + "//class_info.csv";
				int count = CheckRowInFile(filename);
				file.open("file_save//SchoolYear//" + Year + "//class_info.csv", ios::app);
				file << count << "," << name << "," << NameMajor << "," << numberStudent << "," << yearStudent << endl;
				file.close();
				gotoxy(43, 23);
				cout << "CREATE CLASS SUCCESSFUL,PRESS ENTER TO BACK TO MENU !!!" << endl;
			}
			
		}
		else
		{
			gotoxy(43, 17);
			cout << "Name class is malformed!! Try again" << endl;
			system("pause");
		}
		
	}

}



void drawASCIIMenuView()
{
	textBgColor(0, 6);
	printtext("   ______    __       ____         _____   _____ ", 40, 4);
	printtext("  / ____/   / /      / /\\ \\      / ____/  / ___/ ", 40, 5);
	printtext(" / /       / /      / /__\\ \\     \\ \\      \\ \\    ", 40, 6);
	printtext("/ /___    / /____  / /____\\ \\   __\\ \\    __\\ \\   ", 40, 7);
	printtext("\\____/   /______/ /_/      \\_\\ /____/   /____/   ", 40, 8);
	printtext("                                                 ", 40, 9);
}
int RunMenuViewListClass()
{
	char ch;
	int command;
	
	while (true)
	{
		showPointer();
		system("cls");
		gotoxy(40, 12);
		string MenuView[] = { "0. Create New Class",
			"1. View List Classes",
			"2. Exit" };
		drawMenu(MenuView, 3, 55, 12, 0, &drawASCIIMenuView);
		command = MoveAndChoose(3, MenuView, 55, 12, 0);
		switch (command)
		{
		case 0:
		{
			system("cls");
			CreateNewClass();
			system("cls");
			break;
		}
		case 1:
		{
			SchoolYear SY;
			determineYearSemesterNow(SY.year, SY.semester.Name);
			system("cls");
			listClass(SY, &showStudentInclass);
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



