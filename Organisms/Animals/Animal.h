#pragma once
#include "../Organism.h"
#include "../../World/World.h"
#include "../../Utilities/Console.h"
#include <memory>


using enum Console::ColorType;
using enum Console::Color;

class Animal : public Organism
{

public:

    void action() override;

    void die(std::shared_ptr<Organism> killer);

    const double reproductionProbability = 0.25;

    Animal(point position,
           int initiative,
           int strength,
           const std::string &name,
           char symbol,
           OrganismType type);

    void collision(std::shared_ptr<Organism> other) override;


};
