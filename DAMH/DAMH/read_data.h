#ifndef readdata_h
#define readdata_h
const string csv_tail = ".csv";
const string txt_tail = ".txt";
void read_1_info(User& A, ifstream &f);
void read_info(User& A, SchoolYear SY);
void Output_info(User A);
void read_course(User A,SchoolYear y);
void read1CourseInfor(Course& A, ifstream& f);
void init_List_Mark(MarkNode*& head);
void add_Tail_List_Mark(MarkNode*& head, string ID,string Name);
void get_course(User& A, SchoolYear s_y);
void delete_Mark_node(MarkNode*& head, string ID);
void get_1_score(MarkNode*& A, string ID, ifstream& f);
void get_score(User& A, SchoolYear s_y, int& i);
void view_1_line(Mark M, int x, int y);
Mark* view_all_score_of_1_student(User A, SchoolYear Y);
void insertMark(string& data, int limit, int& flag);
void edit_score(User& A, SchoolYear SY, int line, Mark* M);
#endif
