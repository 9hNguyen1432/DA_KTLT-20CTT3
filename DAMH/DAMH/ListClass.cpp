#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

const string csv_tail = ".csv";

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


string CreateNewClass()
{
	fstream fs, fs1;
	string name;
	cout << "MENU CREATE NEW CLASS" << endl;
	cout << "Please you create name of new class:";
	cin >> name;
	cout << "File has been created !!!";
	string FileName = name + csv_tail;
	fs.open(FileName, ios::out);
	fs1.open("ListClass.csv", ios::out);
	fs1 << FileName << endl;
	fs1.close();
	return FileName;
}
void UpdateInforToNewClass()
{
	fstream ifs, fs;
	ifs.open("infor_student.csv", ios::in);
	fs.open(CreateNewClass(), ios::out);
	Database info;
	int count = 0;
	while (!ifs.eof() && (count != 45))
	{
		string ID;
		getline(ifs, ID, ',');
		info.ID = atoi(ID.c_str());
		if (info.ID == 0) break;
		fs << info.ID << ',';
		getline(ifs, info.name, ',');
		fs << info.name << ',';
		string date, month, year;
		getline(ifs, date, ',');
		info.Birth.Date = atoi(date.c_str());
		fs << info.Birth.Date << ',';
		getline(ifs, month, ',');
		info.Birth.Month = atoi(month.c_str());
		fs << info.Birth.Month << ',';
		getline(ifs, year, ',');
		info.Birth.Year = atoi(year.c_str());
		fs << info.Birth.Year << ',';
		ifs >> info.sex;
		fs << info.sex << endl;
		count += 1;
	}
	ifs.close();
	fs.close();
}

void ViewListClasses()
{
	fstream f;
	cout << "LIST CLASSES" << endl;
	f.open("ListClass.csv", ios::in);
	while (!f.eof())
	{
		string NameClass;
		f >> NameClass;
		cout << NameClass << endl;
	}
	cout << endl;
	f.close();

}

int RunMenuCreate(int Lenh);

int RunMenuView(int Lenh);


int MenuViewListClass()
{

	cout << "======CLASSES======" << endl;
	cout << "1. Create New Class" << endl;
	cout << "2. View List Classes" << endl;
	cout << "3. Exit Menu" << endl;
	cout << "===========================" << endl;
	return 3;
}

int MenuCreate()
{
	system("cls");
	cout << "======CREATE NEW CLASSES======" << endl;
	cout << "0. Return Menu" << endl;
	cout << "1. Create New Classes" << endl;
	cout << "2. Exit Menu" << endl;
	return 2;
}

int MenuView()
{
	system("cls");
	cout << "======VIEW LIST CLASSES======" << endl;
	cout << "0. Return Menu" << endl;
	cout << "1. View List Classes" << endl;
	cout << "2. Exit Menu" << endl;
	return 2;
}

int SelectCommand(int Lenh)
{
	bool check;
	int  n;
	do
	{
		cout << "Please Input Your Command: ";
		cin >> n;
		check = cin.fail();
		if (check == true)
		{
			cin.clear();
			cin.ignore();

		}
	} while (check == true || n > Lenh || n < 0);
	return n;
}

int RunMenuViewListClass(int Lenh)
{
	switch (Lenh)
	{
	case 1:
	{
		system("cls");
		int lenh;
		int check = 0;
		do
		{
			lenh = SelectCommand(MenuCreate());
			check = RunMenuCreate(lenh);
		} while (check != 2);
	};
	case 2:
	{
		system("cls");
		int lenh;
		int check = 0;
		do
		{
			lenh = SelectCommand(MenuView());
			check = RunMenuView(lenh);
		} while (check != 2);
	};
	case 3:
	{
		bool check = true;
		char c;
		do {
			cout << "Press Y to exit: ";
			cin >> c;
			check = cin.fail();
			if (check)
			{
				cin.ignore();
				cin.clear();
			}

		} while (check == true);
		if (c == 'y')
		{
			return 3;
		}
		else
		{
			return 0;
		}
	};
	}
}

int RunMenuCreate(int Lenh)
{
	if (Lenh == 0)
	{
		return 2;

	}
	else if (Lenh == 1)
	{
		system("cls");
		UpdateInforToNewClass();
		system("pause");
	}
	else if (Lenh == 2)
	{
		bool check = true;
		char c;
		do {
			cout << "Press Y to exit: ";
			cin >> c;
			check = cin.fail();
			if (check)
			{
				cin.ignore();
				cin.clear();
			}

		} while (check == true);
		if (c == 'y')
		{
			return 2;
		}
		else
		{
			return -1;
		}
	}
}

int RunMenuView(int Lenh)
{
	if (Lenh == 0)
	{
		return 2;
	}
	else if (Lenh == 1)
	{
		system("cls");
		ViewListClasses();
		system("pause");
	}
	else if (Lenh == 2)
	{
		bool check = true;
		char c;
		do {
			cout << "Press Y to exit: ";
			cin >> c;
			check = cin.fail();
			if (check)
			{
				cin.ignore();
				cin.clear();
			}

		} while (check == true);
		if (c == 'y')
		{
			return 2;
		}
		else
		{
			return -1;
		}
	}
}
