#include "Header.h"
#include "read_data.h"
#include"ConsoleProcess.h"

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

void read_course(User& A, SchoolYear y)
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
			if (_strcmpi(co.ID_course.c_str(),tempo->ID.c_str()) == 0)
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
void add_Tail_List_Mark(MarkNode*& head, string A) {
	//khởi tạo 1 node
	MarkNode* n1 = new MarkNode;
	n1->ID = A;
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
					add_Tail_List_Mark(A.info.phead, IDtemp);
					IDtemp = "";
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
		if (_strcmpi(temp->ID.c_str(), ID.c_str()) == 0) {
			*Dp = temp->pNext;
			delete (temp);
		}
		else
			Dp = &(temp->pNext);
	}
}
