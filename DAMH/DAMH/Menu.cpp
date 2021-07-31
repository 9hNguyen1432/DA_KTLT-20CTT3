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
		string MenuStaff[] = {
			"YOUR INFO","NEW","CLASS INFO","COURSE INFO","RESULT OF STUDENTS","LOG OUT"
		};
			/*{ 

 "4. CLASS",

 "7. Add student to class",
,
 "9. Edit student's marks",
 "10. View list of course\, Delete a course\, update course information",
 "11. Export student list",
 "12. Import student list",
 "13. View score board of a course",
 "14. View score board of a class" };*/
		drawMenu(MenuStaff, 6, 50, 10, 1,&drawASCIIStaffMenu);
		option = MoveAndChoose(6, MenuStaff, 50, 10, 1);
		switch (option)
		{
		case 0: {
			system("cls");
			string MenuStaff1[] = {
			"1. Profile info",
		 "2. Change password","3.Back to Menu"
			};
			drawMenu(MenuStaff1, 3, 50, 11, 2, &drawASCIIStaffMenu);
			int option1 = MoveAndChoose(3, MenuStaff1, 50, 11, 2);
			switch (option1)
			{
			case 0: {
				// lenh show thong tin 
				Output_info(user);
				break;
			}
			case 1: {
				// lenh thay mat khau
				change_password(user);
				break;
			}
			case 2: {
				break;
			}
			}
			break;
		}
		case 1:
		{
			system("cls");
			string MenuStaff2[] = {
			"1. Create school - year",
		 "2. Create semester ", "3. Create course registration session", "4. Create course",
		 "5. Create Class","6. Back to Menu"
			};
			drawMenu(MenuStaff2, 6, 40, 10, 1, &drawASCIIStaffMenu);
			int option1 = MoveAndChoose(6, MenuStaff2, 40, 10, 1);
			switch (option1)
			{
			case 0: {
				// lenh tao nam
				addSchoolYear(SY);
				break;
			}
			case 1: {
				//lenh them hoc ki
				addSemester(SY.year, SY.semester.Name);
				break;
			}
			case 2: {
				// tao phien dang ki khoa hoc
				createRegistrationCourse();
				break;
			}
			case 3: {
				// lenh them khoa hoc
				addCourse();
				break;
			}
			case 4: {
				// lenh them lop hoc
				CreateNewClass();
				break;
			}
			default:
				break;
			}
			break;
		}
		case 2:
		{
			system("cls");
			//xem danh sach lop hoc va danh sach sinh vien trong lop
			listClass(user,SY, &showStudentInclass);
			break;
		}
		case 3: {
			system("cls");
			string MenuStaff4[] = {
				"1. View List Course And List Student in Course",
			 "2. Delete or Edit Course info","3.Back to Menu"};
			drawMenu(MenuStaff4, 3, 45, 10, 2, &drawASCIIStaffMenu);
			int option1 = MoveAndChoose(3, MenuStaff4, 45, 10, 2);
			switch (option1)
			{
			case 0: {
				system("cls");
				//xem danh sach khoa hoc va danh sach sinh vien trong khoa
				viewStudentInCourse(user,SY);
				textBgColor(0, 15);
				break;
			}
			case 1: {
				//view danh sachs hoc phan
				listCourse(user,SY.year, SY.semester.Name);
				break;
			}
			case 2: {
				break;
			}
			}
			break;
		}
		case 4:
			/*system("cls");
			RunMenuViewListClass();
			break;*/
		{
			system("cls");
			string MenuStaff5[] = {
			"1. View and edit student's marks", "2. Export student list mark", "3. Import student list mark", "4. Back to Menu"};
			drawMenu(MenuStaff5, 4, 40, 10, 2, &drawASCIIStaffMenu);
			int option1 = MoveAndChoose(4, MenuStaff5, 40, 10, 2);
			switch (option1)
			{
			case 0: //edit diem sinh vien
			{
				system("cls");
				string edit[] = { "1. From List Class.","2. From List Course.","3. Exit to Menu." };
				drawMenu(edit, 3, 45, 20, 2, &drawASCIIeditscore);
				int choose = MoveAndChoose(3, edit, 45, 20, 2);
				switch (choose)
				{
				case 0: {
					listClass(user,SY, &showScoreOfClass);
					break;
				}
				case 1: {
					Course* SLC = select_course(user, SY, &read_file_List_course, &drawASCIIlistCourse);
					if (SLC == NULL) {
						break;
					}
					edit_score_in_list_course(user, SY, SLC->ID_course);
					break;
				}
				default:
					break;
				}
				break;
			}
			case 1: {
				//xuat diem hoc sinh vao file
				exportScoreboardInterface(user,SY.year, SY.semester.Name,2, 1);
				break;
			}
			case 2: {
				//xuat diem hoc sinh vao file
				importScoreBoardUI();
				break;
			}
			default:
				break;
			}
			break;
		}
		case 7:
			//them sinh vien vao lop
			system("cls");
			//AddStudentToClass();
			RunMenuAddInfoStudentToClass();
			break;

		case 14:
			//view diem cua lop hoc
			listClassUseFor14(SY);
			break;
		case 5:
			isExit = true;
			break;
		//default: std::cout << "your choice is invalid!!!\n";
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