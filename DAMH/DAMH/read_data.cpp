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
void read_info(User& A) {
	string fileName;
	if (A.role == 1) {
		fileName = "file_save/Class/"+A.info.Class + csv_tail;
	}
	else {
		fileName = "file_save/Class/staff.csv";
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

void read_course(User& A, MarkNode* &view)
{
	string fileName, flag;
	fileName = "file_save/Class/" + A.info.Class + csv_tail;
	ifstream courseFile;
	courseFile.open(fileName, ios::in);
	
	MarkNode* temp = new MarkNode;
	temp = view;
	
	while (!courseFile.eof())
	{
		getline(courseFile, temp->ID, ',');
		if (temp->ID.compare(A.ID) == 0)
		{
			getline(courseFile, temp->ID, ',');
			while (courseFile.peek() != '\n')
			{
				MarkNode* clone = new MarkNode;
				getline(courseFile, clone->ID, ',');
				temp->pNext = clone;
				temp = temp->pNext;
			}
			break;
		}
		getline(courseFile, temp->ID);
	}
	temp->pNext = NULL;
	courseFile.close();
	fileName = "file_save/course_infor.csv";
	ifstream courseInfor;
	courseFile.open(fileName, ios::in);
	getline(courseFile, flag);
	int i = 0;
	while (view->pNext != NULL)
	{
		i++;
		while (!courseFile.eof())
		{
			Course course;
			getline(courseFile, flag, ',');
			read1CourseInfor(course, courseFile);
			getline(courseFile, flag, ',');
			if (view->ID.compare(flag) == 0)
			{
				gotoxy(5, 0 + i);std::cout<<
			}

		}
	}
}

void read1CourseInfor(Course& A, ifstream& f)
{
	string flag;//luu tru thong tin dang int tam thoi;
	getline(f, flag,',');
	getline(f, flag, ',');
	A.ID_course = stoi(flag, 0, 10);
	getline(f, A.name, ',');
	getline(f, A.teacher, ',');
	getline(f, flag, ',');
	A.Num_of_std_now= stoi(flag, 0, 10);
	getline(f, flag, ',');
	A.Max_student = stoi(flag, 0, 10);
	getline(f, A.Schedule, ',');
	getline(f, A.date_star, ',');
	getline(f, A.date_end, ',');
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
void read_course(User& A) {
	ifstream f;
	string fileName = "file_save/Class/" + A.info.Class + "_1_2020" + csv_tail;// chỉ là thử nghiệm, sau khi có hàm đọc học kì sẽ thay đổi.
	f.open(fileName, ios::in);
	init_List_Mark(A.info.phead);
	while (f.eof() == false) {
		string temp;
		getline(f, temp, ',');
		if (temp.compare(A.ID) != 0) {
			getline(f, temp);
		}
		else {
			getline(f, temp);
			string IDtemp = "";
			for (int i = 0; i < temp.length(); i++) {
				if (temp[i] == ',' || i == temp.length() - 1)
				{
					if (i == temp.length() - 1) {
						IDtemp += temp[i];
					}
					add_Tail_List_Mark(A.info.phead, IDtemp);
					IDtemp = "";
				}
				else if (temp[i] != ',') {
					IDtemp += temp[i];
				}
			}
		}
	}
}

