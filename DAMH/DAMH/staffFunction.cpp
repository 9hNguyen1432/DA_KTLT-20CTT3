#include"staffFunction.h"
#include"Header.h"
void createFolder(string namefolder) {
    const char* NameFolder = namefolder.c_str();
    int check = _mkdir(NameFolder);
    if (check) {
        cout << "Could not create folder"<<endl;
        exit(1);
    }
    else {
        cout << "Folder created";
    }
    return;
}

void addSchoolYear() {
    string year;

    while (true) {
        cout << "Enter school year (Ex:2020-2021,..) : ";
        getline(cin, year);

        fstream file1, file2;
        bool check = true;
        file1.open("file_save//year-semester.csv", ios::in);
        file2.open("file_save//year-semester.csv", ios::in);

        string row, column;
        getline(file1, row);
        getline(file2, column);
        while (!file1.eof()) {
            getline(file2, column, ',');
            if (column.compare(year) == 0) {
                cout << "SCHOOL YEAR EXIST !";
                check = false;
                break;
            }
            getline(file1, row);
            getline(file2, column);
        }
        if (check == true) break;
    }

    string nameFolder = "file_save//SchoolYear//" + year;
    createFolder(nameFolder);
}



