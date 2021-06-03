﻿#include "Header.h"
#include "Course_function.h"
#include"ConsoleProcess.h"
#include "read_data.h"
// hàm tổng quát, command_flag >=0, thì thêm data vào file, <0 xóa data khỏi file
void rewrite_course_of_student_file(User user, string fileName, string data, int command_flag) {
	fstream file_prv, file_aft;
	string oldName = fileName+csv_tail;
	string newName = fileName+"new"+csv_tail;
	file_prv.open(oldName, ios::in);
	file_aft.open(newName, ios::out);
	string temp;
	bool flag_change = true;
	while (file_prv.eof() == false) {
		//đọc, ghi lại số thứ tự
		/*getline(file_prv, temp, ',');
		file_aft << temp << ',';*/
		//đọc ghi lại mssv
		getline(file_prv, temp);
		string temp1 = "";
		int i = 0;
		for (i = 0; i < temp.length(); i++) {
			if (temp[i] == ',' || i == temp.length() - 1)
			{
				if (i == temp.length() - 1) {
					temp1 += temp[i];
				}
				break;
			}
			else if (temp[i] != ',') {
				temp1 += temp[i];
			}
		}
		if (user.ID.compare(temp1) != 0) {
			if (flag_change == true) {
				file_aft << temp;
				flag_change = false;
			}
			else {
				file_aft << '\n' << temp;
			}
		}
		else {
			if (command_flag >= 0) {
				temp1 = temp + ',' + data;
			}
			else {
				string temp2 = "";
				for (i = i + 1; i < temp.length(); i++) {
					if (temp[i] == ',' || i == temp.length() - 1)
					{
						if (i == temp.length() - 1) {
							temp2 += temp[i];
						}
						if (_strcmpi(temp2.c_str(), data.c_str()) != 0) {
							temp1 = temp1 + ',' + temp2;
						}
						temp2 = "";
					}
					else if (temp[i] != ',') {
						temp2 += temp[i];
					}
				}
			}
			if (flag_change == true) {
				file_aft << temp1;
				flag_change = false;
			}
			else {
				file_aft << '\n' << temp1;
			}
		}
	}
	file_prv.close();
	file_aft.close();
	// removing the existing file
	remove(oldName.c_str());
	// renaming the updated file with the existing file name
	rename(newName.c_str(), oldName.c_str());
}
//hàm ghi danh vào file khóa học tổng của staff, user là học sinh.
void rewrite_course_of_staff_file(User user, string fileName, string ID_course, int command_flag) {
	fstream file_prv, file_aft;
	string oldName = fileName + csv_tail;
	string newName = fileName + "new" + csv_tail;
	file_prv.open(oldName, ios::in);
	file_aft.open(newName, ios::out);
	string temp;
	bool flag_change = true;
	while (file_prv.eof() == false) {
		string str_num_of_student;
		int num_of_student;
		getline(file_prv, temp, ',');
		if (flag_change == true) {
			file_aft << temp;
			flag_change = false;
		}
		else {
			file_aft << '\n' << temp;
		}
		getline(file_prv, str_num_of_student);
		num_of_student = stoi(str_num_of_student);
		if (_strcmpi(temp.c_str(), ID_course.c_str()) != 0) {
			file_aft << ',' << str_num_of_student;
			for (int i = 0; i < num_of_student; i++) {
				getline(file_prv, temp);
				file_aft << '\n' << temp;
			}
		}
		else {
			if (command_flag >= 0) {
				num_of_student++;
				file_aft << ',' << to_string(num_of_student);
				for (int i = 0; i < num_of_student - 1; i++) {
					getline(file_prv, temp);
					file_aft << '\n' << temp;
				}
				file_aft << '\n' << user.ID << ',' << "20CTT333";
			}
			else {
				num_of_student--;
				file_aft << ',' << to_string(num_of_student);
				for (int i = 0; i < num_of_student + 1; i++) {
					getline(file_prv, temp, ',');
					if (_strcmpi(temp.c_str(), user.ID.c_str()) == 0) {
						getline(file_prv, temp);
					}
					else {
						file_aft << temp;
						getline(file_prv, temp);
						file_aft << '\n' << temp;
					}
				}
			}
		}
	}
	file_prv.close();
	file_aft.close();
	// removing the existing file
	remove(oldName.c_str());
	// renaming the updated file with the existing file name
	rename(newName.c_str(), oldName.c_str());
};
void enroll_course(User& A) {
	//hàm hiện danh sách các môn học.
	string ID_course_input;
	cout<<"\nEnter the course code you want to register for: ";
	cin.ignore();
	getline(cin, ID_course_input);
	fstream file_course_info;
	file_course_info.open("file_save/course_info.csv", ios::in);
	string temp;
	string file_cousre = "file_save/Class/" + A.info.Class + "_1_2020";
	while (file_course_info.eof() == false) {
		getline(file_course_info, temp, ',');//đọc stt
		getline(file_course_info, temp, ',');//đọc mã môn học
		//nếu so sánh được mã môn nhập vào có trong danh sách lớp học, cho phép ghi danh:
		if (_strcmpi(temp.c_str(), ID_course_input.c_str()) == 0) {
			MarkNode* Mtemp = A.info.phead;
			//kiểm tra xem trong danh sách môn học của sinh viên đã có môn này hay chưa
			while (Mtemp != NULL) {
				if (_strcmpi(temp.c_str(), Mtemp->ID.c_str()) == 0) {
					//nếu có thì return.
					cout << "\nFailed!! The course has been registered before.";
					return;
				}
				Mtemp = Mtemp->pNext;
			}
			//chưa có thì thêm vào danh sách.
			add_Tail_List_Mark(A.info.phead, temp);
			//ghi them vao file;
			rewrite_course_of_student_file(A, file_cousre, temp, 1);
			rewrite_course_of_staff_file(A, "file_save/Course/total_student", temp, 1);
		}
		// ngược lại so sánh không hợp lệ
		else {
			cout << "\nFailed!! Invalid ID course";
			return;
		}
	}
}