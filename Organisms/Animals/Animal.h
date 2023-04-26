#pragma once
#include "../Organism.h"

class Animal : public Organism
{

public:

//    Animal(const std::string& name, char symbol, int colorCode);
    void action() override;
    void collision() override;

};
