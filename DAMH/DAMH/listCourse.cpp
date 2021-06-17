#include"ListClass.h"
#include"Header.h"
#include"ConsoleProcess.h"
void viewCourse(SchoolYear y)
{
	ifstream f1;
	string link, temp;
	//need year & semester to make a proper link
	link = "file_save/SchoolYear/"+"/TotalCourse.csv";//a temp link
	f1.open(link, ios::in);
	int i = 1;
	if (f1.is_open() == false)
	{
		std::cout << "reading file error!!!\n";
		return;
	}

	printtext("ID", 8, 9);
	printtext("Course name", 20, 9);
	printtext("Number of credit", 40, 9);
	printtext("Max student", 60, 9);
	printtext("Day", 75, 9);
	printtext("Session 1", 80, 9);
	printtext("Session 2", 90, 9);
	getline(f1, temp);
	while (!f1.eof())
	{
		gotoxy(1, 9+i); std::cout << i;
		getline(f1, temp, ',');
		printtext(temp, 8, 9 + i);
		getline(f1, temp, ',');
		printtext(temp,20,9+i);
		getline(f1, temp, ',');
		printtext(temp, 40, 9 + 1);
		getline(f1, temp, ',');
		printtext(temp, 60, 9 + 1);
		getline(f1, temp, ',');
		printtext(temp, 75, 9 + i);
		getline(f1, temp, ',');
		printtext(temp, 80, 9 + i);
		getline(f1, temp, ',');
		printtext(temp, 90, 9 + i);
		i++;
	}
}