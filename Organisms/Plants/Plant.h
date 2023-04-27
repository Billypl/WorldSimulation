#pragma once

#include "../Organism.h"

class Plant : public Organism
{

protected:

    double reproductionProbability = 0.5;

public:

    Plant(point position, const std::string& name, char symbol, int colorCode)
        : Organism(position, name, symbol, colorCode)
    {
        initiative = 0;
    }

    void action() override;
};

