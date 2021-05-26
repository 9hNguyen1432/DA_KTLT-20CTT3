#include"ConsoleProcess.h"
#include "login.h"
#include "Menu.h"

void LoginInterface(User &user){
    
    showPointer();
    textBgColor(2, 0);
    system("cls");

    user.ID=user.Password="";

    
    gotoxy(2, 15);
    cout << "  _   _   ____  __  __  _   _  ____";
    gotoxy(2, 16);
    cout << " | | | | / ___||  \\/  || | | |/ ___|";
    gotoxy(2, 17);
    cout << " | |_| || |    | |\\/| || | | |\\___ \\";
    gotoxy(2, 18);
    cout << " |  _  || |___ | |  | || |_| | ___) |";
    gotoxy(2, 19);
    cout << " |_| |_| \\____||_|  |_| \\___/ |____/" ;


    gotoxy(86, 15);
    cout << "  _____  ___  _____" ;
    gotoxy(86, 16);
    cout << " |  ___||_ _||_   _|" ;
    gotoxy(86, 17);
    cout << " | |_    | |   | |" ;
    gotoxy(86, 18);
    cout << " |  _|   | |   | |" ;
    gotoxy(86, 19);
    cout << " |_|    |___|  |_|" ;

    gotoxy(38, 0);
    cout << " __  __    _    _   _    _    ____ _____ ____";
    gotoxy(38, 1);
    cout << "|  \\/  |  / \\  | \\ | |  / \\  / ___| ____|  _ \\ ";
    gotoxy(38, 2);
    cout << "| |\\/| | / _ \\ |  \\| | / _ \\| |  _|  _| | |_) |";
    gotoxy(38, 3);
    cout << "| |  | |/ ___ \\| |\\  |/ ___ \\ |_| | |___|  _ <";
    gotoxy(38, 4);
    cout << "|_|  |_/_/   \\_\\_| \\_/_/   \\_\\____|_____|_| \\_\\ ";

    gotoxy(40, 6);
    cout << " ____ _____ _   _ ____  _____ _   _ _____";
    gotoxy(40, 7);
    cout << "/ ___|_   _| | | |  _ \\| ____| \\ | |_   _|";
    gotoxy(40, 8);
    cout << "\\___ \\ | | | | | | | | |  _| |  \\| | | |";
    gotoxy(40, 9);
    cout << " ___) || | | |_| | |_| | |___| |\\  | | |";
    gotoxy(40, 10);
    cout << "|____/ |_|  \\___/|____/|_____|_| \\_| |_|";
    
    textColor(0);
    drawRectangle(47, 15, 27, 10, 11);
    gotoxy(48, 16);
    cout<<"USERNAME : ";
    gotoxy(48,19);
    cout<<"PASSWORD : ";
    
    drawRectangle(48, 17, 25, 1, 15);
	drawRectangle(48, 20, 25, 1, 15);
	gotoxy(48, 22);
	cout<<"ENTER TO LOGIN";
    gotoxy(48,17);
    getline(cin,user.ID);
    gotoxy(48,20);
    getline(cin,user.Password);
}

int CheckLogin(string& ID, string& password) {
    fstream file1,file2;
    file1.open("login_info.csv",ios::in);
    file2.open("login_info.csv",ios::in);

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
            if (column.compare(ID)==0) {
                getline(file2,column,',');
                if (column.compare(password)==0) {
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
    file1.close();
    file2.close();
    if (check==false) return -1;
    else return caseUser;
}

void repeatLogin(User &user){
    textColor(0);
    
    do
	{   
        system("cls");
		LoginInterface(user);
        
		if (CheckLogin(user.ID, user.Password) ==-1)
		{   
			gotoxy(48, 24);
			cout<<"LOGIN FAIL";
            hidePointer();
			Sleep(900);
		}
	} 
    while (CheckLogin(user.ID, user.Password) == -1);
    
    gotoxy(48, 24);
    cout<<"LOGIN SUCCESSFUL";
    hidePointer();
    Sleep(900);
    system("cls");
    if (CheckLogin(user.ID, user.Password) == 1) menuStudent(user);
    else menuStaff(user);

}



