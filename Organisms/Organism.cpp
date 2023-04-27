#include "Organism.h"
#include "../World/World.h"
#include "../GUI/GUI.h"
#include "../Utilities/Console.h"

using namespace std;

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

Organism::Organism(point position, const string& name, char symbol, OrganismType type, int colorCode)
    : world(World::Get()), name(name), symbol(symbol), type(type), colorCode(colorCode), initiative(-1), ageInTours(-1), strength(-1), position(position) {}

void Organism::draw()
{
    Console::setColor(colorCode);
    GUI::printToBoard(position, symbol);
    Console::setDefaultColor();
}

Organism *Organism::generateOrganism(OrganismType type, point position)
{
    switch(type)
    {
        case GRASS:
            return new Grass(position);
            break;
        default:
            throw "Not a type!";
    }
}

void Organism::reproduce(OrganismType type)
{
    optional<point> freeField = world.getFreeField(this);
    if(freeField.has_value() && World::isInBounds(freeField.value()))
    {
        Organism* organism = Organism::generateOrganism(type, freeField.value());
        world.getOrganisms().push_back(organism);

        string message = organism->name + " has reproduced\n";
        GUI::logMessage += message;
    }

}


