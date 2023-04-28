#include "Animal.h"
#include "../../Utilities/Random.h"

using namespace std;

Animal::Animal(point position,
               int initiative,
               int strength,
               const std::string &name,
               char symbol,
               OrganismType type
               )
        : Organism(position, name, symbol, type, LIGHT_YELLOW * BACKGROUND + BLACK * FOREGROUND)
{
    this->initiative = initiative;
    this->strength = strength;
}

void Animal::action()
{
    Organism::action();
    auto This = world.getOrganism(this);

    point newPosition(-1, -1);
    while (!World::isInBounds(newPosition))
    {
        World::Field field = static_cast<World::Field>(Random::range(0, 3));
        newPosition = World::getOffsettedField(This, field);
    }
    if(world.isFieldTaken(newPosition))
    {
        world.findOrganismByPosition(newPosition)->collision(This);
    }
    else
    {
        this->position = newPosition;
    }
}

void Animal::die(shared_ptr<Organism> killer)
{
    point position = this->getPosition();
    Organism::die(killer);
    killer->setPosition(position);
}

void Animal::collision(std::shared_ptr<Organism> other)
{
    if(this->type == other->type)
    {
        if(Random::isProbable(reproductionProbability))
        {
            reproduce(type);
        }
        return;
    }

    if(this->strength > other->getStrength())
        other->die(shared_ptr<Organism>(this));
    else
        this->die(other);
}
