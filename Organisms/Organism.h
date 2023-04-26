#pragma once

#include "../Utilities/Point.h"
#include <string>

class World
{
public:
    static World& Get()
    {
        static World world;
        return world;
    }
};

class Organism
{

protected:

    int initiative;
    int ageInTours;
    int strength;
    point position;
    const std::string name;
    World& world;

public:

    Organism()
        : world(World::Get()) {}

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
    virtual void draw() = 0;

};



