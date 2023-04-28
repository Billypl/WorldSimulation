#pragma once
#include <windows.h>
#include <iostream>
#include <cmath>
#include "Point.h"

class Console
{

public:

    enum ColorType
    {
        FOREGROUND = 1,
        BACKGROUND = 16
    };

    enum Color
    {
        BLACK = 0,
        BLUE,
        GREEN,
        AQUA,
        RED,
        PURPLE,
        YELLOW,
        WHITE,
        GREY,
        LIGHT_BLUE,
        LIGHT_GREEN,
        LIGHT_AQUA,
        LIGHT_RED,
        LIGHT_PURPLE,
        LIGHT_YELLOW,
        LIGHT_WHITE
    };

    static Color _textColor;
    static Color _backgroundColor;

public:

    static void setTextColor(Color color)
    {
        setColor(color, _backgroundColor);
    }

    static void setBackgroundColor(Color color)
    {
        setColor(_textColor, color);
    }

    static void setDefaultColor()
    {
        setColor(WHITE, BLACK);
    }

    static void setColor(Color textColor, Color backgroundColor)
    {
        _textColor = textColor;
        _backgroundColor = backgroundColor;
        int colorCode = _textColor * ColorType::FOREGROUND + _backgroundColor * ColorType::BACKGROUND;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
    }

    static void setColor(int colorCode)
    {
        _textColor = static_cast<Color>(colorCode % 16);
        _backgroundColor = static_cast<Color>(colorCode / 16);
        setColor(_textColor, _backgroundColor);
    }

    static void gotoxy(point coords)
    {
        gotoxy(coords.x, coords.y);
    }

    static void gotoxy(int x, int y)
    {
        COORD c = {x, y};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }

    static void gotoxy(int x, int y, char character)
    {
        gotoxy(x, y);
        std::cout << character;
    }

    static void gotoxy(point coords, char character)
    {
        gotoxy(coords.x, coords.y, character);
    }

    static void gotoxy(int x, int y, const std::string& str)
    {
        gotoxy(x, y);
        std::cout << str;
    }

    static void gotoxy(point coords, const std::string& str)
    {
        gotoxy(coords.x, coords.y, str);
    }

    static void setCursorType(bool showCursor)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hConsole, &cursorInfo);
        cursorInfo.bVisible = showCursor;
        SetConsoleCursorInfo(hConsole, &cursorInfo);
    }

};

inline Console::Color Console::_textColor = Console::Color::WHITE;
inline Console::Color Console::_backgroundColor = Console::Color::BLACK;
