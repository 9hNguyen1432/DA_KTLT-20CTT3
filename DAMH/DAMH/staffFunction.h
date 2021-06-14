#pragma once
#pragma warning(disable : 4996)
#include"Header.h"
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include <direct.h>
#include<stdio.h> 
#include<conio.h> 
#include <sys/stat.h>
#include <ctime>
using namespace std;

void createFolder(string namefolder);

void addSchoolYear();

void insertSchoolYear(string& SchoolYear);

void insertDate(string& Date);

void insertNameSemester(string& name);

void addSemester();

int checkSchoolYear(Semester semester);

void UpDatefileInfo(Semester semester);

void UpDatefileCSV(Semester semester);

void createRegistrationCourse();

int checkDate(string Date);

void determineYearSemesterNow(string& Year, string& semester);

void addCourse();

void insertNum(int& n);

int countLine(string filename);

void listCourse();

void getLineInfo(string filename, int line, string column[]);

void updateFileCourse(int currentColumn,int currentLine, string column[]);

void editInforCourse(int y, int currentLine, string column[]);

void insertSession(string& data, int limit);

void insertDay(string& data, int limit);

void insertNum2(string& data, int limit);

void insertString(string& data, int limit);

void deleteCourse(string filename, int currentLine);

void viewCourse();

bool checkTimeEnd(string date, string month, string year);

bool checkTimeStart(string date, string month, string year);

bool checkCourseSession();

void exportScoreboardInterface();

void exportSB(string SchoolYear, string Semester, string CourseID);