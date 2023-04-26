#pragma once

#include "../Utilities/Point.h"
#include "../Utilities/Includes.h"
#include <string>

class GUI
{

    static const char BORDER_CHAR;
    static const std::string AUTHOR;

public:

    static void printToBoard(char ch, const point& x);
    static void printToLogger(std::string str, const point& x);
    static void printBoard();

private:

    static void printHorizontalBorder(int y);
    static void printVerticalBorder(int x);


};

