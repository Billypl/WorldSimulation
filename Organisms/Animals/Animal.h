#pragma once
#include "../Organism.h"

class Animal : public Organism
{

public:

    Animal(point position, const std::string& name, char symbol, int colorCode);
    void action() override;
    void collision() override;

};
