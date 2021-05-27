#ifndef Login_h
#define Login_h
#include <iostream>
#include "windows.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <iostream>
#include"Header.h"
#pragma warning(disable : 4996)
using namespace std;

void LoginInterface(User &user);

void repeatLogin(User &user);

int CheckLogin(string& ID, string& password);

void insertUserName(string& username);

void insertPassword(string& password);

#endif
