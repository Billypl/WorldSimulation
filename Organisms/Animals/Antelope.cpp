#include "Antelope.h"
#include "../../Utilities/Random.h"

Antelope::Antelope(point position)
        : Animal(position,
                 4,
                 4,
                 "Antelope",
                 'A',
                 ANTELOPE
)
{}

void Antelope::action()
{
    Organism::action();
    auto This = world.getOrganism(this);

    point newPosition = point(-1, -1);
    while (!World::isInBounds(newPosition))
    {
        World::Field field = static_cast<World::Field>(Random::range(0, 3));
        newPosition = World::getOffsettedField(This, field);
        newPosition = World::getOffsettedField(This, field);
    }
    this->position = newPosition;
    if(world.isFieldTaken(newPosition))
    {
        world.findOrganismByPosition(newPosition)->collision(This);
    }
    else
    {
        this->position = newPosition;
    }
}
