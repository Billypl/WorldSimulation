#include "Organism.h"

int Organism::getInitiative() const
{
    return initiative;
}

void Organism::setInitiative(int initiative)
{
    Organism::initiative = initiative;
}

int Organism::getAgeInTours() const
{
    return ageInTours;
}

void Organism::setAgeInTours(int ageInTours)
{
    Organism::ageInTours = ageInTours;
}

int Organism::getStrength() const
{
    return strength;
}

void Organism::setStrength(int strength)
{
    Organism::strength = strength;
}

const point &Organism::getPosition() const
{
    return position;
}

void Organism::setPosition(const point &position)
{
    Organism::position = position;
}

const std::string &Organism::getName() const
{
    return name;
}
