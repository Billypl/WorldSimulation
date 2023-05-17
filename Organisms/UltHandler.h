#pragma once
#include "../GUI/GUI.h"

class UltHandler
{

public:

    bool isUltActive = false;
    int cooldown = 10;

    bool isActive();
    void activate();
};
