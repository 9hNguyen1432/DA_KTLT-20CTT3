#include"ConsoleProcess.h"
#include "login.h"
#include "Menu.h"
#include"Header.h"
#include<stdio.h> 
#include<conio.h> 

void insertUserName(string& username) {
    showPointer();
    char index=getch();
    while (index != 13) {
        //Backspace
        if (index == 8) {
            if (username.size() > 0) {
                username.pop_back();
                gotoxy(ReturnX() - 1, ReturnY());
                cout << " ";
                gotoxy(ReturnX() - 1, ReturnY());
            }
        }
        //Other index
        else if (index >= 33 && index <= 126 && username.size()<=15) {
            cout << index;
            username.push_back(index);
        }
        index = getch();
    }
}

void insertPassword(string& password) {
    showPointer();
    password = "";
    char index = getch();
    while (index != 13) {
        //Backspace
        if (index == 8) {
            if (password.size() > 0) {
                password.pop_back();
                gotoxy(ReturnX() - 1, ReturnY());
                cout << " ";
                gotoxy(ReturnX() - 1, ReturnY());
            }
        }
        //Other index
        else if (index >= 33 && index <= 126 && password.size() <= 15) {
            cout << "*";
            password.push_back(index);
        }
        index = getch();
    }
}

void LoginInterface(User &user){
    
    showPointer();
    textBgColor(2, 0);
    system("cls");

    user.ID=user.Password="";

    
    printtext("  _   _   ____  __  __  _   _  ____", 2, 15);
    printtext(" | | | | / ___||  \\/  || | | |/ ___|", 2, 16);
    printtext(" | |_| || |    | |\\/| || | | |\\___ \\", 2, 17);
    printtext(" |  _  || |___ | |  | || |_| | ___) |", 2, 18);
    printtext(" |_| |_| \\____||_|  |_| \\___/ |____/",2, 19);


    printtext("  _____  ___  _____", 86, 15);
    printtext(" |  ___||_ _||_   _|", 86, 16);
    printtext(" | |_    | |   | |", 86, 17);
    printtext(" |  _|   | |   | |", 86, 18);
    printtext(" |_|    |___|  |_|", 86, 19);
    printtext(" __  __    _    _   _    _    ____ _____ ____", 38, 0);
    printtext("|  \\/  |  / \\  | \\ | |  / \\  / ___| ____|  _ \\ ", 38, 1);
    printtext("| |\\/| | / _ \\ |  \\| | / _ \\| |  _|  _| | |_) |", 38, 2);
    printtext("| |  | |/ ___ \\| |\\  |/ ___ \\ |_| | |___|  _ <", 38, 3);
    printtext("|_|  |_/_/   \\_\\_| \\_/_/   \\_\\____|_____|_| \\_\\ ", 38, 4);


    printtext(" ____ _____ _   _ ____  _____ _   _ _____", 40, 6);
    printtext("/ ___|_   _| | | |  _ \\| ____| \\ | |_   _|", 40, 7);
    printtext("\\___ \\ | | | | | | | | |  _| |  \\| | | |", 40, 8);
    printtext(" ___) || | | |_| | |_| | |___| |\\  | | |", 40, 9);
    printtext("|____/ |_|  \\___/|____/|_____|_| \\_| |_|", 40, 10);

    textColor(0);
    drawRectangle(47, 15, 27, 10, 11);
    printtext("USERNAME : ", 48, 16);
    printtext("PASSWORD : ", 48, 19);

    drawRectangle(48, 17, 25, 1, 15);
    drawRectangle(48, 20, 25, 1, 15);
    gotoxy(48, 22);
    cout << "ENTER TO LOGIN";

    gotoxy(48,17);
    insertUserName(user.ID);

    gotoxy(48,20);
    insertPassword(user.Password);
}

int CheckLogin(User& user) {
    fstream file1,file2;
    file1.open("file_save/login_info.csv",ios::in);
    file2.open("file_save/login_info.csv",ios::in);

    if (!file1.is_open() || !file2.is_open())    
   	    cout << "Error File Open";
    
    string row,column;
    int caseUser;
    bool check=false;
    while (!file1.eof())
    {   
        getline(file1,row);
        while (!file2.eof())
        {
            getline(file2,column,',');
            if (column.compare(user.ID)==0) {
                getline(file2,column,',');
                if (column.compare(user.Password)==0) {
                    check=true;
                    getline(file2, column, ',');
                    caseUser = stoi(column, 0, 10);
                    break;
                }
            }
            getline(file2,column);
            break;
        }
        if (check==true) break;    
    }
    
    if (check==false) return -1;
    
    user.role = caseUser;
    if (caseUser == 1) {
        getline(file2, column, '\n');
        user.info.Class = column;
    }

    file1.close();
    file2.close();
    
    return caseUser;
}

void repeatLogin(User &user){
    textColor(0);
    
    do
	{   
        system("cls");
		LoginInterface(user);
        
		if (CheckLogin(user) ==-1)
		{   
			gotoxy(48, 24);
			cout<<"LOGIN FAIL";
            hidePointer();
			Sleep(900);
		}
	} 
    while (CheckLogin(user) == -1);
    gotoxy(48, 24);
    cout<<"LOGIN SUCCESSFUL";
    hidePointer();
    Sleep(900);
    system("cls");
    if (user.role==1) menuStudent(user);
    else menuStaff(user);
}



