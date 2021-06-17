#ifndef HEADERFILE_H
#define HEADERFILE_H
#include <iostream>
#include "windows.h"
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*
	Color:
		0 black
		1 blue
		2 green
		3 aqua
		4 red
		5 purple
		6 yellow
		7 white
		8 gray
		9 light blue
		10 light green
		11 light aqua
		12 light red
		13 light purple
		14 light yellow
		15 bright white
*/
// struct điểm 1 môn của 1 sinh viên
struct Mark {
	string ID;// linh hoạt trong điểm của sinh viên thì là id môn học, còn trong môn học thì là id sinh viên
	string Name;
	float Total_Mark;
	float Final_Mark;
	float Midterm_Mark;
	float Other_Mark;
};
struct MarkNode {
	Mark data;
	MarkNode* pNext;
};
//struct thông tin học sinh hoặc giáo viên, nếu là giáo viên thì 1 số thông tin bỏ trống
struct Data {
	int NO_inclass;
	string IDstd;
	string name;
	string sex;// 0 là nam, 1 là nữ.
	string Bir;// ngày sinh
	string IDsocial;
	string Class;
	MarkNode* phead;// nhiều môn
};
//
// struct 1 khóa học, 1 số thông tin có thể trống
struct Course {
	string ID_course;
	string name;
	string teacher;
	int Num_of_creadit;
	int Max_student;
	string Schedule;// thời khóa biểu môn học
	string session[2];//thời gian mỗi tiết học (mỗi môn đều có 2 tiết)
	string DayOfWeek;
	MarkNode* pHead;
};

struct Class {
	string name;
	string MajorClass;
	int Num_of_std_now;
	int Year;//Năm vào trường
};

struct Semester {
	string Name;
	int Num_of_std_now;
	string schoolyear;
	string date_star;
	string date_end;
	Course Course;
	Class Class;
};

struct SchoolYear {
	Semester semester;
	string year;//VD:2020-2021
	int Num_of_std_now;
	string date_star;
	string date_end;
};

//
struct User {
	string ID;
	string Password;
	int role;// 0 là giáo viên quản trị. 1 là học sinh
	Data info;
};

#endif