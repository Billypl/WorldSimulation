#pragma once
#include "../Organism.h"
#include "../../World/World.h"
#include "../../Utilities/Console.h"


using enum Console::ColorType;
using enum Console::Color;

class Animal : public Organism
{

public:
    void action() override;

    Animal(point position,
           int initiative,
           int strength,
           const std::string &name,
           char symbol,
           OrganismType type);
};
