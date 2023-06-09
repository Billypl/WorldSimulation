#pragma once

#include "../Organism.h"
#include "../../Utilities/Console.h"

using enum Console::ColorType;
using enum Console::Color;

class Plant : public Organism
{

public:

    Plant(point position, const std::string& name, char symbol, OrganismType type)
        : Organism(position, name, symbol, type, WHITE * FOREGROUND + GREEN * BACKGROUND)
    {
        initiative = 0;
    }

    const double reproductionProbability = 0.05;

    void action() override;

    void collision(std::shared_ptr<Organism> other) override;
};

