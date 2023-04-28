#pragma once

#include "../Utilities/Point.h"
#include "../Utilities/Includes.h"
#include <string>

class GUI
{

    static const char BORDER_CHAR;
    static const std::string AUTHOR;
    static int lastLoggedMessagesCount;

public:

    static std::string logMessage;
    static void printToBoard(point position, char ch);
    static void printLogger(int toursCounter);
    static void printLogger(std::string &str, int toursCounter);
    static void printBoard();

private:

    static void clearLogger();
    static void printHorizontalBorder(int y);
    static void printVerticalBorder(int x);

};

