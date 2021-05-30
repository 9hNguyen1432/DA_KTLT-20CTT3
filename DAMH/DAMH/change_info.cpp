#include <stdio.h>
#include "Header.h"
#include"ConsoleProcess.h"
#include"login.h"
void rewrite_info_file(User user) {
    fstream file_prv, file_aft;
    string oldName = "file_save/login_info.csv";
    string newName = "file_save/login_info_new.csv";
    file_prv.open(oldName, ios::in);
    file_aft.open(newName, ios::out);
    string temp;
    while (file_prv.eof() == false) {
        getline(file_prv, temp,',');
        file_aft << temp<<',';
        if (user.ID.compare(temp)!=0) {
            getline(file_prv, temp);
            file_aft << temp<<'\n';
        }
        else {
            getline(file_prv, temp);
            string temp1 = user.Password + ',' + to_string(user.role);
            if (user.role == 1) {
                temp1 =temp1 +','+ user.info.Class;
            }
            file_aft << temp1<<'\n';
        }
    }
    file_prv.close();
    file_aft.close();
    // removing the existing file
    remove(oldName.c_str());
    // renaming the updated file with the existing file name
    rename(newName.c_str(), oldName.c_str());
};
void change_password(User& A) {
    system("cls");
    printtext(" _____  _____  _____  _____  _____  _____    _____  _____  _____  _____  _ _ _  _____  _____  ____  ", 10, 4);
    printtext("|     ||  |  ||  _  ||   | ||   __||   __|  |  _  ||  _  ||   __||   __|| | | ||     || __  ||    \\ ", 10, 5);
    printtext("|   --||     ||     || | | ||  |  ||   __|  |   __||     ||__   ||__   || | | ||  |  ||    -||  |  |", 10, 6);
    printtext("|_____||__|__||__|__||_|___||_____||_____|  |__|   |__|__||_____||_____||_____||_____||__|__||____/ ", 10, 7);
    drawRectangle(47, 15, 27, 12, 11);
    printtext("YOUR PASSWORD :", 48, 16);
    printtext("ENTER NEW PASSWORD :", 48, 19);
    printtext("ENTER NEW PASSWORD AGAIN :", 48, 22);

    drawRectangle(48, 17, 25, 1, 15);
    drawRectangle(48, 20, 25, 1, 15);
    drawRectangle(48, 23, 25, 1, 15);
    gotoxy(48, 17);
    string temp;
    insertPassword(temp);
    if (temp.compare(A.Password) == 0) {
        gotoxy(48, 20);
        string temp1;
        insertPassword(temp);
        gotoxy(48, 23);
        insertPassword(temp1);
        if (temp.compare(temp1) == 0) {
            A.Password = temp;
            gotoxy(46, 25);
            cout << "Change password successfully \n";
            rewrite_info_file(A);
        }
        else {
            gotoxy(48, 25);
            cout << "Password does not match.\n";
        }
    }
    else {
        gotoxy(48,18);
        cout << "Incorrect password. \n";
    }
    system("pause");
}
