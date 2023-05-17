#include <conio.h>
#include <windows.h>
#include "InputParser.h"
#include "../Utilities/Includes.h"
#include "World.h"
#include "../Organisms/Animals/Human.h"
#include "../GUI/GUI.h"
#include "FileParser.h"
#include <iostream>

const int InputParser::KEY_UP = 72;
const int InputParser::KEY_DOWN = 80;
const int InputParser::KEY_LEFT = 75;
const int InputParser::KEY_RIGHT = 77;
const int InputParser::CONFIRMATION_KEY = ' ';
point InputParser::DIRECTION = point(0,0);

void InputParser::chooseMovementInput()
{
    while (true)
    {
        char key = 0;
        switch ((key = getch()))
        {
            case KEY_UP:
                DIRECTION = World::getOffset(World::Field::UPPER_FIELD);
                break;
            case KEY_DOWN:
                DIRECTION = World::getOffset(World::Field::BOTTOM_FIELD);
                break;
            case KEY_LEFT:
                DIRECTION = World::getOffset(World::Field::LEFT_FIELD);
                break;
            case KEY_RIGHT:
                DIRECTION = World::getOffset(World::Field::RIGHT_FIELD);
                break;
            case 'u':
                Human::ultimate.activate();
                break;
            case 's':
                FileParser::saveToFile("game.txt", &World::Get());
                break;
            case CONFIRMATION_KEY:
                return;
            case VK_ESCAPE:
                exit(0);
            default:
                break;
        }
    }
}
