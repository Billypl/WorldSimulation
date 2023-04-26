#pragma once

#include "../Organism.h"

class Plant : public Organism
{

public:

    Plant()
    {
        initiative = 0;
    }

    void action() override;
};

