#pragma once

#include "../Organism.h"

class Plant : public Organism
{

protected:

    static const double reproductionProbability;

public:

    Plant(point position, const std::string& name, char symbol, OrganismType type, int colorCode)
        : Organism(position, name, symbol, type, colorCode)
    {
        initiative = 0;
    }

    void action() override;
};

