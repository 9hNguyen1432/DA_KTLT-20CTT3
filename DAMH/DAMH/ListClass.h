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
void CreateNewClass();
int RunMenuCreateClass();
int CheckRowInFile(string filename);
void drawASCIIMenuView();
void CreateAutoClassAndImportRandomInfo();
void ImportRandom(string& YearCourse, string& Class);