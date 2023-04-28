#include "Organism.h"
#include "../World/World.h"
#include "../GUI/GUI.h"
#include "Plants/Grass.h"
#include "Plants/Dandelion.h"
#include "Plants/Guarana.h"
#include "Plants/Wolfberries.h"
#include "Plants/SosnowskyBorscht.h"
#include "Animals/Wolf.h"
#include "Animals/Sheep.h"
#include "Animals/Fox.h"
#include "../Utilities/Random.h"
#include "Animals/Turtle.h"
#include "Animals/Human.h"

using namespace std;


int Organism::getInitiative() const
{
    return initiative;
}

void Organism::setInitiative(int initiative)
{
    Organism::initiative = initiative;
}

int Organism::getAgeInTurns() const
{
    return ageInTurns;
}

void Organism::setAgeInTurns(int ageInTurns)
{
    Organism::ageInTurns = ageInTurns;
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
    ageInTurns(0),
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

shared_ptr<Organism> Organism::generateOrganism(OrganismType type, point position)
{
    if(!World::isInBounds(position))
        throw "Out of board";

    switch(type)
    {
        case GRASS:
            return make_shared<Grass>(position);
            break;
        case DANDELION:
            return  make_shared<Dandelion>(position);
            break;
        case GUARANA:
            return make_shared<Guarana>(position);
            break;
        case WOLFBERRIES:
            return make_shared<Wolfberries>(position);
            break;
        case SOSNOWSKY_BORSCHT:
            return make_shared<SosnowskyBorscht>(position);
            break;
        case WOLF:
            return make_shared<Wolf>(position);
            break;
        case SHEEP:
            return make_shared<Sheep>(position);
            break;
        case FOX:
            return make_shared<Fox>(position);
            break;
        case TURTLE:
            return make_shared<Turtle>(position);
            break;
        case HUMAN:
            return make_shared<Human>(position);
            break;
        default:
            throw "Not a type!";
    }
}

void Organism::reproduce(OrganismType type)
{
    optional<point> freeField = world.getFreeField(world.getOrganism(this));
    if(freeField.has_value() && World::isInBounds(freeField.value()))
    {
        shared_ptr<Organism> organism = Organism::generateOrganism(type, freeField.value());
        world.getOrganisms().push_back(organism);

        string message = organism->name + " has reproduced\n";
        GUI::logMessage += message;
    }
}

bool Organism::operator>(shared_ptr<Organism> other) const
{
    if(this->initiative == other->initiative)
        if(this->ageInTurns > other->ageInTurns)
            return true;
    if(this->initiative > other->initiative)
        return true;
    else
        return false;
}

void Organism::die(shared_ptr<Organism> killer)
{
    GUI::printToBoard(this->lastPosition, ' ');
    GUI::printToBoard(this->position, ' ');
    GUI::logMessage += killer->name + " destroyed " + this->name + '\n';
    int index = world.findOrganismIndexByPosition(this->position);
    world.getOrganisms().erase(world.getOrganisms().begin() + index);
}

void Organism::incrementLivedTurnsCounter()
{
    ageInTurns++;
}

void Organism::action()
{
    incrementLivedTurnsCounter();
}

