#include"Menu.h"
#include"Login.h"
#include"ConsoleProcess.h"
#include "read_data.h"
#include "change_info.h"
void menuStaff(User &user)
{	
	showPointer();
	bool isExit = false;
	read_info(user);
	int option;
	do
	{	
		system("cls");
		std::cout << "==================MENU============\n"
			<< "1. Profile info\n"
			<< "2. Change password\n"
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
			<<"15. View score board of a class\n"
			<< "0. Log out\n"
			<< " ---------------------\n"
			<< " your choice: ";
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
			<< " ---------------------\n"
			<< " your choice: ";
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