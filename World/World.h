#pragma once
#include "../Organisms/Organism.h"
#include <optional>
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



private:

    void doTurn();
    void drawOrganisms();
    Organism*  findOrganismByPosition();
    point getOffsettedField(Organism* organism, Field field);
};

