#pragma once
#include <optional>
#include "../Organisms/Organism.h"
#include "../Organisms/Plants/Grass.h"

class World
{

private:

    std::vector<Organism*> organisms;

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

private:

    void doTurn();
    void drawOrganisms();
    Organism*  findOrganismByPosition(point position);
    static point getOffsettedField(Organism* organism, Field field);

};

