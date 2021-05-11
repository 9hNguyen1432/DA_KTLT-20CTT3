#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//
struct Date {
	int Date;
	int Month;
	int Year;
};
struct Data {
	int IDstd;
	char* name;
	int sex;// 0 là nam, 1 là nữ.
	Date Bir;// ngày sinh
	int IDsocial;
};
//
struct schedule {// thời gian học
	int Date;
	int Month;
	int hour;
	int minute;
};
//
struct MarkNode {
	int ID;// linh hoạt trong điểm của sinh viên thì là id môn học, còn trong môn học thì là id sinh viên
	int Mark;
	MarkNode* pNext;
};
struct Course{
	int ID_course;
	char* name;
	char* teacher;
	int Num_of_creadit;
	int Num_of_std_now;
	int Max_student;
	schedule Schedule;// thời khóa biểu môn học
	MarkNode* pHead;
};
//
struct Mark {
	int IDstd;
	int Num_of_course;
	MarkNode* pHead;
};
//
struct User {
	int ID;
	char* Password;
	int role;// 0 là giáo viên quản trị. 1 là học sinh
	Data info;
};