#include "read_data.h"
#include <string>
#include <fstream>
using namespace std;
void read_1_info(User& A, ifstream& f) {
	string NO_temp;
	std::getline(f, NO_temp, ',');
	A.info.NO_inclass = stoi(NO_temp);
	std::getline(f, A.info.IDstd, ',');// giáo viên thì sẽ là id đăng nhập
	getline(f, A.info.name, ',');
	getline(f, A.info.Bir, ',');
	getline(f, A.info.sex, ',');
	getline(f, A.info.IDsocial);
	A.info.phead = NULL;
}
//
void read_info(User& A, SchoolYear SY) {
	string year_path = "file_save/SchoolYear/" + SY.year + '/';
	string fileName;
	if (A.role == 1) {
		fileName = year_path + A.info.Class + csv_tail;
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
	if (tempo == NULL) {
		drawRectangle(1, 17, 115, 3, 2);
		printtext("You has not registered for any courses this semester ", 30, 18);
		textBgColor(0, 15);
		return;
	}
	while (tempo != NULL)
	{
		string fl;
		Course co;
		fi.open(fileName, ios::in);
		getline(fi, fl);
		while (!fi.eof())
		{
			read1CourseInfor(co, fi);
			if (_strcmpi(co.ID_course.c_str(), tempo->data.ID.c_str()) == 0)
			{
				drawRectangle(1, 15 + i, 115, 2, 6);
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
	A.Num_of_creadit = stoi(flag, 0, 10);
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
void add_Tail_List_Mark(MarkNode*& head, string ID, string name, string num_of_creadit) {
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
		return -1;
	}
	if (flag == 0) {
		init_List_Mark(A.info.phead);
	}
	while (f.eof() == false) {

		string temp1;
		getline(f, temp1);
		size_t found = temp1.find(",");
		if (found == std::string::npos) {
			if (_strcmpi(temp1.c_str(), A.info.IDstd.c_str()) != 0) {
				continue;
			}
			else {
				return -2;
			}
		}
		int length = f.tellg();
		if (length == -1) {
			f.close();
			f.open(fileName, ios::in);
			f.seekg(0,ios::end);
			int a = f.tellg();
			f.seekg(a - temp1.length(), ios::beg);
		}
		else {
			f.seekg(length - temp1.length() - 2, ios::beg);
		}
		string temp;
		getline(f, temp, ',');
		if (temp.compare(A.info.IDstd) != 0) {
			getline(f, temp);
		}
		else {
			string temp1;
			getline(f, temp1);
			string IDtemp = "";
			for (int i = 0; i < temp1.length(); i++) {
				if (temp1[i] == ',' || i == temp1.length() - 1)
				{
					if (i == temp1.length() - 1) {
						IDtemp += temp1[i];
					}
					ifstream fi;
					string fileName = "file_save/SchoolYear/" + s_y.year + "/" + s_y.semester.Name + "/course_info.csv";
					fi.open(fileName, ios::in);
					string temp;
					string num_of_creadit;
					while (!fi.eof()) {
						getline(fi, temp, ',');
						if (_strcmpi(temp.c_str(), IDtemp.c_str()) == 0) {
							getline(fi, temp, ',');
							getline(fi, num_of_creadit, ',');
							getline(fi, num_of_creadit, ',');
							break;
						}
						else {
							getline(fi, temp);
						}
					}
					add_Tail_List_Mark(A.info.phead, IDtemp, temp, num_of_creadit);
					IDtemp = "";
					fi.close();
				}
				else if (temp1[i] != ',') {
					IDtemp += temp1[i];
				}
			}
			f.close();
			return 0;
		}
	}

}
//
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
void get_all_course(User& A, SchoolYear SY) {
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
void get_1_score(MarkNode*& A, string ID, ifstream& f) {
	string temp;
	getline(f, temp);
	while (!f.eof()) {
		getline(f, temp, ',');// doc stt
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
void get_score(User& A, SchoolYear s_y, int& i) {
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
//
void save_Mark(User& A, Mark* B, int i, SchoolYear SY) {
	string Str = ',' + A.info.IDstd + ',' + A.info.name + ',' + A.info.Class + ',' + to_string(B[i].Midterm_Mark) + ',' + to_string(B[i].Final_Mark) + ',' + to_string(B[i].Other_Mark) + ',' + to_string(B[i].Total_Mark);
	fstream file_prv, file_aft;
	string fileName = "file_save/SchoolYear/" + SY.year + '/' + SY.semester.Name + "/Course/score/" + B[i].ID;
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
			file_aft << temp_str;
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
void insertMark(string& data, int limit, int& flag) {
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
		else if (((ch >= 48 && ch <= 57) || ch == '.') && data.size() < limit) {
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
Mark* read_file_score_of_course(SchoolYear SY, string IDcourse, int& n) {
	string fileName = "file_save/SchoolYear/" + SY.year + '/' + SY.semester.Name + "/Course/score/" + IDcourse + csv_tail;
	ifstream f;
	f.open(fileName, ios::in);
	if (!f.good()) {
		return NULL;
	}
	n = countLine(fileName) - 1;
	Mark* M = new Mark[n];
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
//
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
//
Course* read_file_List_course(User A, SchoolYear SY, int& n) {
	string fileName = "file_save/SchoolYear/" + SY.year + '/' + SY.semester.Name + "/course_info" + csv_tail;
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
	while (i < n && !f.eof()) {
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
			f.close();
			f.open(fileName, ios::in);
		}
		else {
			getline(f, temp);
		}
	}
	return M;
}
Data* read_file_student_info_of_course(SchoolYear SY, string IDcourse, int& n) {
	string fileName = "file_save/SchoolYear/" + SY.year + '/' + SY.semester.Name + "/Course/" + IDcourse + csv_tail;
	ifstream f;
	f.open(fileName, ios::in);
	if (!f.good()) {
		return NULL;
	}
	n = countLine(fileName) - 1;
	Data* M = new Data[n];
	string temp;
	getline(f, temp);
	for (int i = 0; i < n; i++) {
		getline(f, M[i].IDstd, ',');
		getline(f, M[i].name, ',');
		getline(f, M[i].Bir, ',');
		getline(f, M[i].sex, ',');
		getline(f, M[i].IDsocial);
		M[i].NO_inclass = i + 1;
	}
	f.close();
	return M;
}
