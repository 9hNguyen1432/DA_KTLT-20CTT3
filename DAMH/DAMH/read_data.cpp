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
