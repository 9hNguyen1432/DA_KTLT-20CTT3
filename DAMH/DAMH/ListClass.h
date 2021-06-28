#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

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
void AddStudentToClass();
void CreateNewClass();
void ViewListClasses();
int MenuViewListClass();
int RunMenuViewListClass();


