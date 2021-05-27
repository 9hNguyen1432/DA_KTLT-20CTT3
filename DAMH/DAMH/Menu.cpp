#include"Menu.h"
#include"Login.h"
#include"ConsoleProcess.h"
#include "read_data.h"
void menuStaff(User &user)
{	
	showPointer();
	bool isExit = false;
	read_info(user);
	int option;
	do
	{	
		system("cls");
		std::cout << "==============================\n";
		printtext(" 1. Profile info\n", 1, 8);
		std::cout	<< "2. Change password\n"
			<< "3. Create school-year\n"
			<< "4. Create class\n"
			<< "5. Create course\n"
			<< "6. Add student to class\n"
			<< "7. Create semester\n "
			<< " 8. Edit student's information\n"
			<< "9. Edit student's marks"
			<< "10. view list of course\n"
			<< "11. Delete a course\n"
			<< "12. Update course information\n"
			<< "13. Export student list"
			<< "14. View score board of a course\n"
			<< "15. View score board of a class\n"
			<< "0. Log out\n"
			<< " ---------------------\n";
		std::cout << " your choice: ";
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
		printtext("     /  /::|      /  /::\\ ", 75,3);
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
			
			
		std::cin >> option;
		switch (option)
		{
		case 1:
			// lenh show thong tin 
			Output_info(user);
			break;
		case 2:
			// lenh thay mat khau
			break;
		case 3:
			// lenh them nam hoc
			break;
		case 4:
			// lenh them lop hoc
			break;
		case 5:
			// lenh them khoa hoc
			break;
		case 6:
			//lenh them hoc snh vao lop
			break;
		case 7:
			//lenh them hoc ki
			break;
		case 8: 
			//lenh chinh thong tin sinh vien
			break;
		case 9:
			//edit diem sinh vien
			break;
		case 10:
			//view danh sachs hoc phan
			break;
		case 11:
			//xoa hoc phan
			break;
		case 12:
			//update thong tin hoc phan
			break;
		case 13:
			//xuat thong tin hoc sinh vao file
			break;
		case 14:
			//view diem cua khoa hoc
			break;
		case 15:
			//view diem cua lop hoc
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
	read_info(user);
	bool isExit = false;
	int option;
	do
	{
		system("cls");
		std::cout << "==================MENU============\n"
			<< "1. Profile info\n"
			<< "2. Change password\n"
			<< "3. List of classes\n"
			<< "4. List of student in class\n"
			<< "5. List of student in a course\n"
			<< "6. Score board\n"
			<< "7. Enroll courses\n"
			<< "8. List of enrolled courses\n"
			<< "9. Remove courses\n"
			<< "0. Log out\n"
			<< " ---------------------\n";
		textColor(10);

		printtext("           ___", 50, 1);
		printtext("          /  /\\     ___  ", 50, 2);
		printtext("         /  /::\\   /__/\\   ", 50, 3);
		printtext("        /__/:/\\:\\  \\  \\:\\   ", 50, 4);
		printtext("       _\\_ \\:\\ \\:\\  \\__\\:\\  ", 50, 5);
		printtext("      /__/\\ \\:\\ \\:\\ /  /::\\ ", 50, 6);
		printtext("      \\  \\:\\ \\:\\_\\//  /:/\\:\\", 50, 7);
		printtext("       \\  \\:\\_\\:\\ /  /:/__\\/", 50, 8);
		printtext("        \\  \\:\\/://__/:/    ", 50, 9);
		printtext("         \\  \\::/ \\__\\/      ", 50, 10);
		printtext("          \\__\\/             ", 50, 11);
		printtext("       ___          ___     ", 50, 12);
		printtext("      /  /\\        /  /\\    ", 50, 13);
		printtext("     /  /:/       /  /::\\   ", 50, 14);
		printtext("    /  /:/       /  /:/\\:\\  ", 50, 15);
		printtext("   /  /:/       /  /:/  \\:\\ ", 50, 16);
		printtext("  /__/:/     /\\/__/:/ \\__\\:|", 50, 17);
		printtext("  \\  \\:\\    /:/\\  \\:\\ /  /:/", 50, 18);
		printtext("   \\  \\:\\  /:/  \\  \\:\\  /:/ ", 50, 19);
		printtext("    \\  \\:\\/:/    \\  \\:\\/:/  ", 50, 20);
		printtext("     \\  \\::/      \\__\\::/   ", 50, 21);
		printtext("      \\__\\/           ~~    ", 50, 22);
		printtext("       ___          ___     ", 50, 23);
		printtext("      /  /\\        /  /\\    ", 50, 24);
		printtext("     /  /::\\      /  /::|   ", 50, 25);
		printtext("    /  /:/\\:\\    /  /:|:|   ", 50, 26);
		printtext("   /  /::\\ \\:\\  /  /:/|:|__ ", 50, 27);
		printtext("  /__/:/\\:\\ \\:\\/__/:/ |:| /\\", 50, 28);
		printtext("  \\  \\:\\ \\:\\_\\/\\__\\/  |:|/:/", 50, 29);
		printtext("   \\  \\:\\ \\:\\      |  |:/:/ ", 50, 30);
		printtext("    \\  \\:\\_\\/      |__|::/  ", 50, 31);
		printtext("     \\  \\:\\        /__/:/   ", 50, 32);
		printtext("      \\__\\/        \\__\\/    ", 50, 85);

		printtext("                    ___     ", 50, 35);
		printtext("                   /__/\\    ", 50, 36);
		printtext("                   \\  \\:\\   ", 50, 37);
		printtext("                    \\__\\:\\  ", 50, 38);
		printtext("                    /  /::\\ ", 50, 39);
		printtext("                   /  /:/\\:\\", 50, 2);
		printtext("                  /  /:/__\\/", 50, 41);
		printtext("                 /__/:/     ", 50, 42);
		printtext("                 \\__\\/     ", 50, 43);
		textColor(14);
		printtext("       ___          ___  ", 85, 1);
		printtext("      /  /\\        /  /\\", 85, 2);
		printtext("     /  /::|      /  /::\\ ", 85, 3);
		printtext("    /  /:|:|     /  /:/\\:\\ ", 85, 4);
		printtext("   /  /:/|:|__  /  /::\\ \\:\\", 85, 5);
		printtext("  /__/:/_|::::\\/__/:/\\:\\ \\:\\", 85, 6);
		printtext("  \\__\\/  /~~/:/\\  \\:\\ \\:\\_\\/", 85, 7);
		printtext("        /  /:/  \\  \\:\\ \\:\\  ", 85, 8);
		printtext("       /  /:/    \\  \:\\_\\/  ", 85, 9);
		printtext("      /__/:/      \\  \\:\\    ", 85, 10);
		printtext("      \\__\\/        \\__\/    ", 85, 11);
		printtext("       ___          ___    ", 85, 12);
		printtext("      /  /\\        /  /\\    ", 85, 13);
		printtext("     /  /::|      /  /:/   ", 85, 14);
		printtext("    /  /:|:|     /  /:/    ", 85, 15);
		printtext("   /  /:/|:|__  /  /:/     ", 85, 16);
		printtext("  /__/:/ |:| /\\/__/:/     /\\", 85, 17);
		printtext("  \\__\\/  |:|/:/\\  \\:\\    /:/", 85, 18);
		printtext("      |  |:/:/  \\  \\:\\  /:/ ", 85, 19);
		printtext("      |__|::/    \\  \\:\\/:/  ", 85, 20);
		printtext("      /__/:/      \\  \\::/  ", 85, 21);
		printtext("      \\__\\/        \\__\\/  ", 85, 22);
		std::cout	<< " your choice: ";
		std::cin >> option;
		switch (option)
		{
		case 1:
			Output_info(user);
			break;
		case 2:
			// lenh thay doi mat khau
			break;
		case 3:
			// lenh show danh sach cac lop
			break;
		case 4:
			//lenh show danh sach hoc sinh trong 1 lop
			break;
		case 5:
			//lenh show danh sach hoc sinh trong 1 khoa hoc
			break;
		case 6: 
			// lenh show bang diem
			break;
		case 7:
			//lenh dang ki khoa hoc
			break;
		case 8:
			//lenh show danh sach khoa hoc da dang ki
			break;
		case 9:
			//lenh xoa bot khoa hoc da dang ki
			break;
		case 0:
			isExit = true;
			break;
		default: std::cout << "option is invalid!!!\n";

		}
	} while (!isExit);
	std::cin.ignore();
	repeatLogin(user);
}