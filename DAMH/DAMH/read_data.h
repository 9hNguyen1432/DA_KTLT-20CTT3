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
void add_Tail_List_Mark(MarkNode*& head, string A);
void get_course(User& A, SchoolYear s_y);
void delete_Mark_node(MarkNode*& head, string ID);
#endif
