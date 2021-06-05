#include"staffFunction.h"
#include"Header.h"
#include"ConsoleProcess.h"


void createFolder(string namefolder) {
    const char* NameFolder = namefolder.c_str();
    int check = _mkdir(NameFolder);
    if (check) {
        cout << "Could not create folder"<<endl;
        exit(1);
    }
    return;
}

bool IsPathExist(const std::string& s)
{
    struct stat buffer;
    return (stat(s.c_str(), &buffer) == 0);
}

void addSchoolYear() {
    SchoolYear schoolyear;
    char ch;
    system("cls");
    textBgColor(13, 15);

    printtext(" ____   ____ _   _  ___   ___  _      __   _______    _    ____", 35, 2);
    printtext("/ ___| / ___| | | |/ _ \\ / _ \\| |     \\ \\ / / ____|  / \\  |  _ \\", 35, 3);
    printtext("\\___ \\| |   | |_| | | | | | | | |      \\ V /|  _|   / _ \\ | |_) |", 35, 4);
    printtext(" ___) | |___|  _| |_| | |_| | | |___    | | | |___ / ___ \\|  _ <", 35, 5);
    printtext("|____/ \\____|_| |_|\\___/ \\___/|_____|   |_| |_____/ _ / \\_\\_| \\_\\", 35, 6);
    while (true) {

        textBgColor(0, 11);
        drawRectangle(35, 8, 70, 7, 11);
        schoolyear.year = "";
        printtext("Enter school year (Ex:2020-2021,..) : ", 40, 10);
        drawRectangle(40, 11, 50, 1, 15);
        gotoxy(40, 11);
        getline(cin, schoolyear.year);

        fstream file1, file2;
        bool check = true;
        file1.open("file_save//year-semester.csv", ios::in);
        file2.open("file_save//year-semester.csv", ios::in);

        string row, column;
        getline(file1, row);
        getline(file2, column);
        while (!file1.eof()) {
            getline(file2, column, ',');
            if (column.compare(schoolyear.year) == 0) {
                textBgColor(4, 11);
                printtext("SCHOOL YEAR EXIST ! PRESS ENTER TO TRY AGAIN", 40, 14);
                hidePointer();
                ch = getch();
                drawRectangle(40, 11, 50, 1, 15);
                drawRectangle(40, 14, 60, 1, 11);
                showPointer();
                check = false;
                break;
            }
            getline(file1, row);
            getline(file2, column);
        }
        if (check == true) break;
    }

    string nameFolder = "file_save//SchoolYear//" + schoolyear.year;
    createFolder(nameFolder);

    fstream file;
    string data;
    file.open("file_save//year-semester.csv", ios::app);
    file << schoolyear.year << ",0"<<endl;
    file.close();

    hidePointer();
    textBgColor(10, 11);
    printtext("CREATE SCHOOL YEAR SUCCESSFUL,PRESS ENTER TO BACK TO MENU !!!", 40, 14);
    ch = getch();
    textBgColor(0, 15);
}

void insertNameSemester(string& name) {
    char word;
    do {
        word = getch();
        if (word == 8) {
            if (name.size() > 0) {
                name.pop_back();
                gotoxy(ReturnX() - 1, ReturnY());
                cout << " ";
                gotoxy(ReturnX() - 1, ReturnY());
            }
        }
        else if (word >= 49 && word <= 51 && name.size()<1 ) {
            cout << word;
            name.push_back(word);
        }
    } while (word != 13);
}

void insertDate(string& Date) {
    int x = ReturnX(), y = ReturnY() ;
    char word;
    do {
        word = getch();
        if (word == 8) {
            if (Date.size() > 0) {
                Date.pop_back();
                gotoxy(ReturnX() - 1, ReturnY());
                cout << " ";
                gotoxy(ReturnX() - 1, ReturnY());
            }
        }
        else if (word >= 47 && word <= 57 && Date.size() < 10) {
            cout << word;
            Date.push_back(word);
        }
    } while (word != 13 || Date.size()<10);
}

void insertSchoolYear(string& SchoolYear) {
    int x = ReturnX(), y = ReturnY();
    char word;
    do {
        word = getch();
        if (word == 8) {
            if (SchoolYear.size() > 0) {
                SchoolYear.pop_back();
                gotoxy(ReturnX() - 1, ReturnY());
                cout << " ";
                gotoxy(ReturnX() - 1, ReturnY());
            }
        }
        else if (((word >= 48 && word <= 57) || word == 45) && SchoolYear.size() < 9) {
            cout << word;
            SchoolYear.push_back(word);
        }

    } while (word != 13 || SchoolYear.size() < 9);
}

int checkSchoolYear(Semester semester)
{   
    string a, b;
    for (int i = 0; i < 4; i++) a.push_back(semester.schoolyear[i]);
    for (int i = 5; i < 9; i++) b.push_back(semester.schoolyear[i]);
    //Không thõa mãn định dạng nhập yyyy-yyyy
    if (stoi(a, 0, 10) >= stoi(b, 0, 10) || semester.schoolyear[4] != 45 || (stoi(a, 0, 10) < 1000 || stoi(a, 0, 10) > 9999) || (stoi(b, 0, 10) < 1000 || stoi(b, 0, 10) > 9999))
        return 0;

    //Không tồn tại School Year
    if (IsPathExist("file_save//SchoolYear//" + semester.schoolyear) == false) return -1;

    //Kiểm tra thử trong School Year đã nhập đã có tồn tại semester vừa nhập chưa
    fstream file2;
    file2.open("file_save//year-semester.csv", ios::in);
    int check=1;
    string column;
    getline(file2, column);
    while (!file2.eof()) {
        getline(file2, column,',');
        if (column.compare(semester.schoolyear) == 0) {
            getline(file2, column,'\n');
            if (stoi(column, 0, 10) >= stoi(semester.Name, 0, 10)) check = -2;
            else if (stoi(semester.Name, 0, 10) - stoi(column, 0, 10) > 1) check = -3;
            break;
        }
        getline(file2, column);
    }
    file2.close();
    return check;
}

int checkDate(string Date) {
    string dd, mm, yyyy;
    dd.push_back(Date[0]);
    dd.push_back(Date[1]);
    mm.push_back(Date[3]);
    mm.push_back(Date[4]);
    yyyy.push_back(Date[6]);
    yyyy.push_back(Date[7]);
    yyyy.push_back(Date[8]);
    yyyy.push_back(Date[9]);
    if (Date.size() < 10 || Date.find('/') != 2 || Date.find('/', 3) != 5 || (Date[2] != 47 || Date[5] != 47) || (stoi(dd, 0, 10) < 1 || stoi(dd, 0, 10) > 31) || (stoi(mm, 0, 10) < 1 || stoi(mm, 0, 10) > 12) || (stoi(yyyy, 0, 10) < 1000 || stoi(yyyy, 0, 10) > 9999))
        return 0;
    return 1;
}

void UpDatefileCSV(Semester semester) {
    fstream file_old1, file_old2 , file_new;
    string data1,data2;
    file_old1.open("file_save//year-semester.csv", ios::in);
    file_old2.open("file_save//year-semester.csv", ios::in);
    file_new.open("file_save//year-semester_new.csv", ios::app);
    file_new << "Năm,số kì đã học " << endl;
    getline(file_old2, data2);
    getline(file_old1, data1);
    data1 = data2 = "";
    while (!file_old2.eof()) {
        getline(file_old2, data2);
        while (!file_old1.eof()) {
            getline(file_old1, data1, ',');
            if (data1.compare(semester.schoolyear) == 0) {
                file_new << data1<<",";
                getline(file_old1, data1);
                int a = stoi(data1, 0, 10);
                a++;
                file_new << to_string(a) << endl;
            }
            else file_new << data2 << endl;
            getline(file_old1, data1);
            break;
        }
    }
    file_old1.close();
    file_old2.close();
    file_new.close();
    remove("file_save//year-semester.csv");
    rename("file_save//year-semester_new.csv", "file_save//year-semester.csv");
}

void UpDatefileInfo(Semester semester) {
    fstream file;
    file.open("file_save//SchoolYear//" + semester.schoolyear + "//Semester" + semester.Name + "//SemesterInfo.txt", ios::app);
    file << "Semester: " << semester.Name << endl;
    file << "Start Date: " << semester.date_star << endl;
    file << "End Date: " << semester.date_end<<endl;
    file.close();
}


void addSemester() {
    char ch;
    Semester semester;
    system("cls");
    textBgColor(13, 15);
    printtext(" ____                           _", 40, 2);
    printtext("/ ___|  ___ _ __ ___   ___  ___| |_ ___ _ __", 40, 3);
    printtext("\\___ \\ / _ \\ '_ ` _ \\ / _ \\/ __| __/ _ \\ '__|", 40, 4);
    printtext("  ___)|  __/ | | | | |  __/\\__ \\ ||  __/ |", 40, 5);
    printtext("|____/ \\___|_| |_| |_|\\___||___/\\__\\___|_|", 40, 6);
   
    textBgColor(0, 11);
    drawRectangle(25, 8, 80, 12, 11);
    printtext("Enter semester (1,2 or 3):", 35, 10);
    printtext("Enter start date (dd/mm/yyyy):", 35, 12);
    printtext("Enter end date (dd/mm/yyyy):", 35, 14);
    printtext("Enter school year of the semester (Ex:2020-2021,...):", 35, 16);
    drawRectangle(35, 11, 35, 1, 15);
    drawRectangle(35, 13, 35, 1, 15);
    drawRectangle(35, 15, 35, 1, 15);
    drawRectangle(35, 17, 35, 1, 15);
   
    gotoxy(35, 11);
    insertNameSemester(semester.Name);

    do {
        gotoxy(35, 13);
        insertDate(semester.date_star);
        int check = checkDate(semester.date_star);
        if (check == 0) {
            textBgColor(4, 11);
            gotoxy(35, 19);
            hidePointer();
            cout << "ERROR: DATE MUST HAVE FORMAT LIKE DD/MM/YYYY (01/02/2020), PRESS ENTER TO TRY AGAIN";
            ch = getch();
            drawRectangle(35, 19, 41, 1, 11);
            drawRectangle(35, 13, 10, 1, 15);
            textBgColor(0, 15);
            semester.date_star.clear();
            showPointer();
        }
        else break;
    } while (true);
    
    do {
        gotoxy(35, 15);
        insertDate(semester.date_end);
        int check = checkDate(semester.date_end);
        if (check == 0) {
            textBgColor(4, 11);
            gotoxy(35, 19);
            hidePointer();
            cout << "ERROR: DATE MUST HAVE FORMAT LIKE DD/MM/YYYY (01/02/2020), PRESS ENTER TO TRY AGAIN";
            ch = getch();
            drawRectangle(35, 19, 41, 1, 11);
            drawRectangle(35, 15, 10, 1, 15);
            textBgColor(0, 15);
            semester.date_end.clear();
            showPointer();
        }
        else break;
    } while (true);

    do{
        gotoxy(35, 17);
        insertSchoolYear(semester.schoolyear);
        int check = checkSchoolYear(semester);
        if (check != 1) {
            hidePointer();
            textBgColor(4, 11);
            gotoxy(35, 19);
            if (check == 0)
                printtext("ERROR:SCHOOL YEAR MUST HAVE FORMAT LIKE YYYY-YYYY,PRESS ENTER TO TRY AGAIN", 30, 19);
            else if (check == -1)
                printtext("ERROR:SCHOOL YEAR WAS EXISTED, PRESS ENTER TO TRY AGAIN", 30, 19);
            else if (check == -2)
                printtext("ERROR:SEMESTER WAS EXISTED IN SCHOOL YEAR, PRESS ENTER TO TRY AGAIN", 30, 19);
            else if (check == -3)
                printtext("ERROR:SEMESTER ISN'T COME UP,PRESS ENTER TO TRY AGAIN", 30, 19);
            ch = getch();
            drawRectangle(30, 19, 70, 1, 11);
            drawRectangle(35, 17, 10, 1, 15);
            textBgColor(0, 15);
            semester.schoolyear = "";
            showPointer();
        }
        else break;
    } while (true);

    createFolder("file_save//SchoolYear//" + semester.schoolyear + "//Semester" + semester.Name);
    createFolder("file_save//SchoolYear//" + semester.schoolyear + "//Semester" + semester.Name + "//Class");
    createFolder("file_save//SchoolYear//" + semester.schoolyear + "//Semester" + semester.Name + "//Course");
    UpDatefileCSV(semester);
    UpDatefileInfo(semester);

    hidePointer();
    textBgColor(10,11);
    printtext("CREATE SEMESTER SUCCESSFUL,PRESS ENTER TO BACK TO MENU !!!", 35, 19);
    ch = getch();
    textBgColor(0, 15);
}

char* gettime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    return dt;
}
//12-21
/*
void updateFileRegistration() {
    fstream file,temp;
    string data, month[12] = { "Jan", "Feb", "Mar", "Apr", "May","Jun", "Jul", "Aug", "Sep", "Oct", "Nov","Dec" };
    file.open("file_save/RegistrationCourseSession.txt",ios::in);
    getline(file, data);
    if (stoi(data, 0, 10) == 1) {
        getline(file, data);
        string dt=gettime(),date;
        if (data.substr(18, 4).compare(dt.substr(20, 4)) =  = 0) {

        }
    }
}
*/

void createRegistrationCourse() {
    system("cls");
    string DateStart, DateEnd;
    char ch;
    textBgColor(13, 15);
    printtext("  ____ ____  _____    _  _____ _____    ____ ___  _   _ ____  ____  _____", 25, 2);
    printtext(" / ___|  _ \\| ____|  / \\|_   _| ____|  / ___/ _ \\| | | |  _ \\/ ___|| ____|", 25, 3);
    printtext("| |   | |_) |  _|   / _ \\ | | |  _|   | |  | | | | | | | |_) \\___ \\|  _|", 25, 4);
    printtext("| |___|  _< | |___ / ___ \\| | | |___  | |__| |_| | |_| |  _ < ___) | |___", 25, 5);
    printtext(" \\____|_| \\_\\_____/_/   \\_\\_| |_____|  \\____\\___/ \\___/|_| \\_\\____/|_____|", 25, 6);

    printtext(" ____  _____ ____ ___ ____ _____ ____      _  _____ ___ ___  _   _", 28, 8);
    printtext("|  _ \\| ____/ ___|_ _/ ___|_   _|  _ \\    / \\|_   _|_ _/ _ \\| \\ | |", 28, 9);
    printtext("| |_) |  _|| |  _ | |\\___ \\ | | | |_) |  / _ \\ | |  | | | | |  \\| |", 28, 10);
    printtext("|  _ <| |__| |_| || | ___) || | |  _ <  / ___ \\| |  | | |_| | |\\  |", 28, 11);
    printtext("|_| \\_\\_____\\____|___|____/ |_| |_| \\_\\/_/   \\_\\_| |___\\___/|_| \\_|", 28, 12);

    printtext(" ____  _____ ____ ____ ___ ___  _   _", 35, 14);
    printtext("/ ___|| ____/ ___/ ___|_ _/ _ \\| \\ | |", 35, 15);
    printtext("\\___ \\|  _| \\___ \\___ \\| | | | |  \\| |", 35, 16);
    printtext(" ___) | |___ ___) |__) | | |_| | |\\  |", 35, 17);
    printtext("|____/|_____|____/____/___\\___/|_| \\_|", 35, 18);

    drawRectangle(30, 20, 50, 7, 11);
    textBgColor(0, 11);
    printtext("START DATE (DD/MM/YYYY):", 35, 21);
    printtext("END DATE (DD/MM/YYYY):", 35, 24);
    drawRectangle(35, 22, 40, 1, 15);
    drawRectangle(35, 25, 40, 1, 15);

    do {
        gotoxy(35, 22);
        insertDate(DateStart);
        int check = checkDate(DateStart);
        if (check == 0) {
            textBgColor(4, 15);
            gotoxy(20, 28);
            hidePointer();
            cout << "ERROR: DATE MUST HAVE FORMAT LIKE DD/MM/YYYY (01/02/2020,..), PRESS ENTER TO TRY AGAIN";
            ch = getch();
            drawRectangle(20, 28, 90, 1, 15);
            drawRectangle(35, 22, 40, 1, 15);
            textBgColor(0, 15);
            DateStart.clear();
            showPointer();
        }
        else break;
    } while (true);

    do {
        gotoxy(35, 25);
        insertDate(DateEnd);
        int check = checkDate(DateEnd);
        if (check == 0) {
            textBgColor(4, 15);
            gotoxy(20, 28);
            hidePointer();
            cout << "ERROR: DATE MUST HAVE FORMAT LIKE DD/MM/YYYY (01/02/2020,..), PRESS ENTER TO TRY AGAIN";
            ch = getch();
            drawRectangle(20, 28, 90, 1, 15);
            drawRectangle(35, 25, 40, 1, 15);
            textBgColor(0, 15);
            DateEnd.clear();
            showPointer();
        }
        else break;
    } while (true);

    fstream file;
    file.open("file_save//RegistrationCourseSession.txt", ios::out);
    file << 1 << endl;
    file << "Date start: " << DateStart << endl;
    file << "Date end:" << DateEnd << endl;
    file.close();

    textBgColor(9, 15);
    printtext("CREATE COURSE REGISTRATION SESSION SUCCESSFUL !!! ,PRESS ENTER TO BACK TO MENU",20,28);
    ch = getch();
    textBgColor(0, 15);
}

void addCourse() {
    char ch;
    Course course;
    system("cls");
    textBgColor(13, 15);
    printtext("SCHOOL YEAR: ",40,15);
    printtext("COURSE ID: ", 40, 16);
    printtext("COURSE NAME: ", 40, 17);
    printtext("TEACHER NAME: ", 40, 18);
    printtext("NUMBER OF CREDITS: ", 40, 19);
    printtext("MAXIMUN OF STUDENT: ", 40, 20);
    printtext("DAY OF THE WEEK: ", 40, 21);
    printtext("SESSION: S1 (7:30), S2 (9:30), S3 (13:30), S4 (15:30) :", 40, 22);
}