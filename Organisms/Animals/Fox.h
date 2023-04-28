#pragma once
#include "Animal.h"

class Fox : public Animal
{

public:

    Fox(point position);

    void action() override;

};
