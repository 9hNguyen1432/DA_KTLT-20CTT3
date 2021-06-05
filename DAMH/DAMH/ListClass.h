#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;
//
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


void openFileToInput(const char* filename, fstream& fs);
void openFileToOutput(const char* filename, fstream& fs);
void ReturnClass(fstream& f, Data& info, fstream& ofs);
void ListClass();

