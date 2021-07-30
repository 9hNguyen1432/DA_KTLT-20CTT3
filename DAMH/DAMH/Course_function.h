#ifndef course_h
#define course_h
typedef void (*drawASCII)();
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
void viewStudentInCourse(SchoolYear SY);
#endif // !course_h

