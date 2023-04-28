#include "GUI.h"
#include "../Utilities/Console.h"
#include "../Utilities/Utils.h"

using namespace std;

const char GUI::BORDER_CHAR = '#';
const string GUI::AUTHOR = "Michal Pawiłojć, 193159";
const int GUI::MAX_LOG_CAPACITY = 10;
string GUI::logMessage;

void GUI::printToBoard(point position, char ch)
{
    if (position.x < 0 || position.y < 0)
        return;
    point alignedPosition = BOARD_POS;
    alignedPosition += position;
    Console::gotoxy(alignedPosition, ch);
}

void GUI::printLogger(int turnsCounter)
{
    clearLogger();
    printLogger(logMessage, turnsCounter);
}

void GUI::printLogger(string &str, int turnsCounter)
{
    Console::gotoxy(LOG_POS - point(0, 1), "Logger: (day " + to_string(turnsCounter) + ")");
    vector<string> messages = Utils::splitString(str, '\n');
    for (int i = 0; i < messages.size(); i++)
    {
        Console::gotoxy(LOG_POS + point(0, i), messages[i]);
        if (i > MAX_LOG_CAPACITY)
        {
            Console::gotoxy(LOG_POS + point(0, i),
                            "(And " + to_string(messages.size() - i) + " other messages...)" + string(20, ' '));
            break;
        }
    }
    str.clear();
}

void GUI::clearLogger()
{
    string eraser;
    string line(40, ' ');
    for (int i = 0; i < MAX_LOG_CAPACITY + 2; i++)
        eraser += line + '\n';
    printLogger(eraser, 0);
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
    for (int i = -1; i < BOARD_SIZE.first + 2; i++)
        Console::gotoxy(BOARD_POS + point(i, y), BORDER_CHAR);
}

void GUI::printVerticalBorder(int x)
{
    for (int i = -1; i < BOARD_SIZE.second + 2; i++)
        Console::gotoxy(BOARD_POS + point(x, i), BORDER_CHAR);
}


