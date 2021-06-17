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
string CreateNewClass();
void UpdateInforToNewClass();
void ViewListClasses();
int RunMenuCreate(int Lenh);
int RunMenuView(int Lenh);
int MenuViewListClass();
int MenuCreate();
int MenuView();
int SelectCommand(int Lenh);
int RunMenuViewListClass(int Lenh);


