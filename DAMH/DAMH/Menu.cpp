#include"Menu.h"
#include"Login.h"
#include"ConsoleProcess.h"
#include "read_data.h"
#include "change_info.h"
#include"staffFunction.h"
#include "Course_function.h"
#include "ListClass.h"
#include "AddStudent.h"
void printASCIIStaffMeNu() {
	printtext("     ___                   ___", 40, 1);
	printtext("    /  /\\     ___         /  /\\  ", 40, 2);
	printtext("   /  /::\\   /__/\\       /  /::\\  ", 40, 3);
	printtext("  /__/:/\\:\\  \\  \\:\\     /  /:/\\:\\ ", 40, 4);
	printtext(" _\\_ \\:\\ \\:\\  \\__\\:\\   /  /::\\ \\:\\", 40, 5);
	printtext("/__/\\ \\:\\ \\:\\ /  /::\\ /__/:/\\:\\_\\:\\", 40, 6);
	printtext("\\  \\:\\ \\:\\_\\//  /:/\\:\\\\__\\/  \\:\\/:/", 40, 7);
	printtext(" \\  \\:\\_\\:\\ /  /:/__\\/     \\__\\::/ ", 40, 8);
	printtext("  \\  \\:\\/://__/:/          /  /:/  ", 40, 9);
	printtext("   \\  \\::/ \\__\\/          /__/:/   ", 40, 10);
	printtext("    \\__\\/                 \\__\\/   ", 40, 11);

	printtext("           ___          ___     ", 40, 12);
	printtext("          /  /\\        /  /\\   ", 40, 13);
	printtext("         /  /::\\      /  /::\\  ", 40, 14);
	printtext("        /  /:/\\:\\    /  /:/\\:\\  ", 40, 15);
	printtext("       /  /::\\ \\:\\  /  /::\\ \\:\\ ", 40, 16);
	printtext("      /__/:/\\:\\ \\:\\/__/:/\\:\\ \\:\\", 40, 17);
	printtext("      \\__\\/  \\:\\_\\/\\__\\/  \\:\\_\\/", 40, 18);
	printtext("           \\  \\:\\       \\  \\:\\  ", 40, 19);
	printtext("            \\__\\/        \\__\\/  ", 40, 20);

	printtext("       ___          ___  ", 75, 1);
	printtext("      /  /\\        /  /\\", 75, 2);
	printtext("     /  /::|      /  /::\\ ", 75, 3);
	printtext("    /  /:|:|     /  /:/\\:\\ ", 75, 4);
	printtext("   /  /:/|:|__  /  /::\\ \\:\\", 75, 5);
	printtext("  /__/:/_|::::\\/__/:/\\:\\ \\:\\", 75, 6);
	printtext("  \\__\\/  /~~/:/\\  \\:\\ \\:\\_\\/", 75, 7);
	printtext("        /  /:/  \\  \\:\\ \\:\\  ", 75, 8);
	printtext("       /  /:/    \\  \:\\_\\/  ", 75, 9);
	printtext("      /__/:/      \\  \\:\\    ", 75, 10);
	printtext("      \\__\\/        \\__\/    ", 75, 11);
	printtext("       ___          ___    ", 75, 12);
	printtext("      /  /\\        /  /\\    ", 75, 13);
	printtext("     /  /::|      /  /:/   ", 75, 14);
	printtext("    /  /:|:|     /  /:/    ", 75, 15);
	printtext("   /  /:/|:|__  /  /:/     ", 75, 16);
	printtext("  /__/:/ |:| /\\/__/:/     /\\", 75, 17);
	printtext("  \\__\\/  |:|/:/\\  \\:\\    /:/", 75, 18);
	printtext("      |  |:/:/  \\  \\:\\  /:/ ", 75, 19);
	printtext("      |__|::/    \\  \\:\\/:/  ", 75, 20);
	printtext("      /__/:/      \\  \\::/  ", 75, 21);
	printtext("      \\__\\/        \\__\\/  ", 75, 22);
}
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
		std::cout << "==============================\n";
		gotoxy(0, 7);
		std::cout<<"1. Profile info\n"
			<< "2. Change password\n"
			<< "3. Create school-year\n"
			<< "4. Create class\n"
			<< "5. Create course\n"
			<< "6. Create course registration session\n"
			<< "7. Add student to class\n"
			<< "8. Create semester\n "
			<< "9. Edit student's marks\n"
			<< "10. View list of course,Delete a course \n"
			<< "update course information\n"
			<< "11. Export student list\n"
			<< "12. Import student list\n"
			<< "13. View score board of a course\n"
			<< "14. View score board of a class\n"
			<< "0. Log out\n"
			<< " -----------------------------\n";
		std::cout << "Your choice: ";
		printASCIIStaffMeNu();
		gotoxy(14, 24);
		std::cin >> option;
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
			cin.ignore();
			addSchoolYear(SY);
			break;
		case 4:
			system("cls");
			RunMenuViewListClass();
			break;
		case 5:
			// lenh them khoa hoc
			cin.ignore();
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
			/*RunMenuAddInfoStudentToClass();*/
			break;
		case 8: 
			//lenh them hoc ki
			cin.ignore();
			addSemester(SY.year, SY.semester.Name);
			break;
		case 9:
			//edit diem sinh vien
			system("cls");
			printASCIIStaffMeNu();
			printtext("1. From List Class.",0,14);
			printtext("2. From List Course.", 0, 15);
			printtext("3. Exit to Menu.", 0, 16);
			printtext("YOUR CHOICE: ", 0, 17);

			cin >> option;
			switch (option)
			{
			case 1: {
				listClass(SY);
				break;
			}
			case 2: {
				Course* SLC = select_course(user, SY, &read_file_List_course,&drawASCIIlistCourse);
				edit_score_in_list_course(user, SY, SLC->ID_course);
			}
			default:
				break;
			}
			break;
		case 10:
			//view danh sachs hoc phan
			cin.ignore();
			listCourse(SY.year, SY.semester.Name);
			break;
		case 11:
			//xuat diem hoc sinh vao file
			exportScoreboardInterface(SY.year, SY.semester.Name, 2, 2, 1);
			break;
		case 12:
			//xuat diem hoc sinh vao file
			cin.ignore();
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
			break;
		case 0:
			isExit = true;
			break;
		default: std::cout << "your choice is invalid!!!\n";
		}
	} while (!isExit);
	std::cin.ignore();
	repeatLogin(user);
}
void menuStudent(User &user)
{
	showPointer();
	SchoolYear SY;
	determineYearSemesterNow(SY.year, SY.semester.Name);
	read_info(user,SY);
	init_List_Mark(user.info.phead);
	get_course(user,SY);
	bool isExit = false;
	int option;
	do
	{
		system("cls");
		gotoxy(45, 8);
		std::cout << "==================MENU============\n";
		gotoxy(45, 9); std::cout << "1. Profile info\n";
		gotoxy(45, 10); std::cout << "2. Change password\n";
		gotoxy(45, 11); std::cout << "3. List of student in class\n";
		gotoxy(45, 12); std::cout << "4. Score board\n";
		gotoxy(45, 13); std::cout << "5. Enroll courses\n";
		gotoxy(45, 14); std::cout << "6. List of enrolled courses\n";
		gotoxy(45, 15); std::cout << "7. Remove courses\n";
		gotoxy(45, 16); std::cout << "8. View your list of course\n";
		gotoxy(45, 17); std::cout << "0. Log out\n";
		gotoxy(45, 18); std::cout << " ---------------------\n";
		
		gotoxy(45, 20); std::cout << " your choice: ";
		printtext(" ______     ______   __  __     _____     ______     __   __     ______  ", 20, 1);
		printtext("/\\  ___\\   /\\__  _\\ /\\ \\/\\ \\   /\\  __-.  /\\  ___\\   /\\ \"-.\\ \\   /\\__  _\\ ", 20, 2);
		printtext("\\ \\___  \\  \\/_/\\ \\/ \\ \\ \\_\\ \\  \\ \\ \\/\\ \\ \\ \\  __\\   \\ \\ \\-.  \\  \\/_/\\ \\/ ", 20, 3);
		printtext(" \\/\\_____\\    \\ \\_\\  \\ \\_____\\  \\ \\____-  \\ \\_____\\  \\ \\_\\\\\"\\_\\    \\ \\_\\ ", 20, 4);
		printtext("  \\/_____/     \\/_/   \\/_____/   \\/____/   \\/_____/   \\/_/ \\/_/     \\/_/", 20, 5);
		printtext(" __    __     ______     __   __     __  __    ", 30, 23);
		printtext("/\\ \"-./  \\   /\\  ___\\   /\\ \"-.\\ \\   /\\ \\/\\ \\", 30, 24);   
		printtext("\\ \\ \\-./\\ \\  \\ \\  __\\   \\ \\ \\-.  \\  \\ \\ \\_\\ \\ ", 30, 25);
		printtext(" \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\ \\_\\\\\"\\_\\  \\ \\_____\\ ", 30, 26);
		printtext("  \\/_/  \\/_/   \\/_____/   \\/_/ \\/_/   \\/_____/ ", 30, 27);
		gotoxy(60, 20);
		std::cin >> option;
		switch (option)
		{
		case 1:
			Output_info(user);
			break;
		case 2:
			change_password(user);
			break;
		case 3:

			break;
		case 4:
			// lenh show bang diem
			get_all_course(user, SY);
			DisPlay_Mark_Of_Student( SY, user);
			break;
		case 5:
		{
			enroll_course(user, SY);
			/*int check = checkCourseSession();
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
			break;*/
			break;
		}
		case 6: 
			DisPlay_Course_Of_Student(SY, user);
			//edit_score(user, SY, view_all_score_of_1_student(user, SY));
			/*edit_score_in_list_course(user, SY);*/
			break;
		case 7:
		{
			//lenh xoa bot khoa hoc da dang ki
			delete_course(user, SY);
			break;
		}
		case 8:
			DisPlay_Course_Of_Student(SY, user);
			break;
		case 0:
			isExit = true;
			break;
		default: std::cout << "option is invalid!!!\n";
			break;
		}
	} while (!isExit);
	std::cin.ignore();
	repeatLogin(user);
}