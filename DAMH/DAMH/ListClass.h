#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

struct Database {
	string No;
	string ID;
	string name;
	string Birth;
	string sex;
	string IDsocial;
};
Database Imput();
void AddStudentToClass();
void CreateNewClass();
void ViewListClasses();
void MenuViewListClass();
int RunMenuViewListClass();
void AddRandomInfoStudentToClass();
int CheckRowInFile(string filename);

