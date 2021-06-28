#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <fstream>
#include"ConsoleProcess.h"
#include "Course_function.h"

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

Database Imput()
{
	Database data;
	cin.ignore();
	cout << "Imput MSSV:";
	getline(cin, data.ID);
	cout << "Imput Name:";
	getline(cin, data.name);
	cout << "Imput Birth:";
	getline(cin, data.Birth);
	cout << "Imput Sex:";
	getline(cin, data.sex);
	cout << "Imput IDsocial:";
	getline(cin, data.IDsocial);
	return data;
}

void CreateNewClass()
{
	string name;
	system("cls");
	gotoxy(40, 10);
	cout << "Enter Name Of Class(Ex:20CTT1,..): ";
	gotoxy(40, 11);
	cin.ignore();
	getline(cin, name);
	fstream file1;
	bool check = true;
	file1.open("file_save//SchoolYear//2020-2021//ListClassOfYear.csv", ios::in);
	string NameClass;
	while (!file1.eof())
	{
		getline(file1, NameClass);
		if (name == NameClass)
		{
			check = false;
		}
	}
	if (check == false)
	{
		gotoxy(40, 15);
		cout << "CLASS EXIT! PLEASE TRY AGAIN" << endl;
	}
	if (check == true)
	{
		gotoxy(40, 15);
		string FileName = "file_save//SchoolYear//2020-2021//" + name + csv_tail;
		fstream f1;
		f1.open(FileName, ios::out);
		f1 << "No" << "," << "ID" << "," << "Name" << "," << "Birth" << "," << "Sex" << "," << "IDSocial" << endl;
		f1.close();
		fstream file;
		file.open("file_save//SchoolYear//2020-2021//ListClassOfYear.csv", ios::app);
		file << name << endl;
		file.close();
		cout << "CREATE CLASS SUCCESSFUL,PRESS ENTER TO BACK TO MENU !!!" << endl;
	}

}

void AddStudentToClass()
{
	Database data;
	data = Imput();
	string YearCourse;
	string Class;
	gotoxy(40, 15);
	cout << "\nImput YearCourse:";
	getline(cin, YearCourse);
	cout << YearCourse << endl;
	fstream file;
	file.open("file_save//year.csv", ios::in);
	string Year;
	bool check = false;
	while (!file.eof())
	{
		getline(file, Year);
		if (YearCourse == Year)
		{
			check = true;
		}
	}
	if (check == false)
	{
		gotoxy(40, 17);
		cout << "Don't Find Year Semester" << endl;
		system("pause");
	}
	if (check == true)
	{
		gotoxy(40, 18);
		cout << "\nImput Class:";
		getline(cin, Class);
		string yearSem = "file_save//SchoolYear//" + YearCourse + "//ListClassOfYear.csv";
		fstream file1;
		string Cla;
		bool check1 = false;
		file1.open(yearSem, ios::in);
		while (!file1.eof())
		{
			getline(file1, Cla);
			if (Class == Cla)
			{
				check1 = true;
			}
		}
		if (check1 = false)
		{ 
			gotoxy(40, 20);
			cout << "Don't Find Class" << endl;
			system("pause");
		}
		else
		{
			string ClassSem = "file_save//SchoolYear//" + YearCourse + "//" + Class + csv_tail;
			fstream file2;
			file2.open(ClassSem, ios::app);
			file2 << "0" << "," << data.ID << "," << data.name << "," << data.Birth << "," << data.sex << "," << data.IDsocial << endl;
			file2.close();
		}
	}
}
	


void ViewListClasses()
{
	fstream f;
	string selection;
	gotoxy(20, 6);
	cin.ignore();
	cout << "Please Imput Your Selection (Year Semester): ";
	getline(cin, selection);
	fstream file;
	string year;
	bool check = false;
	file.open("file_save//year.csv", ios::in);
	while (!file.eof())
	{
		getline(file, year);
		if (selection == year)
		{
			check = true;
		}
	}
	if (check == false)
	{
		gotoxy(25, 15);
		cout << "Your Selection Is Fail" << endl;
	}
	else
	{
		gotoxy(25, 15);
		cout << "===== LIST CLASSES IN " << selection << " =======" << endl;
		f.open("file_save//SchoolYear//" + selection + "//ListClassOfYear.csv", ios::in);
		int i = 16;
		while (!f.eof())
		{
			string NameClass;
			f >> NameClass;
			gotoxy(25, i);
			cout << NameClass << endl;
			i++;
		}
		cout << endl;
		f.close();
	}
}

int MenuViewListClass()
{
	gotoxy(20, 10);
	cout << "======CLASSES======" << endl;
	gotoxy(20, 11);
	cout << "1. Create New Class" << endl;
	gotoxy(20, 12);
	cout << "2. View List Classes In Year Semester" << endl;
	gotoxy(20, 13);
	cout << "3. Exit Menu" << endl;
	gotoxy(20, 14);
	cout << "===========================" << endl;
	return 3;
}



int RunMenuViewListClass()
{
	while (true)
	{

		int command;
		MenuViewListClass();
		gotoxy(20, 15);
		cout << "Please Input Your Command: ";
		cin >> command;
		switch (command)
		{
			case 1:
			{
				system("cls");
				CreateNewClass();
				system("pause");
				system("cls");
				break;
			}
			case 2:
			{
				system("cls");
				ViewListClasses();
				system("pause");
				system("cls");
				break;
			}
			case 3: return 0; break;
		}
	}
}



