#pragma once

#include "../Utilities/Point.h"
#include <string>

class World;

class Organism
{

protected:

    int initiative;
    int ageInTours;
    int strength;
    point position;
    point lastPosition;
    World& world;
    bool _isDead;

public:

    enum OrganismType
    {
        GRASS,
        DANDELION,
        GUARANA,
        WOLFBERRIES,
        SOSNOWSKY_BORSCHT,

        WOLF,
        SHEEP,
        FOX,
        TURTLE,
        ANTELOPE,
        CYBER_SHEEP,

        HUMAN
    };

    const OrganismType type;
    const std::string name;
    const char symbol;
    const int colorCode;

    Organism(point position, const std::string& name, char symbol, OrganismType type, int colorCode);
    bool operator>(Organism* other) const;

    int getInitiative() const;
    void setInitiative(int initiative);
    int getAgeInTours() const;
    void setAgeInTours(int ageInTours);
    int getStrength() const;
    void setStrength(int strength);
    const point &getPosition() const;
    void setPosition(point position);

    static Organism* generateOrganism(OrganismType type, point position);
    void reproduce(OrganismType type);
    void die(Organism* killer);

    bool isDead() const;

    void incrementLivedToursCounter();

    virtual void action() = 0;
    virtual void collision(Organism* other);
    void draw();

};



