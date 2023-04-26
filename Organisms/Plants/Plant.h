#pragma once

#include "../Organism.h"

class Plant : public Organism
{

public:

    Plant(const std::string& name, char symbol, int colorCode)
        : Organism(name, symbol, colorCode) {
        initiative = 0;
    }

    void action() override;
};

