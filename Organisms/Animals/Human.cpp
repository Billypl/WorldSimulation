#include "Human.h"
#include "../../World/InputParser.h"
#include "../../GUI/GUI.h"
#include <memory>

using namespace std;

UltHandler Human::ultimate;

Human::Human(point position)
    : Animal(position,
             4,
             5,
             "Human",
             'H',
             HUMAN)
{}

void Human::action()
{
    point newPosition = this->position + InputParser::DIRECTION;
    if (World::isInBounds(newPosition))
    {
        if(world.isFieldTaken(newPosition) && this->position != newPosition)
        {
            world.findOrganismByPosition(newPosition)->collision(world.getOrganism(this));
        }
        else
        {
            this->position = newPosition;
        }
    }
    if(ultimate.isActive())
    {
        auto This = world.getOrganism(this);
        destroyNeighbour(This, World::Field::UPPER_FIELD);
        destroyNeighbour(This, World::Field::BOTTOM_FIELD);
        destroyNeighbour(This, World::Field::RIGHT_FIELD);
        destroyNeighbour(This, World::Field::LEFT_FIELD);
    }
}

void Human::destroyNeighbour(std::shared_ptr<Organism> &This, World::Field field)
{
    if(world.isFieldTaken(This, field))
    {
        auto toDelete = world.findOrganismByPosition(World::getOffsettedField(This, field));
        toDelete->die(This);
    }
}

void Human::collision(std::shared_ptr<Organism> other)
{
    if(this->strength > other->getStrength())
        other->die(world.getOrganism(this));
    else
        this->die(other);
}

