#pragma once

#include "../Utilities/Point.h"

class InputParser
{

    const static int KEY_UP;
    const static int KEY_DOWN;
    const static int KEY_LEFT;
    const static int KEY_RIGHT;
    const static int CONFIRMATION_KEY;

public:

    static point DIRECTION;

    static void chooseMovementInput();
};


