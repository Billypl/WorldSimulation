#pragma once

#include "../Utilities/Point.h"
#include "../Utilities/Includes.h"
#include <string>

class GUI
{

    static const char BORDER_CHAR;
    static const std::string AUTHOR;

public:

    static std::string logMessage;
    static void printToBoard(const point &x, char ch);
    static void printToLogger();
    static void printBoard();

private:

    static void printHorizontalBorder(int y);
    static void printVerticalBorder(int x);

};

