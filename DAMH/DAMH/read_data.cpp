
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
	printtext("| ||  _ \\ (_   __) / _ \\  / ___)|    \\ (____ |(_   _)| | / _ \\ |  _ \\ ", 20, 5);
	printtext("| || | | |  | |   | |_| || |    | | | |/ ___ |  | |_ | || |_| || | | |", 20, 6);
	printtext("|_||_| |_|  |_|    \\___/ |_|    |_|_|_|\\_____|   \\__)|_| \\___/ |_| |_|", 20, 7);
	drawRectangle(30, 12, 50, 16, 11);
	printtext("Ho va ten: " + A.info.name, 35, 15);
	if (A.role == 1) {
		printtext("Ma so sinh vien: " + A.info.IDstd, 35, 17);
	}
	else {
		printtext("email : " + A.info.IDstd + "@hcmus.edu.vn", 35, 17);
	}
	printtext("ngay sinh: " + A.info.Bir, 35, 19);
	printtext("gioi tinh: " + A.info.sex, 35, 21);
	printtext("chuc vu: " + (A.role == 1) ? "Hoc sinh" : "Admin", 35, 23);
	printtext("CMND/CCCD: " + A.info.IDsocial, 35, 25);
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
	textBgColor(0, 15);
	/*string fileName, fileName2, flag, flag2;
	Course co;
	fileName = "file_save/Class/20CTT3_course_1_2020.csv";
	ifstream courseFile;
	int i = 1;
	courseFile.open(fileName, ios::in);

	if (!courseFile.is_open())
		std::cout << "reading file error!";*/
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
void add_Tail_List_Mark(MarkNode*& head, string ID , string name) {
	//khởi tạo 1 node
	MarkNode* n1 = new MarkNode;
	n1->data.ID = ID;
	n1->data.Name = name;
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
void get_course(User& A, SchoolYear s_y) {
	ifstream f;
	string semester_path = "file_save/SchoolYear/" + s_y.year + '/' + s_y.semester.Name + '/';
	string class_path = semester_path + "Class/";
	string course_path = semester_path + "Course/";
	string fileName = class_path + A.info.Class + csv_tail;// chỉ là thử nghiệm, sau khi có hàm đọc học kì sẽ thay đổi.
	f.open(fileName, ios::in);
	init_List_Mark(A.info.phead);
	while (f.eof() == false) {
		string temp;
		getline(f, temp, ',');
		if (temp.compare(A.ID) != 0) {
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
					while (!fi.eof()) {
						getline(fi, temp, ',');
						if (_strcmpi(temp.c_str(), IDtemp.c_str()) == 0) {
							getline(fi, temp, ',');
							break;
						}
						else {
							getline(fi, temp);
						}
					}
					add_Tail_List_Mark(A.info.phead, IDtemp, temp);
					IDtemp = "";
					fi.close();
				}
				else if (temp1[i] != ',') {
					IDtemp += temp1[i];
				}
			}
		}
	}
	f.close();
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
			if (ch == 80 && tab_now < n/10) //down
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