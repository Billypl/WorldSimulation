#include "Organism.h"
#include "../World/World.h"
#include "../GUI/GUI.h"
#include "../Utilities/Console.h"
#include "Plants/Grass.h"
#include "Plants/Dandelion.h"
#include "Plants/Guarana.h"

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

void Organism::setPosition(point position)
{
    Organism::position = position;
}

Organism::Organism(point position, const string& name, char symbol, OrganismType type, int colorCode)
    : world(World::Get()),
    name(name),
    symbol(symbol),
    type(type),
    colorCode(colorCode),
    initiative(-1),
    ageInTours(0),
    strength(-1),
    position(position),
    lastPosition(point(-1,-1))
    {}

void Organism::draw()
{
    if(lastPosition != position)
    {
        if(world.findOrganismIndexByPosition(lastPosition) == -1)
        {
            Console::setDefaultColor();
            GUI::printToBoard(lastPosition, ' ');
        }
        Console::setColor(colorCode);
        lastPosition = position;
        GUI::printToBoard(position, symbol);
        Console::setDefaultColor();
    }
}

Organism *Organism::generateOrganism(OrganismType type, point position)
{
    if(!World::isInBounds(position))
        throw "Out of board";

    switch(type)
    {
        case GRASS:
            return new Grass(position);
            break;
        case DANDELION:
            return new Dandelion(position);
            break;
        case GUARANA:
            return new Guarana(position);
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

bool Organism::operator>(Organism *other) const
{
    if(this->initiative == other->initiative)
        if(this->ageInTours > other->ageInTours)
            return true;
    if(this->initiative > other->initiative)
        return true;
    else
        return false;
}

void Organism::collision(Organism *other)
{
    if(this->type == other->type)
    {
        reproduce(type);
        return;
    }

    if(this->strength > other->strength)
        other->die(this);
    else
        this->die(other);
}

void Organism::die(Organism* killer)
{
    GUI::printToBoard(position, ' ');
    GUI::logMessage += killer->name + " destroyed " + this->name + '\n';
    int index = world.findOrganismIndexByPosition(this->position);
    world.getOrganisms().erase(world.getOrganisms().begin() + index);
    delete this;
}

void Organism::incrementLivedToursCounter()
{
    ageInTours++;
}
