#include <string>
#include "read_data.h"


void read_1_info(User& A, ifstream &f) {
	string NO_temp;
	getline(f, NO_temp, ',');
	A.info.NO_inclass =	stoi(NO_temp);
	getline(f, A.info.IDstd, ',');// giáo viên thì sẽ là id đăng nhập
	getline(f, A.info.name, ',');
	getline(f, A.info.Bir, ',');
	getline(f, A.info.sex, ',');
	getline(f, A.info.IDsocial);
	A.info.phead = NULL;
}
//
void read_info(User& A,SchoolYear SY) {
	string year_path = "file_save/SchoolYear/" + SY.year + '/';
	string fileName;
	if (A.role == 1) {
		fileName = year_path+A.info.Class + csv_tail;
	}
	else {
		fileName = year_path + "staff.csv";
	}
	ifstream info_file;
	info_file.open(fileName, ios::in);
	string temp;
	getline(info_file, temp);
	while (info_file.eof() == false) {
		read_1_info(A, info_file);
		if (A.ID.compare(A.info.IDstd) == 0) {
			break;
		}
		else {
			continue;
		}
	}
	info_file.close();
}
void Output_info(User A) {
	system("cls");
	printtext(" _            ___                                     _               ", 20, 2);
	printtext("(_)          / __)                               _   (_)              ", 20, 3);
	printtext(" _  ____   _| |__   ___    ____  ____   _____  _| |_  _   ___   ____  ", 20, 4);
	printtext("| ||  _  \\(_   __) / _ \\  / ___)|    \\ (____ |(_   _)| | / _ \\ |  _ \\ ", 20, 5);
	printtext("| || | | |  | |   | |_| || |    | | | |/ ___ |  | |_ | || |_| || | | |", 20, 6);
	printtext("|_||_| |_|  |_|    \\___/ |_|    |_|_|_|\\_____|  \\___)|_| \\___/ |_| |_|", 20, 7);


	int a = 0;
	if (A.role == 1) {
		drawRectangle(30, 12, 50, 16, 11);
		printtext("Ma so sinh vien: " + A.info.IDstd, 35, 15);
		printtext("Lop: " + A.info.Class, 35, 17);
		a = 2;
		printtext("Chuc vu: Hoc sinh", 35, 21 + a);
	}
	else {
		drawRectangle(30, 12, 50, 13, 11);
		printtext("Email : " + A.info.IDstd + "@hcmus.edu.vn", 35, 15);
		printtext("Chuc vu: Admin", 35, 21 + a);
	}
	printtext("Ho va ten: " + A.info.name, 35, 13);
	printtext("Ngay sinh: " + A.info.Bir, 35, 17 + a);
	printtext("Gioi tinh: " + A.info.sex, 35, 19 + a);

	printtext("CMND/CCCD: " + A.info.IDsocial, 35, 23 + a);
	textBgColor(0, 15);
	system("pause");
}

void read_course(User A, SchoolYear y)
{
	system("cls");
	textBgColor(4, 10);
	printtext(".-.  .-. .----. .-. .-..----.     .---.  .----. .-. .-..----.  .----..----.", 20, 4);
	printtext(" \\ \\/ / /  {}  \\| { } || {}  }   /  ___\}/  {}  \\| { } || {}  \}{ {__  | {_  ", 20, 5);
	printtext("  }  {  \\      /| {_} || .-. \\   \\     }\\      /| {_} || .-. \\.-._} }| {__ ", 20, 6);
	printtext("  `--'   `----' `-----'`-' `-'    `---'  `----' `-----'`-' `-'`----' `----'", 20, 7);
	drawRectangle(1, 14, 115, 2, 6);
	gotoxy(1, 15); std::cout << "N.o";
	gotoxy(8, 15); std::cout << "Id course";
	gotoxy(19, 15); std::cout << "Course name";
	gotoxy(45, 15); std::cout << "Lecturer";
	gotoxy(70, 15); std::cout << "Number of credits";
	gotoxy(90, 15); std::cout << "Max student";
	gotoxy(102, 15); std::cout << "Schedule";
	ifstream fi;
	string fileName = "file_save/SchoolYear/" + y.year + "/" + y.semester.Name + "/course_info.csv";
	MarkNode* tempo = new MarkNode;
	tempo = A.info.phead;
	int i = 1;
	while (tempo != NULL)
	{
		string fl;
		Course co;
		fi.open(fileName, ios::in);
		getline(fi, fl);
		while (!fi.eof())
		{
			read1CourseInfor(co, fi);
			if (_strcmpi(co.ID_course.c_str(),tempo->data.ID.c_str()) == 0)
			{
				drawRectangle(1, 15+i, 115, 2, 6);
				gotoxy(1, 15 + i); std::cout << i;
				gotoxy(8, 15 + i); std::cout << co.ID_course;
				gotoxy(19, 15 + i); std::cout << co.name;
				gotoxy(45, 15 + i); std::cout << co.teacher;
				gotoxy(78, 15 + i); std::cout << co.Num_of_creadit;
				gotoxy(94, 15 + i); std::cout << co.Max_student;
				gotoxy(102, 15 + i); std::cout << co.Schedule;
				i++;
				tempo = tempo->pNext;
				break;
			}
		}
		fi.close();
		textBgColor(0, 15);
	}
}

void read1CourseInfor(Course& A, ifstream& f)
{
	string flag;
	getline(f, A.ID_course, ',');
	getline(f, A.name, ',');
	getline(f, A.teacher, ',');
	getline(f, flag, ',');
	A.Num_of_creadit= stoi(flag, 0, 10);
	getline(f, flag, ',');
	A.Max_student = stoi(flag, 0, 10);
	getline(f, A.DayOfWeek, ',');
	getline(f, A.session[0], ',');
	getline(f, A.session[1]);
	A.Schedule = A.session[0] + ';' + A.session[1] + '-' + A.DayOfWeek;
}
void init_List_Mark(MarkNode*& head) {
	head = NULL;
}
void add_Tail_List_Mark(MarkNode*& head, string ID , string name, string num_of_creadit) {
	//khởi tạo 1 node
	MarkNode* n1 = new MarkNode;
	n1->data.ID = ID;
	n1->data.Name = name;
	n1->data.C = num_of_creadit;
	n1->data.Midterm_Mark = 0;
	n1->data.Final_Mark = 0;
	n1->data.Other_Mark = 0;
	n1->data.Total_Mark = 0;
	n1->pNext = NULL;
	MarkNode* temp = head;
	if (head == NULL) {
		head = n1;
		return;
	}
	else {
		while (temp->pNext != NULL) {
			temp = temp->pNext;
		}
		temp->pNext = n1;
	}
}
//bool checkCourseInSemester(User A, SchoolYear SY){
//	ifstream f;
//	string semester_path = "file_save/SchoolYear/" + SY.year + '/' + SY.semester.Name + '/';
//	string class_path = semester_path + "Class/";
//	string fileName = class_path + A.info.Class + csv_tail;
//	f.open(fileName, ios::in);
//	if (!f.is_open()) {
//		return true;
//	}
//	while (!f.eof()) {
//		getline(f, temp);
//	}
//
//}
int get_course(User& A, SchoolYear s_y, int flag) {
	ifstream f;
	string semester_path = "file_save/SchoolYear/" + s_y.year + '/' + s_y.semester.Name + '/';
	string class_path = semester_path + "Class/";
	string course_path = semester_path + "Course/";
	string fileName = class_path + A.info.Class + csv_tail;
	bool IDflag = false;
	f.open(fileName, ios::in);
	if (!f.is_open()) {
		drawRectangle(3, 14, 115, 3, 4);
		printtext("Can't open infomation file.", 47, 15);
		textBgColor(0, 15);
		Sleep(1800);
		return -1;
	}
	if (flag == 0) {
		init_List_Mark(A.info.phead);
	}
	while (f.eof() == false) {
		string temp = "";
		string temp1;
		getline(f, temp1);
		string IDtemp = "";
		for (int i = 0; i < temp1.length(); i++) {
			if (temp1[i] == ',' || i == temp1.length() - 1)
			{
				if (IDflag == false) {
					if (i == temp1.length() - 1) {
						IDtemp += temp1[i];
					}
					if (_strcmpi(IDtemp.c_str(), A.info.IDstd.c_str()) != 0) {
						break;
					}
					else {
						if (i == temp1.length() - 1) {
							drawRectangle(3, 14, 115, 3, 4);
							printtext("You have not enrolled any course yet.", 45, 15);
							textBgColor(0, 15);
							Sleep(1800);
							return -1;
						}
					}
					IDflag = true;
				}
				else {
					if (i == temp1.length() - 1) {
						temp += temp1[i];
					}
					ifstream fi;
					string fileName = "file_save/SchoolYear/" + s_y.year + "/" + s_y.semester.Name + "/course_info.csv";
					fi.open(fileName, ios::in);
					string tam;
					string num_of_creadit;
					while (!fi.eof()) {
						getline(fi, tam, ',');
						if (_strcmpi(tam.c_str(), temp.c_str()) == 0) {
							getline(fi, tam, ',');
							getline(fi, num_of_creadit, ',');
							getline(fi, num_of_creadit, ',');
							break;
						}
						else {
							getline(fi, tam);
						}
					}
					add_Tail_List_Mark(A.info.phead, temp, tam, num_of_creadit);
					temp = "";
					fi.close();
				}
			}
			else if (temp1[i] != ',') {
				if (IDflag == false) {
					IDtemp += temp1[i];
				}
				else {
					temp += temp1[i];
				}
			}

		}
		f.close();
	}
	return 0;
}
void Back_A_Semester(SchoolYear& S) {
	if (S.semester.Name.back() == '1' || S.semester.Name.back() == '0') {
		string year = "";
		for (int i = 0; i < 4; i++) {
			year += S.year[i];
		}
		int Y = atoi(year.c_str());
		Y--;
		S.year = to_string(Y) + "-" + year;
		S.semester.Name = "Semester3";
	}
	else {
		if (S.semester.Name.back() == '2') {
			S.semester.Name.pop_back();
			S.semester.Name.push_back('1');
		}
		else if (S.semester.Name.back() == '3') {
			S.semester.Name.pop_back();
			S.semester.Name.push_back('2');
		}
	}
}
void get_all_course(User& A,SchoolYear SY) {
	init_List_Mark(A.info.phead);
	int i = 0;
	int count = 0;
	do {
		i = get_course(A, SY, 1);
		if (i == -1) {
			break;
		}
		get_score(A, SY, count);
		Back_A_Semester(SY);
	} while (i != -1);
}
void delete_Mark_node(MarkNode*& head, string ID) {
	MarkNode** Dp = &head;
	while (*Dp != NULL) {
		MarkNode* temp = *Dp;
		if (_strcmpi(temp->data.ID.c_str(), ID.c_str()) == 0) {
			*Dp = temp->pNext;
			delete (temp);
		}
		else
			Dp = &(temp->pNext);
	}
}
void get_1_score(MarkNode* &A, string ID, ifstream& f) {
	string temp;
	getline(f, temp);
	while (!f.eof()) {
		getline(f,temp,',');// doc stt
		getline(f, temp, ',');//doc mssv
		if (_strcmpi(temp.c_str(), ID.c_str()) == 0) {
			getline(f, temp, ',');//doc ten
			getline(f, temp, ',');//doc lop
			getline(f, temp, ',');
			A->data.Midterm_Mark = atof(temp.c_str());
			getline(f, temp, ',');
			A->data.Final_Mark = atof(temp.c_str());
			getline(f, temp, ',');
			A->data.Other_Mark = atof(temp.c_str());
			getline(f, temp);
			A->data.Total_Mark = atof(temp.c_str());
			return;
		}
		else {
			getline(f, temp);
		}
	}
}
void get_score(User& A, SchoolYear s_y, int &i) {
	ifstream f;
	string semester_path = "file_save/SchoolYear/" + s_y.year + '/' + s_y.semester.Name + '/';
	string course_path = semester_path + "Course/score/";
	i = 0;
	MarkNode* temp = A.info.phead;
	while (temp != NULL) {
		string fileName = course_path + temp->data.ID + csv_tail;
		f.open(fileName, ios::in);
		if (f.good()) {
			get_1_score(temp, A.ID, f);
		}
		else {
			temp->data.Final_Mark = 0;
			temp->data.Midterm_Mark = 0;
			temp->data.Other_Mark = 0;
			temp->data.Total_Mark = 0;
		}
		f.close();
		i++;
		temp = temp->pNext;
	}
}
void view_1_line(Mark M,int x,int y) {
	printtext(M.ID, x, y);
	printtext(M.Name, x+12 , y);//12 ki tu cho id
	printtext(to_string(M.Midterm_Mark), x + 42, y);//30 ki tu cho ten
	printtext(to_string(M.Final_Mark), x + 56, y);//14 ki tu cho 1 diem
	printtext(to_string(M.Other_Mark), x + 70, y);//14 ki tu cho 1 diem
	printtext(to_string(M.Total_Mark), x + 84, y);//14 ki tu cho 1 diem
}
Mark* view_all_score_of_1_student(User A, SchoolYear Y) {
	system("cls");
	int n;
	get_score(A, Y, n);
	int x = 15;
	int y = 14;
	textBgColor(4, 6);
	printtext("    __     _            __           _____                            ", 25, 3);
	printtext("   / /    (_)   _____  / /_         / ___/  _____  ____    _____  ___ ", 25, 4);
	printtext("  / /    / /   / ___/ / __/         \\__ \\  / ___/ / __ \\  / ___/ / _ \\", 25, 5);
	printtext(" / /___ / /   (__  ) / /_          ___/ / / /__  / /_/ / / /    /  __/", 25, 6);
	printtext("/_____//_/   /____/  \\__/         /____/  \\___/  \\____/ /_/     \\___/ ", 25, 7);
	printtext("                                                                      ", 25, 8);
	drawRectangle(0, 13, 120, n+3, 11);
	textBgColor(0, 11);
	printtext("ID", x, y);
	printtext("Name of Course", x + 12, y);//12 ki tu cho id
	printtext("Midterm Mark", x + 42, y);//30 ki tu cho ten
	printtext("Final Mark", x + 56, y);//14 ki tu cho 1 diem
	printtext("Other Mark", x + 70, y);//14 ki tu cho 1 diem
	printtext("Total Mark", x + 84, y);//14 ki tu cho 1 diem
	y++;
	Mark* M = new Mark[n];
	MarkNode* temp = A.info.phead;
	for (int i = 0; i < n; i++) {
		M[i] = temp->data;
		view_1_line(M[i], x, y + i);
		temp = temp->pNext;
	}
	textBgColor(0, 15);
	return M;
}
void save_Mark(User& A, Mark* B, int i, SchoolYear SY) {
	string Str = ','+A.info.IDstd + ',' + A.info.name + ',' + A.info.Class + ',' + to_string(B[i].Midterm_Mark) + ',' + to_string(B[i].Final_Mark) + ',' + to_string(B[i].Other_Mark) + ',' + to_string(B[i].Total_Mark);
	fstream file_prv, file_aft;
	string fileName= "file_save/SchoolYear/" + SY.year + '/' + SY.semester.Name + "/Course/score/"+B[i].ID;
	bool flag_first_line = true;
	string oldName = fileName + csv_tail;
	string newName = fileName + "new" + csv_tail;
	file_prv.open(oldName, ios::in);
	file_aft.open(newName, ios::out);
	MarkNode* temp = A.info.phead;
	for (int j = 0; j < i; j++) {
		temp = temp->pNext;
	}
	temp->data = B[i];
	string temp_str;
	while (file_prv.eof() == false) {
		getline(file_prv, temp_str, ',');
		if (flag_first_line == true) {
			flag_first_line = false;
			file_aft  << temp_str;
		}
		else {
			file_aft << endl << temp_str;
		}
		getline(file_prv, temp_str, ',');
		if (_strcmpi(temp_str.c_str(), A.info.IDstd.c_str()) == 0) {
			getline(file_prv, temp_str);
			file_aft << Str;
		}
		else {
			file_aft <<','<< temp_str;
			getline(file_prv, temp_str);
			file_aft <<','<< temp_str;
		}
	}

	file_prv.close();
	file_aft.close();
	// removing the existing file
	remove(oldName.c_str());
	// renaming the updated file with the existing file name
	rename(newName.c_str(), oldName.c_str());
}
void insertMark(string& data, int limit, int &flag) {
	char ch;
	do
	{
		ch = _getch();
		if (ch == 8) {
			if (data.size() > 0) {
				data.pop_back();
				gotoxy(ReturnX() - 1, ReturnY());
				cout << " ";
				gotoxy(ReturnX() - 1, ReturnY());
			}
		}
		else if (((ch >= 48 && ch <= 57)||ch=='.') && data.size() < limit) {
			cout << ch;
			data.push_back(ch);
		}
		else if (ch == 27) {
			flag = -1;
			return;
		}
	} while (ch != 13);
}
//
Mark* read_file_score_of_course(SchoolYear SY, string IDcourse, int &n) {
	string fileName = "file_save/SchoolYear/" + SY.year + '/' + SY.semester.Name + "/Course/score/" + IDcourse + csv_tail;
	ifstream f;
	f.open(fileName, ios::in);
	if (!f.good()) {
		return NULL;
	}
	n = countLine(fileName)-1;
	Mark* M=new Mark[n];
	string temp;
	getline(f, temp);
	for (int i = 0; i < n; i++) {
		getline(f, temp, ',');
		getline(f, M[i].ID, ',');
		getline(f, M[i].Name, ',');
		getline(f, M[i].C, ',');
		getline(f, temp, ',');
		M[i].Midterm_Mark = atof(temp.c_str());
		getline(f, temp, ',');
		M[i].Final_Mark = atof(temp.c_str());
		getline(f, temp, ',');
		M[i].Other_Mark = atof(temp.c_str());
		getline(f, temp);
		M[i].Total_Mark = atof(temp.c_str());
	}
	f.close();
	return M;
}
void view_1_score_of_course(Mark M, int x, int y) {
	printtext(M.ID, x, y);
	printtext(M.Name, x + 12, y);//12 ki tu cho id
	printtext(M.C, x + 42, y);
	printtext(to_string(M.Midterm_Mark), x + 52, y);//30 ki tu cho ten
	printtext(to_string(M.Final_Mark), x + 66, y);//14 ki tu cho 1 diem
	printtext(to_string(M.Other_Mark), x + 80, y);//14 ki tu cho 1 diem
	printtext(to_string(M.Total_Mark), x + 94, y);//14 ki tu cho 1 diem
}
void view_10_score_of_course(Mark*M,int i,int n, int x, int y) {
	if (n - i >= 10) {
		for (int j = 0; j < 10; j++) {
			view_1_score_of_course(M[i + j], x, y+j);
		}
	}
	else {
		for (int j = 0; j < n-i; j++) {
			view_1_score_of_course(M[i + j], x, y+j);
		}
	}
	
}
int view_score_of_course_in_year(Mark* M, int n) {
	textBgColor(0, 15);
	system("cls");
	int x = 10;
	int y = 14;
	textBgColor(4, 6);
	printtext("    __     _            __           _____                            ", 25, 3);
	printtext("   / /    (_)   _____  / /_         / ___/  _____  ____    _____  ___ ", 25, 4);
	printtext("  / /    / /   / ___/ / __/         \\__ \\  / ___/ / __ \\  / ___/ / _ \\", 25, 5);
	printtext(" / /___ / /   (__  ) / /_          ___/ / / /__  / /_/ / / /    /  __/", 25, 6);
	printtext("/_____//_/   /____/  \\__/         /____/  \\___/  \\____/ /_/     \\___/ ", 25, 7);
	printtext("                                                                      ", 25, 8);
	drawRectangle(0, y-2, 120, 13, 11);
	textBgColor(0, 11);
	printtext("ID", x, y-1);
	printtext("Name", x + 12, y-1);//12 ki tu cho id
	printtext("Class", x + 42, y-1);
	printtext("Midterm Mark", x + 52, y-1);//30 ki tu cho ten
	printtext("Final Mark", x + 66, y-1);//14 ki tu cho 1 diem
	printtext("Other Mark", x + 80, y-1);//14 ki tu cho 1 diem
	printtext("Total Mark", x + 94, y-1);//14 ki tu cho 1 diem
	char ch;
	int tab_now = 0;
	view_10_score_of_course(M, tab_now*10, n, x, y);
	do {
		hidePointer();
		ch = _getch();
		//[ESC]
		if (ch == 27) {
			return-1;
		}
		else {
			//Control Up down 
			if (ch == 72 && tab_now > 0) //up
			{
				tab_now--;
				drawRectangle(0, y , 120, 11, 11);
				view_10_score_of_course(M, tab_now*10, n, x, y);
			}
			if (ch == 80 && tab_now < (n-1)/10) //down
			{
				tab_now++;
				drawRectangle(0, y, 120, 11, 11);
				view_10_score_of_course(M, tab_now*10, n, x, y);
			}
			if (ch == 13) {
				return tab_now;
			}
		}
	} while (true);
}
void save_Mark_With_List_Cousre(string IDcourse, Mark B, SchoolYear SY) {
	string Str = ',' + B.ID + ',' + B.Name + ',' + B.C + ',' + to_string(B.Midterm_Mark) + ',' + to_string(B.Final_Mark) + ',' + to_string(B.Other_Mark) + ',' + to_string(B.Total_Mark);
	fstream file_prv, file_aft;
	string fileName = "file_save/SchoolYear/" + SY.year + '/' + SY.semester.Name + "/Course/score/" + IDcourse;
	bool flag_first_line = true;
	string oldName = fileName + csv_tail;
	string newName = fileName + "new" + csv_tail;
	file_prv.open(oldName, ios::in);
	file_aft.open(newName, ios::out);
	string temp_str;
	while (file_prv.eof() == false) {
		getline(file_prv, temp_str, ',');
		if (flag_first_line == true) {
			flag_first_line = false;
			file_aft << temp_str;
		}
		else {
			file_aft << endl << temp_str;
		}
		getline(file_prv, temp_str, ',');
		if (_strcmpi(temp_str.c_str(), B.ID.c_str()) == 0) {
			getline(file_prv, temp_str);
			file_aft << Str;
		}
		else {
			file_aft << ',' << temp_str;
			getline(file_prv, temp_str);
			file_aft << ',' << temp_str;
		}
	}

	file_prv.close();
	file_aft.close();
	// removing the existing file
	remove(oldName.c_str());
	// renaming the updated file with the existing file name
	rename(newName.c_str(), oldName.c_str());
}
void view_1_course_of_list_course(Course M, int x, int y) {
	printtext(M.ID_course, x, y);
	printtext(M.name, x + 8, y);//12 ki tu cho id
	printtext(M.teacher, x + 33, y);
	printtext(to_string(M.Num_of_creadit), x + 59, y);//30 ki tu cho ten
	printtext(to_string(M.Max_student), x + 75, y);//14 ki tu cho 1 diem
	printtext(M.DayOfWeek, x + 87, y);//14 ki tu cho 1 diem
	printtext(M.session[0], x + 97, y);//14 ki tu cho 1 diem
	printtext(M.session[1], x + 107, y);
}
void view_10_course_of_list_course(Course* M, int i, int n, int x, int y) {
	if (n - i >= 10) {
		for (int j = 0; j < 10; j++) {
			view_1_course_of_list_course(M[i + j], x, y + j);
		}
	}
	else {
		for (int j = 0; j < n - i; j++) {
			view_1_course_of_list_course(M[i + j], x, y + j);
		}
	}

}
Course* read_file_List_course(User A, SchoolYear SY, int& n) {
	string fileName = "file_save/SchoolYear/" + SY.year + '/' + SY.semester.Name + "/course_info"  + csv_tail;
	ifstream f;
	f.open(fileName, ios::in);
	if (!f.good()) {
		drawRectangle(3, 14, 115, 3, 4);
		printtext("Can't open information file.", 47, 15);
		textBgColor(0, 15);
		Sleep(1800);
		return NULL;
	}
	n = countLine(fileName) - 1;
	if (n == 0) {
		drawRectangle(3, 14, 115, 3, 4);
		printtext("There isn't course now.", 50, 15);
		textBgColor(0, 15);
		Sleep(1800);
		return NULL;
	}
	Course* M = new Course[n];
	string temp;
	getline(f, temp);
	for (int i = 0; i < n; i++) {
		getline(f, M[i].ID_course, ',');
		getline(f, M[i].name, ',');
		getline(f, M[i].teacher, ',');
		getline(f, temp, ',');
		M[i].Num_of_creadit = atoi(temp.c_str());
		getline(f, temp, ',');
		M[i].Max_student = atoi(temp.c_str());
		getline(f, M[i].DayOfWeek, ',');
		getline(f, M[i].session[0], ',');
		getline(f, M[i].session[1]);
	}
	f.close();
	return M;
}
void drawASCIIlistCourse() {
	textBgColor(4, 6);
	printtext(" _     ___ ____ _____    ____ ___  _   _ ____  ____  _____ ", 30, 2);
	printtext("| |   |_ _/ ___|_   _|  / ___/ _ \\| | | |  _ \\/ ___|| ____|", 30, 3);
	printtext("| |    | |\\___ \\ | |   | |  | | | | | | | |_) \\___ \\|  _|  ", 30, 4);
	printtext("| |___ | | ___) || |   | |__| |_| | |_| |  _ < ___) | |___ ", 30, 5);
	printtext("|_____|___|____/ |_|    \\____\\___/ \\___/|_| \\_\\____/|_____|", 30, 6);
	printtext("                                                           ", 30, 7);
}
void drawASCIIenrolCourse() {
	textBgColor(4, 6);
	printtext("                                 __                                                   ", 20, 3);
	printtext("  ___    ____    _____  ____    / /         _____  ____   __  __   _____   _____  ___ ", 20, 4);
	printtext(" / _ \\  / __ \\  / ___/ / __ \\  / /         / ___/ / __ \\ / / / /  / ___/  / ___/ / _ \\", 20, 5);
	printtext("/  __/ / / / / / /    / /_/ / / /         / /__  / /_/ // /_/ /  / /     (__  ) /  __/", 20, 6);
	printtext("\\___/ /_/ /_/ /_/     \\____/ /_/          \\___/  \\____/ \\__,_/  /_/     /____/  \\___/ ", 20, 7);
	printtext("                                                                                      ", 20, 8);
	printtext("Choose the course you want to enrol. Enter to choose.", 35, 28);
}
void drawASCIIsuccessful() {
	textBgColor(6, 0);
	printtext("                                                        ____            __", 20, 15);
	printtext("   _____  __  __  _____  _____  ___    _____   _____   / __/  __  __   / /", 20, 16);
	printtext("  / ___/ / / / / / ___/ / ___/ / _ \\  / ___/  / ___/  / /_   / / / /  / / ", 20, 17);
	printtext(" (__  ) / /_/ / / /__  / /__  /  __/ (__  )  (__  )  / __/  / /_/ /  / /  ", 20, 18);
	printtext("/____/  \\__,_/  \\___/  \\___/  \\___/ /____/  /____/  /_/     \\__,_/  /_/   ", 20, 19);
	printtext("                                                                          ", 20, 20);
	textBgColor(0, 15);
}
void drawASCIIfailEnrol() {
	textBgColor(6, 0);
	printtext("    ______            _     __             __    __    __", 35, 15);
	printtext("   / ____/  ____ _   (_)   / /  ___   ____/ /   / /   / /", 35, 16);
	printtext("  / /_     / __ `/  / /   / /  / _ \\ / __  /   / /   / / ", 35, 17);
	printtext(" / __/    / /_/ /  / /   / /  /  __// /_/ /   /_/   /_/  ", 35, 18);
	printtext("/_/       \\__,_/  /_/   /_/   \\___/ \\__,_/   (_)   (_)   ", 35, 19);
	printtext("                                                         ", 35, 20);
	printtext("        The course has been registered before.           ", 35, 21);
	printtext("                                                         ", 35, 22);
	textBgColor(0, 15);
}
void drawASCIIdeleteCourse() {
	textBgColor(4, 6);
	printtext("    ____           __         __                 ______                                     ", 20, 5);
	printtext("   / __ \\  ___    / /  ___   / /_  ___          / ____/  ____   __  __   _____   _____  ___ ", 20, 6);
	printtext("  / / / / / _ \\  / /  / _ \\ / __/ / _ \\        / /      / __ \\ / / / /  / ___/  / ___/ / _ \\", 20, 7);
	printtext(" / /_/ / /  __/ / /  /  __// /_  /  __/       / /___   / /_/ // /_/ /  / /     (__  ) /  __/", 20, 8);
	printtext("/_____/  \\___/ /_/   \\___/ \\__/  \\___/        \\____/   \\____/ \\__,_/  /_/     /____/  \\___/ ", 20, 9);
	printtext("                                                                                            ", 20, 10);
	printtext("Choose the course you want to delete. Enter to choose.", 35, 28);
}
void drawASCIIStaffMenu() {
	drawRectangle(3, 1, 115, 5, 0);
	drawRectangle(3, 24, 115, 5, 0);
	textBgColor(6, 0);
	printtext(" __    __     ______     __   __     __  __    ", 35, 1);
	printtext("/\\ \"-./  \\   /\\  ___\\   /\\ \"-.\\ \\   /\\ \\/\\ \\   ", 35, 2);
	printtext("\\ \\ \\-./\\ \\  \\ \\  __\\   \\ \\ \\-.  \\  \\ \\ \\_\\ \\  ", 35, 3);
	printtext(" \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_\\\\\"\\_\\  \\ \\_____\\ ", 35, 4);
	printtext("  \\/_/  \\/_/   \\/_____/   \\/_/ \\/_/   \\/_____/ ", 35, 5);
	printtext(" ______     ______   ______     ______   ______  ", 35, 24);
	printtext("/\\  ___\\   /\\__  _\\ /\\  __ \\   /\\  ___\\ /\\  ___\\ ", 35, 25);
	printtext("\\ \\___  \\  \\/_/\\ \\/ \\ \\  __ \\  \\ \\  __\\ \\ \\  __\\ ", 35, 26);
	printtext(" \\/\\_____\\    \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_\\    \\ \\_\\   ", 35, 27);
	printtext("  \\/_____/     \\/_/   \\/_/\\/_/   \\/_/     \\/_/   ", 35, 28);
	//printtext("                                                 ", 30, 29);
	textBgColor(0, 15);
}
void drawASCIIchangeYear() {
	textColor(46);
	printtext("   ______    __                                        __  __                      ", 15, 4);
	printtext("  / ____/   / /_   ____ _   ____    ____ _  ___        \\ \\/ /  ___   ____ _   _____", 15, 5);
	printtext(" / /       / __ \\ / __ `/  / __ \\  / __ `/ / _ \\        \\  /  / _ \\ / __ `/  / ___/", 15, 6);
	printtext("/ /___    / / / // /_/ /  / / / / / /_/ / /  __/        / /  /  __// /_/ /  / /    ", 15, 7);
	printtext("\\____/   /_/ /_/ \\__,_/  /_/ /_/  \\__, /  \\___/        /_/   \\___/ \\__,_/  /_/     ", 15, 8);
	printtext("                                 /____/                                            ", 15, 9);
	textColor(496);
}
void drawASCIIchangeSemester() {
	textColor(46);
	printtext("   ______    __                                 ", 35, 5);
	printtext("  / ____/   / /_   ____ _   ____    ____ _  ___ ", 35, 6);
	printtext(" / /       / __ \\ / __ `/  / __ \\  / __ `/ / _ \\", 35, 7);
	printtext("/ /___    / / / // /_/ /  / / / / / /_/ / /  __/", 35, 8);
	printtext("\\____/   /_/ /_/ \\__,_/  /_/ /_/  \\__, /  \\___/ ", 35, 9);
	printtext("                                 /____/         ", 35, 10);
	printtext("   _____                                   __               ", 30, 23);
	printtext("  / ___/  ___    ____ ___   ___    _____  / /_  ___    _____", 30, 24);
	printtext("  \\__ \\  / _ \\  / __ `__ \\ / _ \\  / ___/ / __/ / _ \\  / ___/", 30, 25);
	printtext(" ___/ / /  __/ / / / / / //  __/ (__  ) / /_  /  __/ / /    ", 30, 26);
	printtext("/____/  \\___/ /_/ /_/ /_/ \\___/ /____/  \\__/  \\___/ /_/     ", 30, 27);
	printtext("                                                            ", 30, 28);
	textColor(496);
}
void drawASCIIeditscore() {
	textBgColor(6, 0);
	printtext("    ______    ____     ____  ______          _____   ______   ____     ____     ______", 20, 4);
	printtext("   / ____/   / __ \\   /  _/ /_  __/         / ___/  / ____/  / __ \\   / __ \\   / ____/", 20, 5);
	printtext("  / __/     / / / /   / /    / /            \\__ \\  / /      / / / /  / /_/ /  / __/   ", 20, 6);
	printtext(" / /___    / /_/ /  _/ /    / /            ___/ / / /___   / /_/ /  / _, _/  / /___   ", 20, 7);
	printtext("/_____/   /_____/  /___/   /_/            /____/  \\____/   \\____/  /_/ |_|  /_____/   ", 20, 8);
	printtext("                                                                                      ", 20, 9);
	textBgColor(0, 15);
}
void drawASCIImenuStudent() {

	drawRectangle(3, 1, 115, 5, 0);
	drawRectangle(3, 23, 115, 5, 0);
	textBgColor(6, 0);
	printtext(" ______     ______   __  __     _____     ______     __   __     ______  ", 23, 1);
	printtext("/\\  ___\\   /\\__  _\\ /\\ \\/\\ \\   /\\  __-.  /\\  ___\\   /\\ \"-.\\ \\   /\\__  _\\ ", 23, 2);
	printtext("\\ \\___  \\  \\/_/\\ \\/ \\ \\ \\_\\ \\  \\ \\ \\/\\ \\ \\ \\  __\\   \\ \\ \\-.  \\  \\/_/\\ \\/ ", 23, 3);
	printtext(" \\/\\_____\\    \\ \\_\\  \\ \\_____\\  \\ \\____-  \\ \\_____\\  \\ \\_\\\\\"\\_\\    \\ \\_\\ ", 23, 4);
	printtext("  \\/_____/     \\/_/   \\/_____/   \\/____/   \\/_____/   \\/_/ \\/_/     \\/_/", 23, 5);
	printtext(" __    __     ______     __   __     __  __    ", 35, 23);
	printtext("/\\ \"-./  \\   /\\  ___\\   /\\ \"-.\\ \\   /\\ \\/\\ \\", 35, 24);
	printtext("\\ \\ \\-./\\ \\  \\ \\  __\\   \\ \\ \\-.  \\  \\ \\ \\_\\ \\ ", 35, 25);
	printtext(" \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_\\\\\"\\_\\  \\ \\_____\\ ", 35, 26);
	printtext("  \\/_/  \\/_/   \\/_____/   \\/_/ \\/_/   \\/_____/ ", 35, 27);
	textBgColor(0, 15);
}
int view_course_in_year(Course* M, int n, drawASCII fun) {
	if (M == NULL) {
		return -1;
	}
	textBgColor(0, 15);
	system("cls");
	int x = 1;
	int y = 14;
	fun();
	drawRectangle(0, y - 2, 120, 13, 11);
	textBgColor(0, 11);
	printtext("ID COURSE", x+2, y - 1);
	printtext("COURSE NAME", x + 12 , y - 1);//12 ki tu cho id
	printtext("TEACHER NAME", x + 35, y - 1);
	printtext("NUMBER OF CREDITS", x + 50, y - 1);//30 ki tu cho ten
	printtext("MAX STUDENT", x + 72, y - 1);
	printtext("DAY", x + 87, y - 1);//14 ki tu cho 1 diem
	printtext("SESSION 1", x + 94, y - 1);//14 ki tu cho 1 diem
	printtext("SESSION 2", x + 104, y - 1);//14 ki tu cho 1 diem
	char ch;
	int tab_now = 0;
	view_10_course_of_list_course(M, tab_now * 10, n, x, y);
	do {
		hidePointer();
		ch = _getch();
		//[ESC]
		if (ch == 27) {
			return-1;
		}
		else {
			//Control Up down 
			if (ch == 72 && tab_now > 0) //up
			{
				tab_now--;
				drawRectangle(0, y, 120, 11, 11);
				view_10_course_of_list_course(M, tab_now * 10, n, x, y);
			}
			if (ch == 80 && tab_now < (n-1) / 10) //down
			{
				tab_now++;
				drawRectangle(0, y, 120, 11, 11);
				view_10_course_of_list_course(M, tab_now * 10, n, x, y);
			}
			if (ch == 13) {
				return tab_now;
			}
		}
	} while (true);
}
Course* select_course(User A, SchoolYear SY, func_Get_course fun, drawASCII fundraw) {
	int n = 0;
	Course* M = fun(A, SY, n);
	if (M == NULL) {
		//thong báo mở file thất bại

		return NULL;
	}
	char ch;
	int line_now = 0;
	int x = 1, y = 14;
	int tab_now = view_course_in_year(M, n, fundraw);
	if (tab_now == -1) {
		textBgColor(0, 15);
		return NULL;
	}
	drawRectangle(1, y + line_now, 115, 1, 14);
	textBgColor(0, 14);
	view_1_course_of_list_course(M[tab_now * 10], x, y);
	int count = tab_now * 10;
	do {
		if (tab_now == -1) {
			textBgColor(0, 15);
			return NULL;
		}
		hidePointer();
		ch = _getch();
		//[ESC]
		if (ch == 27) {
			tab_now = view_course_in_year(M, n, fundraw);
			if (tab_now == -1) {
				textBgColor(0, 15);
				return NULL;
			}
			line_now = 0;
			count = tab_now * 10;
			drawRectangle(1, y + line_now, 115, 1, 14);
			textBgColor(0, 14);
			view_1_course_of_list_course(M[tab_now * 10], x, y);
		}
		else {
			//Control Up down 
			if (ch == 72 && line_now > 0) //up
			{
				drawRectangle(1, y + line_now, 115, 1, 11);
				textBgColor(0, 11);
				view_1_course_of_list_course(M[count], x, y + line_now);

				line_now--;
				count--;
				drawRectangle(1, y + line_now, 115, 1, 14);
				textBgColor(0, 14);
				view_1_course_of_list_course(M[count], x, y + line_now);
			}
			else if (ch == 72 && line_now == 0 && count > 0) {
				count--;
				drawRectangle(0, y, 120, 11, 11);
				view_10_course_of_list_course(M, count, n, x, y);
				drawRectangle(1, y + line_now, 115, 1, 14);
				textBgColor(0, 14);
				view_1_course_of_list_course(M[count], x, y + line_now);
			}
			else if (ch == 80 && line_now < 9 && count < n - 1) //down
			{
				drawRectangle(1, y + line_now, 115, 1, 11);
				textBgColor(0, 11);
				view_1_course_of_list_course(M[count], x, y + line_now);

				line_now++;
				count++;
				drawRectangle(1, y + line_now, 115, 1, 14);
				textBgColor(0, 14);
				view_1_course_of_list_course(M[count], x, y + line_now);
			}
			else if (ch == 80 && line_now == 9 && count < n - 1) {
				count++;
				drawRectangle(0, y, 120, 11, 11);
				view_10_course_of_list_course(M, count - 9, n, x, y);
				drawRectangle(1, y + line_now, 115, 1, 14);
				textBgColor(0, 14);
				view_1_course_of_list_course(M[count], x, y + line_now);
			}
			if (ch == 13) {
				return &M[count];
			}
		}
	} while (true);
	textBgColor(0, 15);
}
Course* get_course_of_student(User A, SchoolYear SY, int& n) {	
	string fileName = "file_save/SchoolYear/" + SY.year + '/' + SY.semester.Name + "/course_info" + csv_tail;
	ifstream f;
	f.open(fileName, ios::in);
	if (!f.good()) {
		return NULL;
	}
	string temp;
	get_course(A, SY);
	if (A.info.phead == NULL) {
		return NULL;
	}
	n = 0;
	MarkNode* count = A.info.phead;
	while (count != NULL) {
		n++;
		count = count->pNext;
	}
	count = A.info.phead;
	Course* M = new Course[n];
	int i = 0;
	while (i<n &&!f.eof()) {
		getline(f, M[i].ID_course, ',');
		if (_strcmpi(M[i].ID_course.c_str(), count->data.ID.c_str()) == 0) {
			getline(f, M[i].name, ',');
			getline(f, M[i].teacher, ',');
			getline(f, temp, ',');
			M[i].Num_of_creadit = atoi(temp.c_str());
			getline(f, temp, ',');
			M[i].Max_student = atoi(temp.c_str());
			getline(f, M[i].DayOfWeek, ',');
			getline(f, M[i].session[0], ',');
			getline(f, M[i].session[1]);
			i++;
			count = count->pNext;
		}
		else {
			getline(f, temp);
		}
	}
	f.close();
	return M;
}