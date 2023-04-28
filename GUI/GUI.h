#pragma once

#include "../Utilities/Point.h"
#include "../Utilities/Includes.h"
#include <string>

class GUI
{

    static const char BORDER_CHAR;
    static const std::string AUTHOR;
    static const int MAX_LOG_CAPACITY;

public:

    static std::string logMessage;
    static void printToBoard(point position, char ch);
    static void printLogger(int turnsCounter);
    static void printLogger(std::string &str, int turnsCounter);
    static void printBoard();

private:

    static void clearLogger();
    static void printHorizontalBorder(int y);
    static void printVerticalBorder(int x);

};

