#include "UltHandler.h"
#define COOLDOWN_END_TOURS 0
#define ULT_END_TOURS 5
#define ULT_CYCLE_PERIOD 10

bool UltHandler::isActive()
{

    if(cooldown == COOLDOWN_END_TOURS)
    {
        cooldown = ULT_CYCLE_PERIOD;
        GUI::logMessage += "Ult renewed!\n";
    }
    else if(cooldown == ULT_END_TOURS)
    {
        isUltActive = false;
        GUI::logMessage += "Ult deactivated!\n";
    }
    if(cooldown != ULT_CYCLE_PERIOD || isUltActive)
    {
        cooldown--;
    }
}

void UltHandler::activate()
{
    if(cooldown == ULT_CYCLE_PERIOD)
    {
        isUltActive = true;
        GUI::logMessage += "Ult activate!\n";
    }
}
