#include"staffFunction.h"
#include"Header.h"
#include"ConsoleProcess.h"
#include"Course_function.h"
#include"read_data.h"

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

void CopyContentFileToFile(string src_path, string des_path)
{
    fstream fileSource, fileDestination;
    fileSource.open(src_path, ios::in);
    fileDestination.open(des_path, ios::out);
    if (!fileSource.is_open()) return;
    string data;
    getline(fileSource, data);
    fileDestination << data;
    while (!fileSource.eof()) {
        getline(fileSource, data);
        fileDestination << endl << data;
    }
    fileSource.close();
    fileDestination.close();
}

void addSchoolYear(SchoolYear &Y) {

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
        if (insertString(schoolyear.year, 10) == 0) return;;
        
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
    fstream file1;
    string data;
    file.open("file_save//year-semester.csv", ios::app);
    file <<endl<< schoolyear.year << ",0";
    file.close();

    file.open("file_save/SchoolYear/"+Y.year+"/class_info.csv",ios::in);
    getline(file, data);
    while (!file.eof()) {
        getline(file, data, ',');
        getline(file, data, ',');
        string source = "file_save/SchoolYear/" + Y.year + "/" + data + ".csv", destination = "file_save/SchoolYear/" + schoolyear.year+"/"+data+".csv";
        CopyContentFileToFile(source,destination);
        getline(file, data);
    }
    CopyContentFileToFile("file_save/SchoolYear/" + Y.year + "/staff.csv", "file_save/SchoolYear/" + schoolyear.year + "/staff.csv");
    CopyContentFileToFile("file_save/SchoolYear/" + Y.year + "/class_info.csv", "file_save/SchoolYear/" + schoolyear.year + "/class_info.csv");
    Y.year = schoolyear.year;
    Y.semester.Name="Semester0";aa

    hidePointer();
    textBgColor(10, 11);
    printtext("CREATE SCHOOL YEAR SUCCESSFUL,PRESS ENTER TO BACK TO MENU !!!", 40, 14);
    ch = getch();
    textBgColor(0, 15);
}

int insertNameSemester(string& name) {
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
        if (word == 27) {
            return 0;
        }
        else if (word >= 49 && word <= 51 && name.size()<1 ) {
            cout << word;
            name.push_back(word);
        }
    } while (word != 13);
    return 1;
}

int insertDate(string& Date) {
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
        if (word == 27) {
            return 0;
        }
    } while (word != 13 || Date.size()<10);
    return 1;
}

int insertSchoolYear(string& SchoolYear) {
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
        if (word == 27) {
            return 0;
        }
        else if (((word >= 48 && word <= 57) || word == 45) && SchoolYear.size() < 9) {
            cout << word;
            SchoolYear.push_back(word);
        }

    } while (word != 13 || SchoolYear.size() < 9);
    return 1;
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
    file_new.open("file_save//year_semester_new.csv", ios::app);
    file_new << "Năm,số kì đã học ";
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
                file_new << endl <<  to_string(a);
            }
            else file_new << endl << data2;
            getline(file_old1, data1);
            break;
        }
    }
    file_old1.close();
    file_old2.close();
    file_new.close();
    remove("file_save//year-semester.csv");
    rename("file_save//year_semester_new.csv", "file_save//year-semester.csv");
}

void UpDatefileInfo(Semester semester) {
    fstream file;
    file.open("file_save//SchoolYear//" + semester.schoolyear + "//Semester" + semester.Name + "//SemesterInfo.txt", ios::app);
    file << "Semester: " << semester.Name;
    file << endl << "Start Date: " << semester.date_star;
    file << endl << "End Date: " << semester.date_end;
    file.close();
}

void addSemester(string &yearNow,string &semesterNow) {
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
    printtext("Enter school year of the semester (Ex:2020-2021,...):", 35, 12);
    printtext("Enter start date (dd/mm/yyyy):", 35, 14);
    printtext("Enter end date (dd/mm/yyyy):", 35, 16);
    drawRectangle(35, 11, 35, 1, 15);
    drawRectangle(35, 13, 35, 1, 15);
    drawRectangle(35, 15, 35, 1, 15);
    drawRectangle(35, 17, 35, 1, 15);

        gotoxy(35, 11);
        if (insertNameSemester(semester.Name)==0) return;
        
        do {
            gotoxy(35, 13);
            if (insertSchoolYear(semester.schoolyear)==0) return;
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
                drawRectangle(35, 13, 10, 1, 15);
                textBgColor(0, 15);
                semester.schoolyear = "";
                showPointer();
            }
            else break;
        } while (true);

        do {
            gotoxy(35, 15);
            if (insertDate(semester.date_star)==0) return;
            int check = checkDate(semester.date_star);
            if (check == 0) {
                textBgColor(4, 11);
                gotoxy(35, 19);
                hidePointer();
                cout << "ERROR: DATE MUST HAVE FORMAT LIKE DD/MM/YYYY (01/02/2020), PRESS ENTER TO TRY AGAIN";
                ch = getch();
                drawRectangle(35, 19, 41, 1, 11);
                drawRectangle(35, 15, 10, 1, 15);
                textBgColor(0, 15);
                semester.date_star.clear();
                showPointer();
            }
            else break;
        } while (true);

        do {
            gotoxy(35, 17);
            if (insertDate(semester.date_end)==0) return;
            int check = checkDate(semester.date_end);
            if (check == 0) {
                textBgColor(4, 11);
                gotoxy(35, 19);
                hidePointer();
                cout << "ERROR: DATE MUST HAVE FORMAT LIKE DD/MM/YYYY (01/02/2020), PRESS ENTER TO TRY AGAIN";
                ch = getch();
                drawRectangle(35, 19, 41, 1, 11);
                drawRectangle(35, 17, 10, 1, 15);
                textBgColor(0, 15);
                semester.date_end.clear();
                showPointer();
            }
            else break;
        } while (true);

    semesterNow = semester.Name;
    createFolder("file_save//SchoolYear//" + semester.schoolyear + "//Semester" + semester.Name);
    createFolder("file_save//SchoolYear//" + semester.schoolyear + "//Semester" + semester.Name + "//Class");
    createFolder("file_save//SchoolYear//" + semester.schoolyear + "//Semester" + semester.Name + "//Course");
    createFolder("file_save//SchoolYear//" + semester.schoolyear + "//Semester" + semester.Name + "//Course//Scoreboard");
    UpDatefileCSV(semester);
    UpDatefileInfo(semester);
    fstream file;
    file.open("file_save//SchoolYear//" + semester.schoolyear + "//Semester" + semester.Name + "//course_info.csv", ios::out);
    file << "ID,COURSE NAME,TEACHER NAME,NUMBER OF CREDITS,MAX STUDENT,DAY,SESSION1,SESSION2";
    file.close();
    fstream fileCourse;
    fileCourse.open("file_save//SchoolYear//" + semester.schoolyear + "//Semester" + semester.Name + "//RegistrationCourseSession.txt", ios::out);
    fileCourse << 0;
    fileCourse.close();
    hidePointer();
    textBgColor(10,11);
    printtext("CREATE SEMESTER SUCCESSFUL,PRESS ENTER BACK TO MENU !!!", 35, 19);
    ch = getch();
    textBgColor(0, 15);
}

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

    string year, semester;
    determineYearSemesterNow(year, semester);
    if (stoi(semester.substr(8, 1), 0, 10) == 0) {
        textBgColor(4, 15);
        printtext("YOU HAVEN'T CREATED SEMESTER YET, PRESS ENTER TO BACK TO MENU.", 40, 10);
        ch = getch();
    }
    else {
        drawRectangle(30, 20, 50, 7, 11);
        textBgColor(0, 11);
        printtext("START DATE (DD/MM/YYYY):", 35, 21);
        printtext("END DATE (DD/MM/YYYY):", 35, 24);
        drawRectangle(35, 22, 40, 1, 15);
        drawRectangle(35, 25, 40, 1, 15);

        string filename = "file_save//SchoolYear//" + year + "//" + semester + "//RegistrationCourseSession.txt";
        do {
            gotoxy(35, 22);
            if (insertDate(DateStart)==0) return;
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
            if (insertDate(DateEnd)==0) return;
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
        hidePointer();
        fstream file;
        file.open(filename, ios::out);
        file << 1;
        file << endl << "Date start: " << DateStart;
        file << endl << "Date end:" << DateEnd;
        file.close();
        textBgColor(9, 15);
        printtext("CREATE COURSE REGISTRATION SESSION SUCCESSFUL !!! ,PRESS ENTER TO BACK TO MENU", 20, 28);
        ch = getch();
    }
    textBgColor(0, 15);
}

int insertNum(int &n) {
    char c;
    string num;
    do{ 
        c = getch(); 
        if (c == 8) {
            if (num.size() > 0) {
                num.pop_back();
                gotoxy(ReturnX() - 1, ReturnY());
                cout << " ";
                gotoxy(ReturnX() - 1, ReturnY());
            }
        }
        else if (c>=48 && c<=57) {
            cout << c;
            num.push_back(c);
        }
        if (c == 27) {
            return 0;
        }
    } while (c != 13);
    n = stoi(num, 0, 10);
    return 1;
}

int countLine(string filename){
    fstream file;
    string line;
    file.open(filename, ios::in);
    int count = 0;
    while (getline(file, line,'\n'))
        count++;
    file.close();
    return count;
}

void determineYearSemesterNow(string& Year, string& semester) {
    fstream file1;
    string data1;
    file1.open("file_save/year-semester.csv",ios::in);  
    getline(file1, data1);
    while (!file1.eof()) {
        getline(file1, data1);
    }
    Year = data1.substr(0, 9);
    semester = "Semester" + data1.substr(10, 1);
}

void addCourse() {
    char ch;
    Course course;
    string Day[7] = { "MON","TUE","WED","THU","FRI","SAT" }, session[4] = { "S1","S2","S3","S4" };
    system("cls");
    textBgColor(13, 15);
    printtext("  ____ ___  _   _ ____  ____  _____", 40, 2);
    printtext(" / ___/ _ \\| | | |  _ \\/ ___|| ____|", 40, 3);
    printtext("| |  | | | | | | | |_) \\___ \\| _|", 40, 4);
    printtext("| |__| |_| | |_| |  _ < ___) | |___", 40, 5);
    printtext(" \\____\\___/ \\___/|_| \\_\\____/|_____| ", 40, 6);

    string year="", semester="";
    determineYearSemesterNow(year,semester);
    if (stoi(semester.substr(8, 1), 0, 10) == 0) {
        textBgColor(4, 15);
        printtext("YOU HAVEN'T CREATED SEMESTER YET, PRESS ENTER TO BACK TO MENU.", 40, 10);
        ch = getch();
    }

    else {
        drawRectangle(25, 9, 70, 18, 11);
        printtext("COURSE ID: ", 30, 10);
        printtext("COURSE NAME: ", 30, 12);
        printtext("TEACHER NAME: ", 30, 14);
        printtext("NUMBER OF CREDITS: ", 30, 16);
        printtext("MAXIMUN OF STUDENT: ", 30, 18);
        printtext("DAY OF THE WEEK (MON / TUE / WED / THU / FRI / SAT): ", 30, 20);
        printtext("SESSION: S1 (7:30), S2 (9:30), S3 (13:30), S4 (15:30) :", 30, 22);

        drawRectangle(30, 11, 50, 1, 15);
        drawRectangle(30, 13, 50, 1, 15);
        drawRectangle(30, 15, 50, 1, 15);
        drawRectangle(30, 17, 50, 1, 15);
        drawRectangle(30, 19, 50, 1, 15);
        drawRectangle(30, 21, 50, 1, 15);
        drawRectangle(30, 23, 50, 1, 15);
        drawRectangle(30, 24, 50, 1, 15);


        ///////////////////////////////////////////
        do
        {
            gotoxy(30, 11);
            if (insertString(course.ID_course,15)==0) return;
            if (countLine("file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv") == 1) break;
            fstream file;
            string line;
            file.open("file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv", ios::in);
            getline(file, line);
            bool check = false;
            while (!file.eof()) {
                getline(file, line, ',');
                if (line.compare(course.ID_course) != 0) {
                    check = true; break;
                }
            }
            if (check == true) break;
            else {
                textBgColor(4, 15);
                hidePointer();
                printtext("ERROR: COURSE ALREADY EXISTS,PRESS ENTER TO TRY AGAIN.", 25, 27);
                ch = getch();
                textBgColor(0, 15);
                drawRectangle(25, 27, 80, 1, 15);
                drawRectangle(30, 11, 50, 1, 15);
            }
        } while (true);

        gotoxy(30, 13);
        if (insertString(course.name, 15) == 0) return;;
        gotoxy(30, 15);
        if (insertString(course.teacher,15)==0) return;
        gotoxy(30, 17);
        if (insertNum(course.Num_of_creadit) == 0) return;
        gotoxy(30, 19);
        if (insertNum(course.Max_student)==0) return;
        do {
            gotoxy(30, 21);
            showPointer();
            if (insertString(course.DayOfWeek,15) == 0) return;
            bool check = false;
            for (int i = 0; i < 7; i++) {
                if (course.DayOfWeek.compare(Day[i]) == 0) {
                    check = true;
                    break;
                }
            }
            if (check == true) break;
            else {
                textBgColor(4, 15);
                hidePointer();
                printtext("ERROR: YOUR DAY MUST HAVE FORMAT LIKE (MON,TUE,..),PRESS ENTER TO TRY AGAIN.", 25, 27);
                ch = getch();
                textBgColor(0, 15);
                drawRectangle(25, 27, 80, 1, 15);
                drawRectangle(30, 21, 50, 1, 15);
            }
        } while (true);

        do
        {
            gotoxy(30, 23);
            showPointer();
            if (insertString(session[0], 15) == 0) return;
            bool check = false;
            for (int i = 0; i < 4; i++) {
                if (course.session[0].compare(session[i]) == 0) {
                    check = true;
                    break;
                }
            }
            if (check == true) break;
            else {
                textBgColor(4, 15);
                hidePointer();
                printtext("ERROR: YOUR SESSION MUST HAVE FORMAT LIKE (S1,S2,..),PRESS ENTER TO TRY AGAIN.", 25, 27);
                textBgColor(0, 15);
                ch = getch();
                drawRectangle(25, 27, 80, 1, 15);
                drawRectangle(30, 23, 50, 1, 15);
            }
        } while (true);

        do
        {
            gotoxy(30, 24);
            showPointer();
            if (insertString(course.session[1],15)==0) return;
            int check = 0;
            for (int i = 0; i < 4; i++) {
                if (course.session[1].compare(session[i]) == 0) {
                    if (course.session[1].compare(course.session[0]) == 0)
                        check = -1;
                    else check = 1;
                    break;
                }
            }
            if (check == 1) break;
            else {
                textBgColor(4, 15);
                hidePointer();
                if (check == 0)
                    printtext("ERROR: YOUR SESSION MUST HAVE FORMAT LIKE (S1,S2,..),PRESS ENTER TO TRY AGAIN.", 25, 27);
                else
                    printtext("ERROR: YOUR SESSION IS THE SAME AS LAST SESSION ,PRESS ENTER TO TRY AGAIN.", 25, 27);
                textBgColor(0, 15);
                ch = getch();
                drawRectangle(25, 27, 80, 1, 15);
                drawRectangle(30, 24, 50, 1, 15);
            }
        } while (true);
        fstream file;
        file.open("file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv", ios::app);
        file << endl << course.ID_course << "," << course.name << "," << course.teacher << "," << course.Num_of_creadit << "," << course.Max_student << "," << course.DayOfWeek << "," << course.session[0] << "," << course.session[1];
        file.close();

        file.open("file_save/SchoolYear/" + year + "/" + semester + "/Course/" + course.ID_course + ".csv", ios::out);
        file << "ID STUDENT,NAME,BIRTHDAY,SEX,ID SOCIAL";
        file.close();
        printtext("CREATE COURSE SUCCESSFUL !!!, PRESS ENTER TO BACK TO MENU.", 25, 27);
        ch = getch();
    }
    textBgColor(0, 15);
}

void getLineInfo(string filename, int line, string column[],int columnNum) {
    if (line > countLine(filename)) cout << "Not exist line";
    int numLine = countLine(filename);
    fstream file;
    string data;
    file.open(filename, ios::in);
    for (int i=1;i<=numLine;i++) {
        if (i == line) {
            for (int j = 0; j < columnNum; j++) {
                if (j != columnNum - 1) {
                    getline(file, data, ',');
                    column[j] = data;
                }
                else {
                    getline(file, data);
                    column[j] = data;
                }
            }
            break;
        }
        else {
            getline(file, data);
        }
    }
}

/*
ID[5]: 1
Name[21]: 9
Teachar[15]: 34
Credits[3] 60   
student[5] 76 
Day[5] 88
Session[5] 98 108
*/

int insertString(string &data,int limit) {
    char ch;
    do
    {
        ch = getch();
        if (ch == 8) {
            if (data.size() > 0) {
                data.pop_back();
                gotoxy(ReturnX() - 1, ReturnY());
                cout << " ";
                gotoxy(ReturnX() - 1, ReturnY());
            }
        }
        else if (ch == 32) {
            data.push_back(ch);
            cout << " ";
        }
        else if (((ch >= 33 && ch <= 57) || (ch>=65 && ch<=90)|| (ch >=97  && ch <= 122) || ch == 95) && data.size()<limit) {
            cout << ch;
            data.push_back(ch);
        }
        if (ch == 27) {
            return 0;
        }
    } while (ch != 13);
    return 1;
}

int insertNum2(string& data, int limit) {
    char ch;
    do
    {
        ch = getch();
        if (ch == 8) {
            if (data.size() > 0) {
                data.pop_back();
                gotoxy(ReturnX() - 1, ReturnY());
                cout << " ";
                gotoxy(ReturnX() - 1, ReturnY());
            }
        }
        if (ch == 27) {
            return 0;
        }
        else if ((ch >= 48 && ch <= 57) && data.size() < limit) {
            cout << ch;
            data.push_back(ch);
        }
    } while (ch != 13);
    return 1;
}

int insertDay(string& data, int limit) {
    string Day[7] = { "MON","TUE","WED","THU","FRI","SAT" };
    char ch;
    bool check = false;
    do
    {
        ch = getch();
        if (ch == 8) {
            if (data.size() > 0) {
                data.pop_back();
                gotoxy(ReturnX() - 1, ReturnY());
                cout << " ";
                gotoxy(ReturnX() - 1, ReturnY());
            }
        }
        else if ((ch >= 65 && ch <= 90) && data.size() < limit) {
            cout << ch;
            data.push_back(ch);
        }
        if (ch == 27) {
            return 0;
        }
        for (int i = 0; i < 7; i++) {
            if (data.compare(Day[i]) == 0) { check = true; break; }
        }
    } while (ch!=13 || check==false);
    return 1;
}

int insertSession(string& data, int limit) {
    string session[4] = { "S1","S2","S3","S4" };
    char ch;
    bool check = false;
    do
    {
        ch = getch();
        if (ch == 8) {
            if (data.size() > 0) {
                data.pop_back();
                gotoxy(ReturnX() - 1, ReturnY());
                cout << " ";
                gotoxy(ReturnX() - 1, ReturnY());
            }
        }
        else if (((ch >= 65 && ch <= 90)||(ch>=48 &&ch<=57)) && data.size() < limit) {
            cout << ch;
            data.push_back(ch);
        }
        if (ch == 27) {
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            if (data.compare(session[i]) == 0) { check = true; break; }
        }
    } while (ch != 13 || check == false);
    return 1;
}

void updateFileCourse(int currentColumn,int currentLine,string column[],string year,string semester) {
    fstream file_be,file_af;
    string newdata,line;
    string filename = "file_save//SchoolYear//" + year + "//" + semester + "//course_info.csv";
    for (int i = 0; i < 8; i++) {
        if (i != 7) {
            newdata = newdata +column[i] + ",";
        }
        else newdata = newdata + column[i];
    }
    file_be.open(filename, ios::in);
    file_af.open("file_save//SchoolYear//" + year + "//" + semester  + "//course_info_new.csv", ios::app);
    getline(file_be, line);
    file_af << line;
    int i = 2;
    while (!file_be.eof()) {
        if (i == currentLine) {
            file_af <<endl<< newdata ;
            getline(file_be, line);
        }
        else {
            getline(file_be, line);
            file_af <<endl<< line;
        }
        i++;
    }

    char* a = new char[filename.size() + 1];
    strcpy(a, filename.c_str());
    a[filename.size()] = '\0';
    string filename_new = "file_save/SchoolYear/" + year + "/" + semester + "/course_info_new.csv";
    char* b = new char[filename_new.size() + 1];
    strcpy(b, filename_new.c_str());
    b[filename_new.size()] = '\0';
    file_be.close();
    file_af.close();
    remove(a);
    rename(b, a);
   
}

void editInforCourse(int y,int currentLine,string column[],string year,string semester) {
    char ch;
    int currentColumn = 0, pos[8] = { 1,9,34,60,76,88,98,108 }, limit[8] = {5,21,15,3,5,5,5,5};
    drawRectangle(1,y,5,1,15);
    textBgColor(0, 15);
    printtext(column[0], 1, y);
    do
    {
        ch = getch();
        //ESC
        if (ch == 27) 
            break;
        //Left 
        if (ch == 75 && currentColumn > 0) {
            drawRectangle(pos[currentColumn], y,limit[currentColumn],1,14);
            textBgColor(0,14);
            printtext(column[currentColumn], pos[currentColumn], y);
            
            currentColumn--;
            drawRectangle(pos[currentColumn], y, limit[currentColumn], 1, 15);
            textBgColor(0, 15);
            printtext(column[currentColumn], pos[currentColumn], y);
        }
        //Right
        if (ch == 77 && currentColumn<7){
            drawRectangle(pos[currentColumn], y, limit[currentColumn], 1, 14);
            textBgColor(0, 14);
            printtext(column[currentColumn], pos[currentColumn], y);

            currentColumn++;
            drawRectangle(pos[currentColumn], y, limit[currentColumn], 1, 15);
            textBgColor(0, 15);
            printtext(column[currentColumn], pos[currentColumn], y);
        }

        //[ENTER]
        if (ch == 13) {
            drawRectangle(pos[currentColumn], y, limit[currentColumn], 1, 15);
            gotoxy(pos[currentColumn], y);
            showPointer();
            textBgColor(0, 15);
            if (currentColumn == 0) {
                string ID;
                insertString(ID, 5);
                column[0] = ID;
            }
            else if (currentColumn == 1) {
                string NameC;
                insertString(NameC, 21);
                column[1] = NameC;
            }
            else if (currentColumn == 2) {
                string NameT;
                insertString(NameT, 15);
                column[2] = NameT;
            }
            else if (currentColumn == 3) {
                string credit;
                insertNum2(credit, 3);
                column[3] = credit;
            }
            else if (currentColumn == 4) {
                string student;
                insertNum2(student, 5);
                column[4] = student;
            }
            else if (currentColumn == 5) {
                string day;
                insertDay(day, 3);
                column[5] = day;
            }
            else {
                string session;
                insertSession(session, 2);
                column[currentColumn] = session;
            }
            hidePointer();
            updateFileCourse(currentColumn,currentLine, column,year,semester); 
        }
    } while (true);
}


void deleteCourse(string filename, int currentLine,string year,string semester) {
    fstream file_be, file_af;
    string newdata, line;
    file_be.open(filename, ios::in);
    file_af.open("file_save//SchoolYear//" + year + "//" + semester + "//course_info_new.csv", ios::app);
    getline(file_be, line);
    file_af << line;
    int i = 2;
    while (!file_be.eof()) {
        if (i == currentLine) {
            getline(file_be, line);
        }
        else {
            getline(file_be, line);
            file_af<<endl << line;
        }
        i++;
    }
    char* a = new char[filename.size() + 1];
    strcpy(a, filename.c_str());
    a[filename.size()] = '\0';
    string filename_new = "file_save/SchoolYear/" + year + "/" + semester + "/course_info_new.csv";
    char* b = new char[filename_new.size() + 1];
    strcpy(b, filename_new.c_str());
    b[filename_new.size()] = '\0';
    file_be.close();
    file_af.close();
    remove(a);
    rename(b, a);
}

void moveUp(string filename,int &currentLine,int columnNum,int indexB[],int y, string column[],int lineInConsole,int width,int x){
    getLineInfo(filename, currentLine + 1, column, columnNum);
    drawRectangle(x, y + lineInConsole + 1, width, 1, 11);
    textBgColor(0, 11);
    for (int i = 0; i < columnNum; i++) {
        printtext(column[i], indexB[i], y + lineInConsole + 1);
    }

    getLineInfo(filename, currentLine , column, columnNum);
    drawRectangle(x, y + lineInConsole, width, 1, 14);
    textBgColor(0, 14);
    for (int i = 0; i < columnNum; i++) {
        printtext(column[i], indexB[i], y + lineInConsole);
    }    
}

void moveDown(string filename, int &currentLine, int columnNum, int indexB[],int y,string column[],int lineInConsole,int width,int x) {
    
    getLineInfo(filename, currentLine -1  , column, columnNum);
    drawRectangle(x, y - 1 + lineInConsole, width, 1, 11);
    textBgColor(0, 11);
    for (int i = 0; i < columnNum; i++) {
        printtext(column[i], indexB[i], y + lineInConsole - 1);
    }
    getLineInfo(filename, currentLine , column, columnNum);
    drawRectangle(x, y + lineInConsole, width, 1, 14);
    textBgColor(0, 14);
    for (int i = 0; i < columnNum; i++) {
        printtext(column[i], indexB[i], y + lineInConsole);
    }
}


void editCourse(string year,string semester) {
    char ch;
    int line = countLine("file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv") ;
    int currentLine = 2;
    int y = 11;
    string column[8];
    int lineInConsole = 1;
    int a[8] = { 2,13,35,52,73,88,95,105 };
    int b[8] = { 1,9,34,60,76,88,98,108 };
    getLineInfo("file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv",currentLine, column,8);
    drawRectangle(1, y + lineInConsole, 110, 1, 14);
    textBgColor(0, 14);
    for (int i = 0; i < 8; i++) 
        printtext(column[i], b[i], y + lineInConsole);
    do {
        hidePointer();
        ch = getch();
        //[ESC]
        if (ch == 27) {
            drawRectangle(1, y + lineInConsole, 110, 1, 11);
            textBgColor(0, 11);
            for (int i = 0; i < 8; i++)
                printtext(column[i], b[i], y + lineInConsole);
            break;
        }
        else {
            if (ch == 72 && currentLine > 2 ) //up
            {   
                currentLine--;
                lineInConsole--;
                if (lineInConsole + y <= 11) {
                    lineInConsole = 12;
                    drawRectangle(0, 10, 120, 15, 15);
                    drawRectangle(0, 10, 120, 15, 11);
                    drawList(8, "file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv", y, a, b, line, currentLine-11);
                    getLineInfo("file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv", currentLine, column, 8);
                    drawRectangle(1, y + lineInConsole, 110, 1, 14);
                    textBgColor(0, 14);
                    for (int i = 0; i < 8; i++) {
                        printtext(column[i], b[i], y + lineInConsole);
                    }
                }
                else 
                    moveUp("file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv", currentLine, 8, b, y, column,lineInConsole,110,1);
                
            }
            if (ch == 80 && currentLine < line) //down
            {   
                currentLine++;
                lineInConsole++;
                if (lineInConsole + y > 23) {
                    lineInConsole=1;
                    drawRectangle(0, 10, 120, 15, 15);
                    drawRectangle(0, 10, 120, 15, 11);
                    drawList(8, "file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv", y, a, b, line, currentLine);
                    getLineInfo("file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv", currentLine, column, 8);
                    drawRectangle(1, y + lineInConsole, 110, 1, 14);
                    textBgColor(0, 14);
                    for (int i = 0; i < 8; i++) {
                        printtext(column[i], b[i], y + lineInConsole);
                    }
                }
                else
                    moveDown("file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv", currentLine, 8, b, y, column, lineInConsole,110,1);
            }
            if (ch == 13) {
            //printtext();
            editInforCourse(y + lineInConsole, currentLine, column,year,semester);
            drawRectangle(1, y + lineInConsole, 110, 1, 14);
            textBgColor(0, 14);
            for (int i = 0; i < 8; i++)
                printtext(column[i], b[i], y + lineInConsole);
            }

            if (ch == 'x') {
                deleteCourse("file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv", currentLine, year, semester);
                string filename = "file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv";
                drawList(8, filename , y, a, b, line,currentLine-lineInConsole+1);
                if (currentLine == line) {
                    currentLine = line - 1;
                    lineInConsole--;
                }
                line--;
                drawRectangle(1, y + lineInConsole, 110, 1, 14);
                textBgColor(0, 14);
                getLineInfo(filename, currentLine , column,8);
                for (int i = 0; i < 8; i++)
                    printtext(column[i], b[i], y + lineInConsole);
            }
        }
    } while (true);
}

void drawList(int columnNum, string filename, int y, int indexA[], int indexB[], int line,int flagLine) {
    if (line == 0 || columnNum == 0) return;
    string *datanew = new string[line];
    string *column = new string[columnNum];
    textBgColor(4, 11);
  
    getLineInfo(filename, 1, column,columnNum);
    for (int i = 0; i < columnNum; i++) {
        printtext(column[i], indexA[i], y);
    }
    textBgColor(0, 11);
    y ++;
    int j = flagLine, h = 1;
    while (j<=line && h<=12) {
        getLineInfo(filename,j, column, columnNum);
        for (int i = 0; i < columnNum; i++) {
            printtext(column[i], indexB[i], y);
        }
        y++; j++;
        h++;
    }
}

void listCourse(string year, string semester) {
    char ch;
    hidePointer();
    system("cls");
    textBgColor(13, 15);
    printtext(" _     ___ ____ _____    ____ ___  _   _ ____  ____  _____", 30, 2);
    printtext("| |   |_ _/ ___|_   _|  / ___/ _ \\| | | |  _ \\/ ___|| ____|", 30, 3);
    printtext("| |    | |\\___ \\ | |   | |  | | | | | | | |_) \\___ \\|  _|", 30, 4);
    printtext("| |___ | | ___) || |   | |__| |_| | |_| |  _ < ___) | |___", 30, 5);
    printtext("|_____|___|____/ |_|    \\____\\___/ \\___/|_| \\_\\____/|_____|", 30, 6);
        
    drawRectangle(97, 0, 22, 5, 11);
    textBgColor(4, 11);
    printtext("-[ESC]: BACK TO MENU", 97, 2);
    printtext("OR RETURN", 97, 3);

    drawRectangle(0, 0, 26, 5, 11);
    textBgColor(4, 11);
    printtext("-[x]: DELETE COURSE", 0, 0.5);
    printtext("-[ENTER]: EDIT COURSE", 0, 1.5);
    printtext("-USE UP,DOWN,LEFT,RIGHT", 0, 2.5);
    printtext("KEY TO MOVE IN EDIT STATUS", 0, 3.5);
    printtext("-[c]: CHANGE TIME", 0, 4.5);

    if (stoi(semester.substr(8, 1), 0, 10) == 0) {
        textBgColor(4, 15);
        printtext("YOU HAVEN'T CREATED SEMESTER YET, PRESS ENTER TO BACK TO MENU.", 30, 14);
        ch = getch();
        textBgColor(0, 15);
    }
    else{
        string filename = "file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv";
        int lineNum = countLine(filename);
        drawRectangle(0, 10, 120, 15, 11);
        int a[8] = { 2,13,35,52,73,88,95,105 };
        int b[8] = { 1,9,34,60,76,88,98,108 };
        drawList(8, filename, 11, a, b,lineNum,2);
        hidePointer();
        do
        {
            ch = getch();
            if (ch == 'e') {
                editCourse(year, semester);
            }
            if (ch == 'c') {
                SchoolYear s;
                change_Year_Semester(s);
                listCourse(s.year, s.semester.Name);
            }
            if (ch == 27) {
                break;
            }
        } while (true);
        textBgColor(0, 15);
    }
}

void viewCourse() {
    char ch;
    system("cls");
    textBgColor(13, 15);
    printtext(" _     ___ ____ _____    ____ ___  _   _ ____  ____  _____", 30, 2);
    printtext("| |   |_ _/ ___|_   _|  / ___/ _ \\| | | |  _ \\/ ___|| ____|", 30, 3);
    printtext("| |    | |\\___ \\ | |   | |  | | | | | | | |_) \\___ \\|  _|", 30, 4);
    printtext("| |___ | | ___) || |   | |__| |_| | |_| |  _ < ___) | |___", 30, 5);
    printtext("|_____|___|____/ |_|    \\____\\___/ \\___/|_| \\_\\____/|_____|", 30, 6);
    string year, semester;
    determineYearSemesterNow(year, semester);
    drawRectangle(0, 10, 120, countLine("file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv") + 2, 11);
    if (stoi(semester.substr(8, 1), 0, 10) == 0) {
        textBgColor(4, 15);
        printtext("YOU HAVEN'T CREATED SEMESTER YET, PRESS ENTER TO BACK TO MENU.", 30, 14);
        ch = getch();
    }
    else {
        textBgColor(4, 11);
        fstream file;
        file.open("file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv", ios::in);
        string data;
        getline(file, data, ',');
        printtext(data, 2, 11);
        getline(file, data, ',');
        printtext(data, 13, 11);
        getline(file, data, ',');
        printtext(data, 35, 11);
        getline(file, data, ',');
        printtext(data, 52, 11);
        getline(file, data, ',');
        printtext(data, 73, 11);
        getline(file, data, ',');
        printtext(data, 88, 11);
        getline(file, data, ',');
        printtext(data, 95, 11);
        getline(file, data);
        printtext(data, 105, 11);
        textBgColor(0, 11);
        int y = 12;
        while (!file.eof()) {
            getline(file, data, ',');
            printtext(data, 1, y);
            getline(file, data, ',');
            printtext(data, 9, y);
            getline(file, data, ',');
            printtext(data, 34, y);
            getline(file, data, ',');
            printtext(data, 60, y);
            getline(file, data, ',');
            printtext(data, 76, y);
            getline(file, data, ',');
            printtext(data, 88, y);
            getline(file, data, ',');
            printtext(data, 98, y);
            getline(file, data);
            printtext(data, 108, y);
            y++;
        }
        file.close();

        ch = getch();
    }
    textBgColor(0, 15);
}

bool checkTimeEnd(string date,string month, string year) {
    int Month = stoi(month, 0, 10);
    int Year = stoi(year, 0, 10);
    int Date = stoi(date, 0, 10);
    time_t now = time(0);
    tm* ltm = localtime(&now);
    //Năm hiện tại nhỏ hơn
    if (ltm->tm_year + 1900 < Year)
        return true;
    else{
        //Năm hiện tại lớn hơn
        if (ltm->tm_year + 1900 > Year)
            return false;
        //Năm hiện tại bằng
        else {
            //Tháng hiện tại nhỏ hơn
            if (ltm->tm_mon + 1 < Month)
                return true;
            else{
                //Tháng hiện tại lớn hơn
                if (ltm->tm_mon + 1 > Month)
                    return false;
                //Tháng hiện tại bằng
                else{
                    if (ltm->tm_mday <= Date)
                        return true;
                    else
                        return false;
                }
            }
        }
    }
}

bool checkTimeStart(string date, string month, string year) {
    int Month = stoi(month, 0, 10);
    int Year = stoi(year, 0, 10);
    int Date = stoi(date, 0, 10);
    time_t now = time(0);
    tm* ltm = localtime(&now);
    //Năm hiện tại lớn hơn
    if (ltm->tm_year + 1900 > Year)
        return true;
    else {
        //Năm hiện tại nhỏ hơn
        if (ltm->tm_year + 1900 < Year)
            return false;
        //Năm hiện tại bằng
        else {
            //Tháng hiện tại lớn hơn
            if (ltm->tm_mon + 1 > Month)
                return true;
            else {
                //Tháng hiện tại nhỏ hơn
                if (ltm->tm_mon + 1 < Month)
                    return false;
                //Tháng hiện tại bằng
                else {
                    if (ltm->tm_mday >= Date)
                        return true;
                    else
                        return false;
                }
            }
        }
    }
}

int checkCourseSession() {
    string year, semester;
    determineYearSemesterNow(year, semester);
    if (stoi(semester.substr(8, 1), 0, 10) == 0) {
        textBgColor(4, 15);
        printtext("HAVEN'T CREATE SEMESTER YET, PRESS ENTER TO BACK TO MENU.", 40, 10);
        char ch = getch();
    }
    else {
        fstream file;
        file.open("file_save/SchoolYear/" + year + "/" + semester + "/RegistrationCourseSession.txt", ios::in);
        string data;
        getline(file, data);
        if (stoi(data, 0, 10) == 0) return 0;//not open session yet
        else {
            getline(file, data);
            string dateStart = data.substr(13, 10);
            getline(file, data);
            string dateEnd = data.substr(10, 10);
            if (checkTimeStart(dateStart.substr(0, 2), dateStart.substr(3, 2), dateStart.substr(6, 2)) == false) return -1;//It's not time to start yet
            else {
                if (checkTimeEnd(dateEnd.substr(0, 2), dateEnd.substr(3, 2), dateEnd.substr(6, 2)) == false) return -2;//It was late to register the course
                else return 1;//can register the course 
            }
        }
    }
    textBgColor(0, 15);
}

void exportScoreboardInterface(string year, string semester,int flagLine,int currentLine,int lineInConsole) {
    char ch;
    system("cls");
    textBgColor(13, 15);
    printtext(" _______  ______   ___  ____ _____ ", 30, 0);
    printtext("| ____\\ \\/ /  _ \\ / _ \\|  _ \\_   _|", 30, 1);
    printtext("|  _|  \\  /| |_) | | | | |_) || |", 30, 2);
    printtext("| |___ /  \\|  __/| |_| |  _ < | |", 30, 3);
    printtext("|_____/_/\\_\\_|    \\___/|_| \\_\\|_|", 30, 4);
    printtext(" ____   ____ ___  ____  _____ ____   ___    _    ____  ____ ", 30, 5);
    printtext("/ ___| / ___/ _ \\|  _ \\| ____| __ ) / _ \\  / \\  |  _ \\|  _ \\ ", 30, 6);
    printtext("\\___ \\| |  | | | | |_) |  _| |  _ \\| | | |/ _ \\ | |_) | | | |", 30, 7);
    printtext(" ___) | |__| |_| |  _ <| |___| |_) | |_| / ___ \\|  _ <| |_| |", 30, 8);
    printtext("|____/ \\____\\___/|_| \\_\\_____|____/ \\___/_/   \\_\\_| \\_\\____/", 30, 9);

    drawRectangle(97, 0, 22, 5, 11);
    textBgColor(4, 11);
    printtext("-[c]: CHANGE SCHOOL YEAR", 97, 0);
    printtext(" YEAR", 97, 1);
    printtext("-[ESC]: BACK TO MENU", 97, 3);

    if (stoi(semester.substr(8, 1), 0, 10) == 0) {
        textBgColor(4, 15);
        printtext("HAVEN'T CREATE SEMESTER YET, PRESS ENTER TO BACK TO MENU.", 40, 10);
        char ch = getch();
        
    }
    else {
        int y = 11;
        string column[8];
        string filename = "file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv";
        int lineNum = countLine(filename);
        drawRectangle(0, 10, 120, 15, 11);
        int a[8] = { 2,13,35,52,73,88,95,105 };
        int b[8] = { 1,9,34,60,76,88,98,108 };
        if (lineNum == 1) {
            string column[8];
            getLineInfo(filename, 1, column, 8);
            for (int i = 0; i < 8; i++) {
                printtext(column[i], a[i], 11);
            }
            ch = getch();
        }
        else {
            drawList(8, filename, 11, a, b, lineNum, flagLine);
            hidePointer();

            //int currentLine = 2;

            //int lineInConsole = 1;
            getLineInfo("file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv", currentLine, column, 8);
            drawRectangle(1, y + lineInConsole, 110, 1, 14);
            textBgColor(0, 14);
            for (int i = 0; i < 8; i++)
                printtext(column[i], b[i], y + lineInConsole);

            do {
                hidePointer();
                ch = getch();
                //[ESC]
                if (ch == 27) {
                    drawRectangle(1, y + lineInConsole, 110, 1, 11);
                    textBgColor(0, 11);
                    for (int i = 0; i < 8; i++)
                        printtext(column[i], b[i], y + lineInConsole);
                    break;
                }
                if (ch == 72 && currentLine > 2) //up
                {
                    currentLine--;
                    lineInConsole--;
                    if (lineInConsole + y <= 11) {
                        lineInConsole = 12;
                        drawRectangle(0, 10, 120, 15, 15);
                        drawRectangle(0, 10, 120, 15, 11);
                        drawList(8, "file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv", y, a, b, lineNum, currentLine - 11);
                        getLineInfo("file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv", currentLine, column, 8);
                        drawRectangle(1, y + lineInConsole, 110, 1, 14);
                        textBgColor(0, 14);
                        for (int i = 0; i < 8; i++) {
                            printtext(column[i], b[i], y + lineInConsole);
                        }
                    }
                    else
                        moveUp("file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv", currentLine, 8, b, y, column, lineInConsole, 110, 1);

                }
                if (ch == 80 && currentLine < lineNum) //down
                {
                    currentLine++;
                    lineInConsole++;
                    if (lineInConsole + y > 23) {
                        lineInConsole = 1;
                        drawRectangle(0, 10, 120, 15, 15);
                        drawRectangle(0, 10, 120, 15, 11);
                        drawList(8, "file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv", y, a, b, lineNum, currentLine);
                        getLineInfo("file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv", currentLine, column, 8);
                        drawRectangle(1, y + lineInConsole, 110, 1, 14);
                        textBgColor(0, 14);
                        for (int i = 0; i < 8; i++) {
                            printtext(column[i], b[i], y + lineInConsole);
                        }
                    }
                    else
                        moveDown("file_save/SchoolYear/" + year + "/" + semester + "/course_info.csv", currentLine, 8, b, y, column, lineInConsole, 110, 1);
                }

                if (ch == 13) {
                    exportSB(year, semester, column[0]);
                    drawRectangle(40, 15, 25, 5, 4);
                    textBgColor(15, 4);
                    printtext("EXPORT SUCCESSFULLY !!!", 41, 17);
                    ch = getch();
                    textBgColor(0, 15);
                    exportScoreboardInterface(year, semester, flagLine, currentLine, lineInConsole);
                }

                if (ch == 'c') {
                    SchoolYear s;
                    change_Year_Semester(s);
                    exportScoreboardInterface(s.year, s.semester.Name, flagLine, currentLine, lineInConsole);
                }
                textBgColor(0, 15);
            } while (true);
        }
    }
    textBgColor(0, 15);
}

void exportSB(string SchoolYear, string Semester, string CourseID) {
    fstream fileScore, fileList;
    fileScore.open("Score/Export/" + SchoolYear + "_" + Semester + "_" + CourseID + ".csv", ios::app);
    fileScore << "NO,STUDENT ID,NAME,TOTAL MARK,FINAL MARK,MIDTERM MARK,OTHER MARK";
    fileList.open("file_save/SchoolYear/" + SchoolYear + "/" + Semester + "/Course/" + CourseID + ".csv", ios::in);
    string data;
    getline(fileList, data);
    int i = 1;
    while (!fileList.eof()) {
        fileScore << endl << i;
        getline(fileList, data, ',');
        fileScore << "," << data;
        getline(fileList, data, ',');
        fileScore << "," << data;
        getline(fileList, data);
        i++;
    }
}

void importScoreBoard(string year, string semester, string courseID) {
    fstream file, fileScore;
    file.open("Score//Import//" + year + "_" + semester + "_" + courseID + ".csv", ios::in);
    fileScore.open("file_save//SchoolYear//" + year + "//" + semester + "//Course//Scoreboard//" + courseID + ".csv", ios::app);
    string data;
    getline(file, data);
    fileScore << data;
    while (!file.eof()) {
        getline(file, data);
        fileScore << endl << data;
    }
}


void importScoreBoardUI() {
    
    char ch;
    system("cls");
    textBgColor(13, 15);
    printtext(" ___ __  __ ____   ___  ____ _____ ", 30, 1);
    printtext("|_ _|  \\/  |  _ \\ / _ \\|  _ \\_   _|", 30, 2);
    printtext(" | || |\\/| | |_) | | | | |_) || | ", 30, 3);
    printtext(" | || |  | |  __/| |_| |  _ < | | ", 30, 4);
    printtext("|___|_|  |_|_|    \\___/|_| \\_\\|_|  ", 30, 5);
    printtext(" ____   ____ ___  ____  _____ ____   ___    _    ____  ____ ", 30, 6);
    printtext("/ ___| / ___/ _ \\|  _ \\| ____| __ ) / _ \\  / \\  |  _ \\|  _ \\ ", 30, 7);
    printtext("\\___ \\| |  | | | | |_) |  _| |  _ \\| | | |/ _ \\ | |_) | | | |", 30, 8);
    printtext(" ___) | |__| |_| |  _ <| |___| |_) | |_| / ___ \\|  _ <| |_| |", 30, 9);
    printtext("|____/ \\____\\___/|_| \\_\\_____|____/ \\___/_/   \\_\\_| \\_\\____/", 30, 10);

    string year, semester;
    determineYearSemesterNow(year, semester);
    if (stoi(semester.substr(8, 1), 0, 10) == 0) {
        textBgColor(4, 15);
        printtext("HAVEN'T CREATE SEMESTER YET, PRESS ENTER TO BACK TO MENU.", 40, 10);
        char ch = getch();
    }
    else {
        drawRectangle(25, 13, 90, 4, 11);
        textBgColor(0, 11);
        printtext("ENTER FILE NAME (Filename must have format like: 2020-2021_Semester2_MH370,.....) :", 26, 13);
        string filename;
        drawRectangle(26, 14.5, 50, 1, 15);
        textBgColor(0,15);
        gotoxy(26, 14.5);
        char ch;
        do
        {
            ch = getch();
            if (ch == 8) {
                if (filename.size() > 0) {
                    filename.pop_back();
                    gotoxy(ReturnX() - 1, ReturnY());
                    cout << " ";
                    gotoxy(ReturnX() - 1, ReturnY());
                }
            }
             if (((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) && filename.size() < 21) {
                cout << ch;
                filename.push_back(ch);
            }
             if (ch == 27) {
                 return;
             }
        } while (ch != 13);
        fstream file;
        file.open("Score/Import/"+filename + ".csv");

        if (!file.is_open()) {
            drawRectangle(40, 15, 25, 5, 4);
            textBgColor(15, 4);
            printtext("FILE DOESN'T EXIST !!!", 41, 17);
            ch = getch();
            textBgColor(0, 15);
            importScoreBoardUI();
        }
        hidePointer();
        importScoreBoard(filename.substr(0, 9), filename.substr(10, 9), filename.substr(20, filename.size() - 1));
        drawRectangle(40, 15, 25, 5, 4);
        textBgColor(15, 4);
        printtext("IMPORT SUCCESSFUL !!!", 41, 17);
        ch = getch();
    }
    textBgColor(0, 15);
}

void listClass(SchoolYear Y) {
    string year = Y.year, semester = Y.semester.Name;
    char ch;
    hidePointer();
    system("cls");
    textBgColor(13, 15);
    printtext(" _     ___ ____ _____    ____ _        _    ____ ____ ", 30, 2);
    printtext("| |   |_ _/ ___|_   _|  / ___| |      / \\  / ___/ ___|", 30, 3);
    printtext("| |    | |\\___ \\ | |   | |   | |     / _ \\ \\___ \\___ \\ ", 30, 4);
    printtext("| |___ | | ___) || |   | |___| |___ / ___ \\ ___) |__) |", 30, 5);
    printtext("|_____|___|____/ |_|    \\____|_____/_/   \\_\\____/____/ ", 30, 6);

    drawRectangle(97, 0, 22, 6, 11);
    textBgColor(4, 11);
    printtext("-[c]: CHANGE SCHOOL YEAR", 97, 0);
    printtext(" YEAR", 97, 1);
    printtext("-[ESC]: BACK TO MENU", 97, 3);
    printtext("-[ENTER]: CHOSE", 97, 5);

    string filename = "file_save/SchoolYear/" + year + "/class_info.csv";
    int lineNum = countLine(filename);
    int y = 11;
    drawRectangle(8, 10, 95, 15, 11);
    int a[5] = { 11,17,43,65,90};
    int b[5] = { 11.5,18.5,33,72,90};
    drawList(5, filename, y, a, b, lineNum, 2);
    hidePointer();

    int currentLine = 2, lineInConsole = 1;
    string column[5];
    getLineInfo(filename, currentLine, column, 5);
    drawRectangle(8, y + lineInConsole, 95, 1, 14);
    textBgColor(0, 14);
    for (int i = 0; i < 5; i++)
        printtext(column[i], b[i], y + lineInConsole);

    do {
        hidePointer();
        ch = getch();
        //[ESC]
        if (ch == 27) {
            break;
        }
        if (ch == 72 && currentLine > 2) //up
        {
            currentLine--;
            lineInConsole--;
            if (lineInConsole + y <= 11) {
                lineInConsole = 12;
                drawRectangle(8, 10, 95, 15, 15);
                drawRectangle(8, 10, 95, 15, 11);
                drawList(5, filename, y, a, b, lineNum, currentLine - 11);
                getLineInfo(filename, currentLine, column, 5);
                drawRectangle(8, y + lineInConsole, 95, 1, 14);
                textBgColor(0, 14);
                for (int i = 0; i < 5; i++) {
                    printtext(column[i], b[i], y + lineInConsole);
                }
            }
            else
                moveUp(filename, currentLine, 5, b, y, column, lineInConsole,95,8);
        }
        if (ch == 80 && currentLine < lineNum) //down
        {
            currentLine++;
            lineInConsole++;
            if (lineInConsole + y > 23) {
                lineInConsole = 1;
                drawRectangle(8, 10, 95, 15, 15);
                drawRectangle(8, 10, 95, 15, 11);
                drawList(5, filename, y, a, b, lineNum, currentLine);
                getLineInfo(filename, currentLine, column, 5);
                drawRectangle(8, y + lineInConsole, 95, 1, 14);
                textBgColor(0, 14);
                for (int i = 0; i < 5; i++) {
                    printtext(column[i], b[i], y + lineInConsole);
                }
            }
            else
                moveDown(filename, currentLine, 5, b, y, column, lineInConsole,95,8);
        }
        if (ch == 13) {
            textBgColor(0, 15);
            showStudentInclass(Y,column[1]);
            listClass(Y);
        }
        if (ch == 'c') {
            textBgColor(0, 15);
            change_Year_Semester(Y);
            listClass(Y);
        }
    } while (true);
    textBgColor(0, 15);
}

void showStudentInclass(SchoolYear Y,string classname) {
    string year = Y.year, semester = Y.semester.Name;
    char ch;
    hidePointer();
    system("cls");
    textBgColor(13, 15);
    printtext(" _     ___ ____ _____   ____ _____ _   _ ____  _____ _   _ _____ ", 30, 2);
    printtext("| |   |_ _/ ___|_   _| / ___|_   _| | | |  _ \\| ____| \\ | |_   _|", 30, 3);
    printtext("| |    | |\\___ \\ | |   \\___ \\ | | | | | | | | |  _| |  \\| | | | ", 30, 4);
    printtext("| |___ | | ___) || |    ___) || | | |_| | |_| | |___| |\\  | | | ", 30, 5);
    printtext("|_____|___|____/ |_|   |____/ |_|  \\___/|____/|_____|_| \\_| |_| ", 30, 6);

    drawRectangle(97, 0, 22, 6, 11);
    textBgColor(4, 11);
    printtext("-[c]: CHANGE SCHOOL YEAR", 97, 0);
    printtext(" YEAR", 97, 1);
    printtext("-[ESC]: BACK TO MENU", 97, 3);
    printtext("-[ENTER]: CHOSE", 97, 5);

    string filename = "file_save/SchoolYear/" + year + "/" + classname + ".csv";
    int lineNum = countLine(filename);
    int y = 11;
    drawRectangle(8, 10, 100, 15, 11);
    int a[6] = { 8,17,44,63,85,95 };
    int b[6] = { 8,18,36,64,85,95 };
    drawList(6, filename, y, a, b, lineNum, 2);
    hidePointer();

    int currentLine = 2, lineInConsole = 1;
    string column[6];
    getLineInfo(filename, currentLine, column, 6);
    drawRectangle(8, y + lineInConsole, 100, 1, 14);
    textBgColor(0, 14);
    for (int i = 0; i < 6; i++)
        printtext(column[i], b[i], y + lineInConsole);

    do {
        hidePointer();
        ch = getch();
        //[ESC]
        if (ch == 27) {
            break;
        }
        if (ch == 72 && currentLine > 2) //up
        {
            currentLine--;
            lineInConsole--;
            if (lineInConsole + y <= 11) {
                lineInConsole = 12;
                drawRectangle(8, 10, 100, 15, 15);
                drawRectangle(8, 10, 100, 15, 11);
                drawList(6, filename, y, a, b, lineNum, currentLine - 11);
                getLineInfo(filename, currentLine, column, 6);
                drawRectangle(8, y + lineInConsole, 100, 1, 14);
                textBgColor(0, 14);
                for (int i = 0; i < 6; i++) {
                    printtext(column[i], b[i], y + lineInConsole);
                }
            }
            else
                moveUp(filename, currentLine, 6, b, y, column, lineInConsole, 100, 8);
        }
        if (ch == 80 && currentLine < lineNum) //down
        {
            currentLine++;
            lineInConsole++;
            if (lineInConsole + y > 23) {
                lineInConsole = 1;
                drawRectangle(8, 10, 100, 15, 15);
                drawRectangle(8, 10, 100, 15, 11);
                drawList(6, filename, y, a, b, lineNum, currentLine);
                getLineInfo(filename, currentLine, column, 6);
                drawRectangle(8, y + lineInConsole, 105, 1, 14);
                textBgColor(0, 14);
                for (int i = 0; i < 6; i++) {
                    printtext(column[i], b[i], y + lineInConsole);
                }
            }
            else
                moveDown(filename, currentLine, 6, b, y, column, lineInConsole, 100, 8);
        }
        if (ch == 13) {
            User A;
            A.ID = column[1];
            A.info.Class = classname;
            A.info.IDsocial = column[5];
            A.info.Bir = column[3];
            A.info.name = column[2];
            A.info.sex = column[4];
            get_course(A, Y);
            textBgColor(0, 15);
            edit_score(A, Y, view_all_score_of_1_student(A, Y));

            showStudentInclass(Y, classname);
        }
    } while (true);
    textBgColor(0, 15);
}
