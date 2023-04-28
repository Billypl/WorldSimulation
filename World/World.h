#pragma once
#include <optional>
#include <memory>
#include "../Organisms/Organism.h"
#include "../Organisms/Plants/Grass.h"

class World
{

private:

    std::vector<std::shared_ptr<Organism>> organisms;
    int turnCounter = 0;

private:

    World();

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
    std::vector<std::shared_ptr<Organism>>& getOrganisms();
    bool isFieldTaken(std::shared_ptr<Organism> organism, Field field);
    std::optional<point> getFreeField(std::shared_ptr<Organism> organism);
    static bool isInBounds(point position);
    std::shared_ptr<Organism>  findOrganismByPosition(point position);
    int findOrganismIndexByPosition(point position);
    static point getOffsettedField(std::shared_ptr<Organism> organism, Field field);

private:

    void doTurn();
    void drawOrganisms();
    void manipulateIterIfNecessary(int &organismsCount, int &i, std::weak_ptr <Organism> organism);

};

