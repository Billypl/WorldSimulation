#pragma once
#include "Animal.h"

class Human : public Animal
{

    static bool isUltimateActive;
    static int cooldown;

public:

    Human(point position);

    void collision(std::shared_ptr<Organism> other) override;

    void action() override;

    void destroyNeighbour(std::shared_ptr<Organism> &This, World::Field field);

    static void activeteUlt();
};
