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

void CopyContentFileToFile(string src_path, string des_path);

void addSchoolYear(SchoolYear& Y);

int insertSchoolYear(string& SchoolYear);

int insertDate(string& Date);

int insertNameSemester(string& name);

void addSemester(string& yearNow, string& semesterNow);

int checkSchoolYear(Semester semester);

void UpDatefileInfo(Semester semester);

void UpDatefileCSV(Semester semester);

void createRegistrationCourse();

int checkDate(string Date);

void determineYearSemesterNow(string& Year, string& semester);

void addCourse();

int insertNum(int& n);

int countLine(string filename);

void moveUp(string filename, int& currentLine, int columnNum, int indexB[], int y, string column[], int lineInConsole, int width, int x);

void moveDown(string filename, int& currentLine, int columnNum, int indexB[], int y, string column[], int lineInConsole, int width, int x);

void drawList(int columnNum, string filename, int y, int indexA[], int indexB[], int line, int flagLine);

void listCourse(string year, string semester);

void getLineInfo(string filename, int line, string column[], int columnNum);

void updateFileCourse(int currentColumn, int currentLine, string column[], string year, string semester);

void editInforCourse(int y, int currentLine, string column[], string year, string semester);

int insertSession(string& data, int limit);

int insertDay(string& data, int limit);

int insertNum2(string& data, int limit);

int insertString(string& data, int limit);

void editCourse(string year, string semester);

void deleteCourse(string filename, string courseName, int currentLine, string year, string semester);

void viewCourse();

bool checkTimeEnd(string date, string month, string year);

bool checkTimeStart(string date, string month, string year);

int checkCourseSession();

void exportScoreboardInterface(string year, string semester, int flagLine, int currentLine, int lineInConsole);

void exportSB(string SchoolYear, string Semester, string CourseID);

void importScoreBoard(string year, string semester, string courseID);

void importScoreBoardUI();

void listClass(SchoolYear Y);

void showStudentInclass(SchoolYear Y, string classname);

void drawListStudent(int columnNum, SchoolYear Y, string filename, int y, int indexA[], int indexB[], int line, int columnNotNeed, int flagLine);

void getLineInfoForStudent(string filename, SchoolYear Y, int line, string column[], int columnNum);

void get_all_course_student(User& B, SchoolYear SY, float& overallGPA);

void showScoreOfClass(SchoolYear Y, string classname);

void listClassUseFor14(SchoolYear Y);

void showScoreOfClassPreventive(SchoolYear Y, string classname);

void deleteFile(string filename);

void renameFile(string oldName, string newName);