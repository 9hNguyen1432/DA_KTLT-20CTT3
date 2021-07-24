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
	cout << "Enter School Year:";
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
		gotoxy(47, 12);
		cout << "Don't Find School Year " << endl;
		system("pause");
	}
	if (check == true)
	{
		char ch;
		gotoxy(52, 12);
		cout << "Enter Name Of Class:";
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
			int count = CheckRowInFile(ClassSem);
			file2.open(ClassSem, ios::app);
			file2 << count << "," << data.ID << "," << data.name << "," << data.Birth << "," << data.sex << "," << data.IDsocial << endl;
			file2.close();
			fstream file3;
			file3.open("file_save//login_info.cvs", ios::app);
			file3 << data.ID << "," << data.ID << "," << "1" << "," << Class << endl;
			file3.close();

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
	cout << "Enter School Year:";
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
		gotoxy(47, 12);
		cout << "Don't Find School Year" << endl;
		system("pause");
	}
	if (check == true)
	{
		gotoxy(52, 12);
		cout << "Enter Name Of Class:";
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