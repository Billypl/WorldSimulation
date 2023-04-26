#include "GUI.h"
#include "../Utilities/Console.h"
#include "../Utilities/Includes.h"
#include <iostream>

using namespace std;

const char GUI::BORDER_CHAR = '#';
const string GUI::AUTHOR = "Michal Pawilojc, 193159";

void GUI::printToBoard(char ch, const point& x)
{
    point alignedPosition = BOARD_POS;
    alignedPosition += x;
    Console::gotoxy(alignedPosition, ch);
}

void GUI::printToLogger(string str)
{
    Console::gotoxy(LOG_POS - point(0,1), "Logger: ");
    Console::gotoxy(LOG_POS, str);
}

void GUI::printBoard()
{
    Console::gotoxy(BOARD_POS - point(1, 2), AUTHOR);
    printHorizontalBorder(-1);
    printHorizontalBorder(BOARD_SIZE.second + 1);
    printVerticalBorder(-1);
    printVerticalBorder(BOARD_SIZE.first + 1);
}

void GUI::printHorizontalBorder(int y)
{
    for(int i = -1; i < BOARD_SIZE.first + 2; i++)
        Console::gotoxy(BOARD_POS + point(i, y), BORDER_CHAR);
}

void GUI::printVerticalBorder(int x)
{
    for(int i = -1; i < BOARD_SIZE.second + 2; i++)
        Console::gotoxy(BOARD_POS + point(x, i), BORDER_CHAR);
}