#pragma once
#include <windows.h>

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

};

Console::Color Console::_textColor = Console::Color::WHITE;
Console::Color Console::_backgroundColor = Console::Color::BLACK;
