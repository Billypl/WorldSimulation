#include "Animal.h"
#include "../../Utilities/Random.h"


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
    point newPosition(-1, -1);
    Organism::action();
    auto This = world.getOrganism(this);

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
