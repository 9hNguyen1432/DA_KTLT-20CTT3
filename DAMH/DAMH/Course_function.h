#ifndef course_h
#define course_h
#include "Menu.h"
typedef void (*drawASCII)();
typedef Course* (*func_Get_course)(User, SchoolYear, int&);
void rewrite_course_of_student_file(User user, string fileName, string data, int command_flag);
//hàm ghi danh vào file khóa học tổng của staff, user là học sinh.
void rewrite_course_file(User user, string fileName, int command_flag);
void enroll_course(User& A, SchoolYear s_y);
void MoveUpMenu(int X, int& Y,int dis);
void MoveDownMenu(int X, int& Y, int dis);
int MoveAndChoose(int a, string A[], int _X, int _Y, int dis);
void drawMenu(string* S, int n, int x, int y, int dis,drawASCII fun);
int getyearData(string* data1, int* data2, string filename);
void change_Year_Semester(SchoolYear&S);
void DisPlay_Course_Of_Student(SchoolYear Y, User A);
void edit_score(User& A, SchoolYear SY, Mark* M);
void DisPlay_Mark_Of_Student(SchoolYear Y, User A);
void edit_score_in_list_course(User& A, SchoolYear SY, string IDcourse);
void delete_course(User& A, SchoolYear s_y);
void viewStudentInCourse(User user, SchoolYear SY);
void Output_info(User A);
void view_1_line(Mark M, int x, int y);
Mark* view_all_score_of_1_student(User A, SchoolYear Y);
void view_1_score_of_course(Mark M, int x, int y);
void view_10_score_of_course(Mark* M, int i, int n, int x, int y);
int view_score_of_course_in_year(Mark* M, int n);
void view_1_course_of_list_course(Course M, int x, int y);
void view_10_course_of_list_course(Course* M, int i, int n, int x, int y);
int view_course_in_year(Course* M, int n, drawASCII fun);
Course* select_course(User A, SchoolYear SY, func_Get_course fun, drawASCII fundraw);
void view_1_student_info_of_course(Data M, int x, int y);
void view_10_student_info_of_course(Data* M, int i, int n, int x, int y);
void view_student_info_of_course(Data* M, int n);
#endif // !course_h

