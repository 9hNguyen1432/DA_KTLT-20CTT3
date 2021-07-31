#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "staffFunction.h"

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
int RunMenuViewListClass(User user);
void AddRandomInfoStudentToClass();
int CheckRowInFile(string filename);
void drawASCIIMenuView();
