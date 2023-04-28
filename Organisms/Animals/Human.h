#pragma once
#include "Animal.h"

class Human : public Animal
{

public:

    static bool isUltimateActive;
    static int cooldown;

    Human(point position);

    void collision(std::shared_ptr<Organism> other) override;

    void action() override;

    void destroyNeighbour(std::shared_ptr<Organism> &This, World::Field field);
};
