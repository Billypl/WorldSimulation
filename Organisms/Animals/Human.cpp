#include "Human.h"
#include "../../World/InputParser.h"
#include <memory>

using namespace std;

Human::Human(point position)
    : Animal(position,
             4,
             5,
             "Human",
             'H',
             HUMAN)
{

}

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
}

void Human::collision(std::shared_ptr<Organism> other)
{
    if(this->strength > other->getStrength())
        other->die(world.getOrganism(this));
    else
        this->die(other);
}
