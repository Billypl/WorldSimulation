#include <conio.h>
#include <windows.h>
#include "InputParser.h"
#include "../Utilities/Includes.h"

bool InputParser::chooseMovementInput()
{
    while (true)
    {
        char key = 0;
        switch ((key = getch()))
        {
            //            case KEY_UP:
            //
            //                break;
            //            case KEY_DOWN:
            //
            //                break;
            //            case KEY_LEFT:
            //
            //                break;
            //            case KEY_RIGHT:
            //
            //                break;
            case CONFIRMATION_KEY:
                return true;
            case VK_ESCAPE:
                exit(0);
            default:
                break;
        }
    }
}
