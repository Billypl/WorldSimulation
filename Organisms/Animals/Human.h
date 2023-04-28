#pragma once
#include "Animal.h"

class Human : public Animal
{

public:

    Human(point position);

    void collision(std::shared_ptr<Organism> other) override;

    void action() override;

};
