#ifndef readdata_h
#define readdata_h

#include"staffFunction.h"
#include"ConsoleProcess.h"
#include "Header.h"
using namespace std;
typedef Course* (*func_Get_course)(User, SchoolYear, int&);
typedef void (*drawASCII)();
const string csv_tail = ".csv";
const string txt_tail = ".txt";
void read_1_info(User& A, ifstream &f);
void read_info(User& A, SchoolYear SY);
void Output_info(User A);
void read_course(User A,SchoolYear y);
void read1CourseInfor(Course& A, ifstream& f);
void init_List_Mark(MarkNode*& head);
void add_Tail_List_Mark(MarkNode*& head, string ID,string Name, string num_of_creadit);
int get_course(User& A, SchoolYear s_y, int flag=0);
void Back_A_Semester(SchoolYear& S);
void get_all_course(User& A, SchoolYear SY);
void delete_Mark_node(MarkNode*& head, string ID);
void get_1_score(MarkNode*& A, string ID, ifstream& f);
void get_score(User& A, SchoolYear s_y, int& i);
void view_1_line(Mark M, int x, int y);
Mark* view_all_score_of_1_student(User A, SchoolYear Y);
void insertMark(string& data, int limit, int& flag);
void save_Mark(User& A, Mark* B, int i, SchoolYear SY);
Mark* read_file_score_of_course(SchoolYear SY, string IDcourse, int& n);
void view_1_score_of_course(Mark M, int x, int y);
void view_10_score_of_course(Mark* M, int i, int n, int x, int y);
int view_score_of_course_in_year(Mark*M, int n);
void save_Mark_With_List_Cousre(string IDcourse, Mark B, SchoolYear SY);
void view_1_course_of_list_course(Course M, int x, int y);
void view_10_course_of_list_course(Course* M, int i, int n, int x, int y);
Course* read_file_List_course(User A, SchoolYear SY, int& n);
int view_course_in_year(Course* M, int n, drawASCII fun);
Course* select_course(User A, SchoolYear SY, func_Get_course fun, drawASCII fundraw);
void drawASCIIlistCourse();
void drawASCIIenrolCourse();
void drawASCIIsuccessful();
void drawASCIIfailEnrol();
void drawASCIIdeleteCourse();
void drawASCIIStaffMenu();
void drawASCIIchangeYear();
void drawASCIIeditscore();
void drawASCIIchangeSemester();
void drawASCIImenuStudent();
Course* get_course_of_student(User A, SchoolYear SY, int& n);
Data* read_file_student_info_of_course(SchoolYear SY, string IDcourse, int& n);
void view_1_student_info_of_course(Data M, int x, int y);
void view_10_student_info_of_course(Data* M, int i, int n, int x, int y);
void view_student_info_of_course(Data* M, int n);
#endif
