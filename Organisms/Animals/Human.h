#pragma once
#include "Animal.h"
#include "../UltHandler.h"

class Human : public Animal
{

public:

    static UltHandler ultimate;

    Human(point position);

    void collision(std::shared_ptr<Organism> other) override;

    void action() override;

    void destroyNeighbour(std::shared_ptr<Organism> &This, World::Field field);

};
