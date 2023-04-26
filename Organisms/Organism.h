#pragma once

#include "../Utilities/Point.h"
#include <string>

class World;

class Organism
{

protected:

    const std::string name;
    const char symbol;
    const int colorCode;

    int initiative;
    int ageInTours;
    int strength;
    point position;
    World& world;

public:

    Organism(const std::string& name, char symbol, int colorCode);

    int getInitiative() const;
    void setInitiative(int initiative);
    int getAgeInTours() const;
    void setAgeInTours(int ageInTours);
    int getStrength() const;
    void setStrength(int strength);
    const point &getPosition() const;
    void setPosition(const point &position);
    const std::string &getName() const;

    virtual void action() = 0;
    virtual void collision() {};
    void draw();

};



