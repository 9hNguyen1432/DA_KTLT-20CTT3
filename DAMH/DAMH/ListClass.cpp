#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <fstream>
#include"ConsoleProcess.h"
#include "Course_function.h"
#include "staffFunction.h"
#include "windows.h"
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
	fstream fs;
	fs.open("file_save//year-semester.csv", ios::in);
	string tempYear;
	string tempSemester;
	while (!fs.eof())
	{
		getline(fs, tempYear, ',');
		getline(fs, tempSemester);
		Year = tempYear;
	}
	{
		cin.ignore();
		textBgColor(0, 11);
		gotoxy(43, 14);
		cout << "Enter Name Of Class(CTT,HOH,TTH,SHH):";
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
				gotoxy(43, 17);
				cout << "CLASS EXIST! PLEASE TRY AGAIN" << endl;
				Sleep(1000);
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
				int numberStudent;
				textBgColor(0, 11);
				gotoxy(43, 18);
				cout << "Enter Number Of Student: ";
				drawRectangle(43, 19, 45, 1, 15);
				gotoxy(43, 19);
				cin >> numberStudent;
				string str = { Year };
				string yearStudent = { Year[0],Year[1],Year[2],Year[3] };

				fstream file;
				string filename = "file_save//SchoolYear//" + Year + "//class_info.csv";
				int count = CheckRowInFile(filename);
				file.open("file_save//SchoolYear//" + Year + "//class_info.csv", ios::app);
				file << count << "," << name << "," << NameMajor << "," << numberStudent << "," << yearStudent << endl;
				file.close();

				gotoxy(43, 22);
				cout << "CREATE CLASS SUCCESSFUL!!!" << endl;
				Sleep(1000);
			}

		}
		else
		{
			gotoxy(43, 17);
			cout << "Name class is malformed!! Try again" << endl;
			Sleep(1000);
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


void ImportRandom(string& YearCourse, string& Class)
{
	fstream ofs, ifs;
	string NameClass = "file_save//SchoolYear//" + YearCourse + "//" + Class + csv_tail;
	ofs.open(NameClass, ios::app);
	ifs.open("file_save//InforNewStudent.csv", ios::in);
	string  NameSt, BirthSt, SexSt, IdSocialSt;
	int count = CheckRowInFile(NameClass);
	int IDSt;
	string CheckYear = { YearCourse };
	string CheckNameYear = { CheckYear[2] , CheckYear[3] };
	int MasoNam;
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
			IDSt = MasoNam + 170000;
		}
		if (CheckSTTClass == "2")
		{
			IDSt = MasoNam + 170100;
		}
		if (CheckSTTClass == "3")
		{
			IDSt = MasoNam + 170200;
		}
		if (CheckSTTClass == "4")
		{
			IDSt = MasoNam + 170300;
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
	string NumberOfStudent;
	fstream file2;
	file2.open("file_save//SchoolYear//" + YearCourse + "//class_info.csv", ios::in);
	string stt2, NameClass2, major2, number2, year2;
	while (!file2.eof())
	{
		getline(file2, stt2, ',');
		getline(file2, NameClass2, ',');
		getline(file2, major2, ',');
		getline(file2, number2, ',');
		file2 >> year2;
		if (Class == NameClass2)
		{
			NumberOfStudent = number2;
		}
	}
	int CheckNumberOfStudent = atoi(NumberOfStudent.c_str());
	while (count != (CheckNumberOfStudent + 1))
	{
		fstream finput;
		finput.open("file_save//login_info.csv", ios::app);
		int MSSV = IDSt + count;
		ofs << count << ",";
		ofs << MSSV << ",";
		finput << endl << MSSV << "," << MSSV << "," << "1" << "," << Class;
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
	int countFile = CheckRowInFile("file_save//InforNewStudent.csv");
	string arr[10000];
	fstream f1;
	f1.open("file_save//InforNewStudent.csv", ios::in);
	
	while (!f1.eof())
	{
		for (int i = 1; i <= countFile; i++)
		{
			getline(f1, arr[i]);
		}
	}
	f1.close();
	fstream f2;
	f2.open("file_save//InforNewStudent.csv", ios::out);
	for (int i = CheckNumberOfStudent+1; i <= 450; i++)
	{
		f2 << arr[i] << endl;
	}
	f2.close();
}

void CreateAutoClassAndImportRandomInfo()
{
	string name;
	system("cls");
	drawASCIIMenuView();
	string Year;
	textBgColor(0, 11);
	drawRectangle(35, 12, 60, 12, 11);
	fstream fs;
	fs.open("file_save//year-semester.csv", ios::in);
	string tempYear;
	string tempSemester;
	while (!fs.eof())
	{
		getline(fs, tempYear, ',');
		getline(fs, tempSemester);
		Year = tempYear;
	}
	{
		cin.ignore();
		textBgColor(0, 11);
		gotoxy(43, 13);
		cout << "Enter Name Abbreviations Of Class(CTT,HOH,TTH,SHH): ";
		drawRectangle(43, 14, 45, 1, 15);
		gotoxy(43, 14);
		getline(cin, name);

		if (name == "CTT" || name == "HOH"
			|| name == "TTH" || name == "SHH")
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
				string NameMajor;
				textBgColor(0, 11);
				gotoxy(43, 15);
				cout << "Enter Name Of Major: ";
				drawRectangle(43, 16, 45, 1, 15);
				gotoxy(43, 16);
				getline(cin, NameMajor);
				int numberStudent;
				textBgColor(0, 11);
				gotoxy(43, 17);
				cout << "Enter Number Of Student: ";
				drawRectangle(43, 18, 45, 1, 15);
				gotoxy(43, 18);
				cin >> numberStudent;

				int NumberOfClass;
				textBgColor(0, 11);
				gotoxy(43, 19);
				cout << "Enter Number Of Class(Max = 4): ";
				drawRectangle(43, 20, 45, 1, 15);
				gotoxy(43, 20);
				cin >> NumberOfClass;
				if (NumberOfClass <= 4)
				{
					string str = { Year };
					string YearStudent = { Year[0],Year[1],Year[2],Year[3] };

					fstream file;
					string filename = "file_save//SchoolYear//" + Year + "//class_info.csv";
					string CheckYear = { Year[2], Year[3] };
					for (int i = 1; i <= NumberOfClass; i++)
					{
						string s = to_string(i);
						string NameClasses = CheckYear + name + s;
						string FileName = "file_save//SchoolYear//" + Year + "//" + NameClasses + csv_tail;
						fstream f1;
						f1.open(FileName, ios::out);
						f1 << "No" << "," << "ID" << "," << "Name" << "," << "Birth" << "," << "Sex" << "," << "IDSocial" << endl;
						f1.close();
						int count = CheckRowInFile(filename);
						file.open("file_save//SchoolYear//" + Year + "//class_info.csv", ios::app);
						file << count << "," << CheckYear << name << i << "," << NameMajor << "," << numberStudent << "," << YearStudent << endl;
						file.close();
						ImportRandom(Year, NameClasses);
					}


					gotoxy(43, 22);
					cout << "CREATE CLASS AND IMPORT RANDOM INFO SUCCESSFUL" << endl;
					Sleep(1000);
				}
				else
				{
					gotoxy(43, 21);
					cout << "Max Number Of Class is 4! Try Again!!!" << endl;
					Sleep(1000);
				}
				
			}

		}
		else
		{
			gotoxy(43, 17);
			cout << "Name abbreviations class is malformed!! Try again" << endl;
			Sleep(1000);
		}

	}
}
int RunMenuCreateClass()
{
	char ch;
	int command;

	while (true)
	{
		showPointer();
		system("cls");
		
		gotoxy(40, 12);
		string MenuView[] = { "1. Create 1 Class",
			"2. Create Auto Classes And Import Info",
			"3. Exit" };
		drawMenu(MenuView, 3, 47, 12, 1, &drawASCIIMenuView);
		command = MoveAndChoose(3, MenuView, 47, 12, 1);
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
			system("cls");
			CreateAutoClassAndImportRandomInfo();
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
