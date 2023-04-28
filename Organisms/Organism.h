#pragma once

#include "../Utilities/Point.h"
#include <string>
#include <memory>

class World;

class Organism
{

protected:

    int initiative;
    int ageInTurns;
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
    bool operator>(std::shared_ptr<Organism> other) const;

    int getInitiative() const;
    void setInitiative(int initiative);
    int getAgeInTurns() const;
    void setAgeInTurns(int ageInTurns);
    int getStrength() const;
    void setStrength(int strength);
    const point &getPosition() const;
    void setPosition(point position);

    static std::shared_ptr<Organism> generateOrganism(OrganismType type, point position);
    void reproduce(OrganismType type);
    void die(std::shared_ptr <Organism> killer);

    void incrementLivedTurnsCounter();

    virtual void action();
    virtual void collision(std::shared_ptr <Organism> other) = 0;
    void draw();

};



