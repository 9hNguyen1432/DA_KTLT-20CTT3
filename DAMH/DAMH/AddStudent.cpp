#include "ConsoleProcess.h"
#include "Header.h"
#include "AddStudent.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;
const string csv_tail = ".csv";

void AddStudentToClass()
{
	textBgColor(1, 10);
	printtext("   ______    __       ____         _____   _____ ", 40, 2);
	printtext("  / ____/   / /      / /\\ \\      / ____/  / ___/ ", 40, 3);
	printtext(" / /       / /      / /__\\ \\     \\ \\      \\ \\    ", 40, 4);
	printtext("/ /___    / /____  / /____\\ \\   __\\ \\    __\\ \\   ", 40, 5);
	printtext("\\____/   /______/ /_/      \\_\\ /____/   /____/   ", 40, 6);
	printtext("                                                 ", 40, 7);
	textBgColor(0, 15);
	gotoxy(55, 8);
	cout << "=ADD STUDENT TO CLASS=";
	string YearCourse;
	string Class;
	cin.ignore();
	gotoxy(52, 10);
	cout << "Select School Year:";
	getline(cin, YearCourse);
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
		gotoxy(47, 12);
		cout << "Don't Find School Year " << endl;
		system("pause");
	}
	if (check == true)
	{
		char ch;
		gotoxy(56, 12);
		cout << "Select Class:";
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
		if (check1 == false)
		{
			gotoxy(52, 14);
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
			file2.open(ClassSem, ios::app);
			file2 << "0" << "," << data.ID << "," << data.name << "," << data.Birth << "," << data.sex << "," << data.IDsocial << endl;
			file2.close();

		}
	}
}

void AddRandomInfoStudentToClass()
{
	textBgColor(1, 10);
	printtext("   ______    __       ____         _____   _____ ", 40, 4);
	printtext("  / ____/   / /      / /\\ \\      / ____/  / ___/ ", 40, 5);
	printtext(" / /       / /      / /__\\ \\     \\ \\      \\ \\    ", 40, 6);
	printtext("/ /___    / /____  / /____\\ \\   __\\ \\    __\\ \\   ", 40, 7);
	printtext("\\____/   /______/ /_/      \\_\\ /____/   /____/   ", 40, 8);
	printtext("                                                 ", 40, 9);
	textBgColor(5, 15);
	string YearCourse;
	string Class;
	cin.ignore();
	gotoxy(52, 10);
	cout << "Select School Year:";
	getline(cin, YearCourse);
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
		gotoxy(47, 12);
		cout << "Don't Find School Year" << endl;
		system("pause");
	}
	if (check == true)
	{
		gotoxy(56, 12);
		cout << "Select Class:";
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
		if (check1 == false)
		{
			gotoxy(56, 14);
			cout << "Don't Find Class" << endl;
			system("pause");
		}
		else
		{
			gotoxy(40, 14);
			cout << "Random Information Student Has Been Imported To Class" << endl;
			fstream ofs, ifs;
			string NameClass = "file_save//SchoolYear//" + YearCourse + "//" + Class + csv_tail;
			ofs.open(NameClass, ios::app);
			ifs.open("file_save//InforNewStudent.csv", ios::in);
			Database info;
			int count = 0;
			while (!ifs.eof() && (count != 30))
			{
				getline(ifs, info.No, ',');
				ofs << info.No << ',';
				getline(ifs, info.ID, ',');
				ofs << info.ID << ',';
				getline(ifs, info.name, ',');
				ofs << info.name << ',';
				getline(ifs, info.Birth, ',');
				ofs << info.Birth << ",";
				getline(ifs, info.sex, ',');
				ofs << info.sex << ',';
				ifs >> info.IDsocial;
				ofs << info.IDsocial;
				count += 1;
			}
			ifs.close();
			ofs.close();
		}
	}
}

void MenuAddInfoStudentToClass()
{
	textBgColor(1, 10);
	printtext("   ______    __       ____         _____   _____ ", 40, 4);
	printtext("  / ____/   / /      / /\\ \\      / ____/  / ___/ ", 40, 5);
	printtext(" / /       / /      / /__\\ \\     \\ \\      \\ \\    ", 40, 6);
	printtext("/ /___    / /____  / /____\\ \\   __\\ \\    __\\ \\   ", 40, 7);
	printtext("\\____/   /______/ /_/      \\_\\ /____/   /____/   ", 40, 8);
	printtext("                                                 ", 40, 9);
	textBgColor(5, 15);
	gotoxy(40, 12);
	cout << "1. Add One Student To Class" << endl;
	gotoxy(40, 14);
	cout << "2. Import Info Student From File To Class" << endl;
	gotoxy(40, 16);
	cout << "3. Exit" << endl;
}

int RunMenuAddInfoStudentToClass()
{
	char ch;
	while (true)
	{

		int command;
		MenuAddInfoStudentToClass();
		gotoxy(40, 18);
		cout << "Please Select Your Command: ";
		cin >> command;
		switch (command)
		{
		case 1:
		{
			system("cls");
			AddStudentToClass();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			AddRandomInfoStudentToClass();
			system("pause");
			system("cls");
			break;
		}
		case 3:
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