#ifndef course_h
#define course_h
void rewrite_course_of_student_file(User user, string fileName, string data, int command_flag);
//hàm ghi danh vào file khóa học tổng của staff, user là học sinh.
void rewrite_course_file(User user, string fileName, int command_flag);
void enroll_course(User& A, SchoolYear s_y, int command_flag);
#endif // !course_h

