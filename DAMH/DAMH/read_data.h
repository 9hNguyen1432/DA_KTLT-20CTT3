#ifndef readdata_h
#define readdata_h
const string csv_tail = ".csv";
const string txt_tail = ".txt";
void read_1_info(User& A, ifstream &f);
void read_info(User& A);
void Output_info(User A);
void init_List_Mark(MarkNode*& head);
void add_Tail_List_Mark(MarkNode*& head, string A);
void read_course(User& A);
#endif
