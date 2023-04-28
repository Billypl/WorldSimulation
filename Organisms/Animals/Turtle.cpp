#include "Turtle.h"
#include "../../Utilities/Random.h"

Turtle::Turtle(point position)
        : Animal(position,
                 2,
                 1,
                 "Turtle",
                 'T',
                 TURTLE
)
{}

void Turtle::action()
{
    if(Random::isProbable(0.25))
    {
        Animal::action();
    }
    else
    {
        Organism::action();
    }
}

void Turtle::collision(std::shared_ptr<Organism> other)
{
    if(this->type == other->type)
    {
        if(Random::isProbable(reproductionProbability))
        {
            reproduce(type);
        }
        return;
    }

    if(other->getStrength() >= 5)
        this->die(other);
    //TODO: add GUI message






    Animal::collision(other);
}