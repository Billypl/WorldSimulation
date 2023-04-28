#pragma once
#include "Animal.h"

class Turtle : public Animal
{

public:
    void action() override;

    Turtle(point position);

    void collision(std::shared_ptr<Organism> other) override;

};


