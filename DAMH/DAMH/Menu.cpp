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
		 "5. Create Class","6. Add Student To Class", "7. Back to Menu"
			};
			drawMenu(MenuStaff2, 7, 40, 8, 1, &drawASCIIStaffMenu);
			int option1 = MoveAndChoose(7, MenuStaff2, 40, 8, 1);
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
				RunMenuCreateClass();
				break;
			}
			case 5:
			{
				system("cls");
				//AddStudentToClass();
				RunMenuAddInfoStudentToClass();
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
					try {
						Course* SLC = select_course(user, SY, &read_file_List_course, &drawASCIIlistCourse);
						if (SLC == NULL) {
							break;
						}
						edit_score_in_list_course(user, SY, SLC->ID_course);
					}
					catch (const char* err) {
						drawRectangle(3, 14, 115, 3, 4);
						printtext(err, 50, 15);
						textBgColor(0, 15);
						Sleep(1800);
					}
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
	string menuStudent[] = { "YOUR INFO", "COURSE" , "YOUR RESULTS","LOG OUT" };
	string MenuStd1[] = {"1. Profile info","2. Change password","3.Back to Menu" };
	string MenuStd2[] = { "1. Enroll courses","2. Remove course","3. View your list of course","4.Back to Menu" };
 //, "3. Score board"
 //, "4. Enroll courses"
 //, "5. List of enrolled courses"
 //, "6. Remove courses"
 //, "7. View your list of course" };
	do
	{
		system("cls");
		drawMenu(menuStudent, 4, 50, 10, 2, &drawASCIImenuStudent);
		option = MoveAndChoose(4, menuStudent, 50, 10, 2);
		switch (option)
		{
		case 0: {
			system("cls");
			drawMenu(MenuStd1, 3, 50, 11, 2, &drawASCIIStaffMenu);
			int option1 = MoveAndChoose(3, MenuStd1, 50, 11, 2);
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
		case 1: {
			system("cls");
			drawMenu(MenuStd2, 4, 45, 10, 2, &drawASCIImenuStudent);
			int option1 = MoveAndChoose(4, MenuStd2, 45, 10, 2);
			switch (option1)
			{
			case 0: {
				//enroll_course(user, SY);
				try {
					int check = checkCourseSession();
					if (check == 1) {
						enroll_course(user, SY);
					}
					else {
						drawRectangle(35, 15, 50, 5, 4);
						textBgColor(15, 4);
						if (check == 0) printtext("NOT OPEN REGISTER COURSE YET", 45, 17);
						else if (check == -1) printtext("IT'S NOT THE TIME TO START YET", 45, 17);
						else printtext("It was late to register the course", 45, 17);
						Sleep(1800);
						textBgColor(0, 15);
					}
				}
				catch (const char* err) {
					string s = string(err);
					s.pop_back();
					s += " to enroll.";
					drawRectangle(3, 14, 115, 3, 4);
					printtext(s, 45, 15);
					textBgColor(0, 15);
					Sleep(1800);
				}
				break;
			}
			case 1: {
				//lenh xoa bot khoa hoc da dang ki
				try {
					int check = checkCourseSession();
					if (check == 1) {
						delete_course(user, SY);
						system("pause");
					}
					else {
						drawRectangle(35, 15, 50, 5, 4);
						textBgColor(15, 4);
						if (check == 0) printtext("NOT OPEN REGISTER COURSE YET", 45, 17);
						else if (check == -1) printtext("IT'S NOT THE TIME TO START YET", 45, 17);
						else printtext("It was late to register the course", 45, 17);
						Sleep(1800);
						textBgColor(0, 15);
					}
				}
				catch (const char* err) {
					string s = string(err);
					s.pop_back();
					s += " to delete.";
					drawRectangle(3, 14, 115, 3, 4);
					printtext(s, 45, 15);
					textBgColor(0, 15);
					Sleep(1800);
				}
				break;
			}
			case 2: {
				DisPlay_Course_Of_Student(SY, user);
				break;
			}
			default: {
				break;
			}
			}
			break;
		}
		case 2: {
			// lenh show bang diem
			DisPlay_Mark_Of_Student(SY, user);
			break;
		}
		case 3:	{
			isExit = true;
			break;
		}
		}
	} while (!isExit);
	repeatLogin(user);
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