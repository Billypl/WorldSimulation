#include "Fox.h"

Fox::Fox(point position)
        : Animal(position,
                 7,
                 3,
                 "Fox",
                 'F',
                 FOX
)
{}

void Fox::action()
{
    Organism::action();
    auto This = world.getOrganism(this);
    auto newPoint = world.getFreeField(This);
    if(newPoint.has_value() && World::isInBounds(newPoint.value()))
        this->position = newPoint.value();
}

