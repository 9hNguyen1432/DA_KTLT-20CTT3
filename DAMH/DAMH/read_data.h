#ifndef readdata_h
#define readdata_h
const string csv_tail = ".csv";
const string txt_tail = ".txt";
void read_1_info(User& A, ifstream &f);
void read_info(User& A);
void Output_info(User A);
void read_course(User& A,MarkNode* &view);
void read1CourseInfor(Course& A, ifstream& f);
#endif
