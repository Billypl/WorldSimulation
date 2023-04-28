#pragma once
#include "Animal.h"

class Antelope : public Animal
{

public:

    Antelope(point position);

    void action() override;

};
