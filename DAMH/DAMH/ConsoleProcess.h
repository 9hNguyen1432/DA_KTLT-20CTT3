#ifndef CSP_H
#define CSP_H
#include <iostream>
#include "windows.h"
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include"Header.h"
/*
	Color:
        0 black
        1 blue
        2 green
        3 aqua
        4 red
        5 purple
        6 yellow
        7 white
        8 gray
        9 light blue
        10 light green
        11 light aqua
        12 light red
        13 light purple
        14 light yellow
        15 bright white
*/
void gotoxy(short int x, short int y);

void textColor(int color);

void textBgColor(int colorText, int colorBG);

void drawRectangle(int positionX, int positionY, int width, int height, int color);

int ReturnX();

int ReturnY();

void hidePointer();

void showPointer();

void DrawAppName(int TextColor, int BgColor);

void drawBoder(int positionX, int positionY, int width, int height, int color);
#endif