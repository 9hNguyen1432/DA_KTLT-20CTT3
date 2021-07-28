#include"Menu.h"
#include"Login.h"
#include"ConsoleProcess.h"
#include "read_data.h"
#include "change_info.h"
#include"staffFunction.h"
#include "Course_function.h"
#include "ListClass.h"
#include "AddStudent.h"

void menuStaff(User &user)
{	
	showPointer();
	bool isExit = false;
	SchoolYear SY;
	determineYearSemesterNow(SY.year, SY.semester.Name);
	read_info(user, SY);			
	int option;
	do
	{	
		showPointer();
		system("cls");
		gotoxy(0, 7);
		string MenuStaff[] = { "0. Log out","1. Profile info",
 "2. Change password",
 "3. Create school-year",
 "4. Create class",
 "5. Create course",
 "6. Create course registration session",
 "7. Add student to class",
 "8. Create semester ",
 "9. Edit student's marks",
 "10. View list of course\, Delete a course\, update course information",
 "11. Export student list",
 "12. Import student list",
 "13. View score board of a course",
 "14. View score board of a class" };
		drawMenu(MenuStaff, 15, 28, 7, 0,&drawASCIIStaffMenu);
		option = MoveAndChoose(15, MenuStaff, 28, 7, 0);
		switch (option)
		{
		case 1:
			// lenh show thong tin 
			Output_info(user);
			break;
		case 2:
			// lenh thay mat khau
			change_password(user);
			break;
		case 3:
			// lenh them nam hoc
			addSchoolYear(SY);
			break;
		case 4:
			system("cls");
			RunMenuViewListClass();
			break;
		case 5:
			// lenh them khoa hoc
			addCourse();
			break;
		case 6:
			// Create course registration session
			createRegistrationCourse();
			break;
		case 7:
			//them sinh vien vao lop
			system("cls");
			//AddStudentToClass();
			RunMenuAddInfoStudentToClass();
			break;
		case 8: 
			//lenh them hoc ki
			addSemester(SY.year, SY.semester.Name);
			break;
		case 9:
			//edit diem sinh vien
		{
			system("cls");
			string edit[] = { "1. From List Class.","2. From List Course.","3. Exit to Menu." };
			drawMenu(edit, 3, 45, 20, 2, &drawASCIIeditscore);
			int choose = MoveAndChoose(3, edit, 45, 20, 2);
			switch (choose)
			{
			case 0: {
				listClass(SY);
				break;
			}
			case 1: {
				Course* SLC = select_course(user, SY, &read_file_List_course, &drawASCIIlistCourse);
				edit_score_in_list_course(user, SY, SLC->ID_course);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 10:
			//view danh sachs hoc phan
			listCourse(SY.year, SY.semester.Name);
			break;
		case 11:
			//xuat diem hoc sinh vao file
			exportScoreboardInterface(SY.year, SY.semester.Name, 2, 2, 1);
			break;
		case 12:
			//xuat diem hoc sinh vao file
			importScoreBoardUI();
			break;
		case 13:
		{
			int n = 0;
			view_score_of_course_in_year(read_file_score_of_course(SY, "ABC4", n), n);
			textBgColor(0, 15);
			break;
		}
		case 14:
			//view diem cua lop hoc
			listClassUseFor14(SY);
			break;
		case 0:
			isExit = true;
			break;
		default: std::cout << "your choice is invalid!!!\n";
		}
	} while (!isExit);
	repeatLogin(user);
}
void menuStudent(User &user)
{
	showPointer();
	SchoolYear SY;
	determineYearSemesterNow(SY.year, SY.semester.Name);
	if (SY.semester.Name == "Semester0") {
		drawRectangle(3, 14, 115, 3, 4);
		printtext("The school year hasn't started yet ", 40, 15);
		Sleep(1800);
		repeatLogin(user);
		return;
	}
	read_info(user,SY);
	init_List_Mark(user.info.phead);
	get_course(user,SY);
	bool isExit = false;
	int option;
	do
	{
		system("cls");
		string menuStudent[]= { "0. Log out", "1. Profile info"
		 , "2. Change password"
		 , "3. Score board"
		 , "4. Enroll courses"
		 , "5. List of enrolled courses"
		 , "6. Remove courses"
		 , "7. View your list of course" };
		drawMenu(menuStudent, 8, 45, 10, 0, &drawASCIImenuStudent);
		option = MoveAndChoose(8, menuStudent, 45, 10, 0);
		switch (option)
		{
		case 1:
			Output_info(user);
			break;
		case 2:
			change_password(user);
			break;
		case 3:
			// lenh show bang diem
			DisPlay_Mark_Of_Student( SY, user);
			break;
		case 4:
		{
			//enroll_course(user, SY);
			int check = checkCourseSession();
			if (check == 1) {
				enroll_course(user, SY);
				system("pause");
			}
			else {
				drawRectangle(40, 15, 25, 5, 4);
				textBgColor(15, 4);
				if (check == 0) printtext("NOT OPEN REGISTER COURSE YET", 41, 17);
				else if (check == -1) printtext("IT'S NOT THE TIME TO START YET", 41, 17);
				else printtext("It was late to register the course", 41, 17);
				Sleep(1000);
				textBgColor(0, 15);
			}
			break;

		}
		case 5: 
			DisPlay_Course_Of_Student(SY, user);
			//edit_score(user, SY, view_all_score_of_1_student(user, SY));
			//edit_score_in_list_course(user, SY);
			break;
		case 6:
		{
			//lenh xoa bot khoa hoc da dang ki
			int check = checkCourseSession();
			if (check == 1) {
				delete_course(user, SY);
				system("pause");
			}
			else {
				drawRectangle(40, 15, 25, 5, 4);
				textBgColor(15, 4);
				if (check == 0) printtext("NOT OPEN REGISTER COURSE YET", 41, 17);
				else if (check == -1) printtext("IT'S NOT THE TIME TO START YET", 41, 17);
				else printtext("It was late to register the course", 41, 17);
				Sleep(1000);
				textBgColor(0, 15);
			}

			break;
		}
		case 7:
			DisPlay_Course_Of_Student(SY, user);
			break;
		case 0:
			isExit = true;
			break;
		default: std::cout << "option is invalid!!!\n";
			break;
		}
	} while (!isExit);
	repeatLogin(user);
}