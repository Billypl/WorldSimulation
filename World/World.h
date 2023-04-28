#pragma once
#include <optional>
#include "../Organisms/Organism.h"
#include "../Organisms/Plants/Grass.h"

class World
{

private:

    std::vector<Organism*> organisms;
    int toursCounter = 0;

private:

    World();
    ~World();

public:

    enum Field
    {
        UPPER_FIELD,
        BOTTOM_FIELD,
        LEFT_FIELD,
        RIGHT_FIELD
    };

    static World& Get();
    void start();
    std::vector<Organism*>& getOrganisms();
    bool isFieldTaken(Organism* organism, Field field);
    std::optional<point> getFreeField(Organism* organism);
    static bool isInBounds(point position);
    Organism*  findOrganismByPosition(point position);
    int findOrganismIndexByPosition(point position);

private:

    void doTurn();
    void drawOrganisms();
    static point getOffsettedField(Organism* organism, Field field);

};

