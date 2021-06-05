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
void read_course(User& A)
{
	system("cls");
	string fileName,fileName2, flag,flag2;
	Course co;
	fileName = "file_save/Class/20CTT3_course_1_2020.csv";
	ifstream courseFile;
	int i = 1;
	courseFile.open(fileName, ios::in);
	
	if (!courseFile.is_open() )
		std::cout << "reading file error!";
	gotoxy(1, 5); std::cout << "Order";
	gotoxy(8, 5 ); std::cout << "Id course";
	gotoxy(19, 5 ); std::cout << "Course name";
	gotoxy(35, 5 ); std::cout << "Lecturer";
	gotoxy(50, 5 ); std::cout << "Max student";
	gotoxy(63, 5); std::cout << "Student";
	gotoxy(72, 5 ); std::cout <<"Schedule";
	gotoxy(88, 5); std::cout << "Start date";
	gotoxy(105, 5); std::cout << "End date" << std::endl;
	

	
	while (!courseFile.eof())
	{
		
		getline(courseFile, flag, ',');
		if (flag.size() > 8)
			flag.erase(0, 3); 
		
		if (flag.compare(A.ID) == 0)
		{
			getline(courseFile, flag, ',');
			while (true)
			{
			//toi day van chay
				fileName2 = "file_save/course_info.csv";
				ifstream courseInfor;
				courseInfor.open(fileName2, ios::in);
				if (!courseInfor.is_open())
					std::cout << "reading error!" << std::endl;
				getline(courseInfor, flag2);
				while (!courseInfor.eof())
				{
					
					
				
					read1CourseInfor(co, courseInfor);
					
					if (flag.compare(co.ID_course) == 0)
					{
						
						gotoxy(1, 5 + i); std::cout << i;
						gotoxy(8, 5 + i); std::cout << co.ID_course;
						gotoxy(19, 5 + i); std::cout << co.name;
						gotoxy(35, 5+ i); std::cout << co.teacher;
						gotoxy(50, 5 + i); std::cout << co.Max_student;
						gotoxy(63, 5 + i); std::cout << co.Num_of_std_now;
						gotoxy(72, 5 + i); std::cout << co.Schedule;
						gotoxy(88, 5 + i); std::cout << co.date_star;
						gotoxy(105, 5 + i); std::cout << co.date_end;
						i++;
						break;
					}
					
				}
				courseInfor.close();
				if (courseFile.peek() == '\n')
					break;
			}
			break;
		}
		getline(courseFile, flag2);
	}
	courseFile.close();
	
	system("pause");
}

void read1CourseInfor(Course& A, ifstream& f)
{
	string flag;//luu tru thong tin dang int tam thoi;
	getline(f, flag,',');
	getline(f, A.ID_course, ',');
	
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