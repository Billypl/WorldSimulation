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
    static bool isInBounds(point position);
    static point getOffset(Field field);
    static point getOffsettedField(std::shared_ptr<Organism> organism, Field field);

    void start();
    std::vector<std::shared_ptr<Organism>>& getOrganisms();
    bool isFieldTaken(std::shared_ptr<Organism> organism, Field field) const;
    bool isFieldTaken(point field) const;
    std::shared_ptr<Organism> getOrganism(Organism* organism);
    std::shared_ptr<Organism> findOrganismByPosition(point position);
    int findOrganismIndexByPosition(point position);
    std::optional<point> getFreeField(std::shared_ptr<Organism> organism);

private:

    void doTurn();
    void drawOrganisms();
    void manipulateIterIfNecessary(int &organismsCount, int &i, std::weak_ptr <Organism> organism);

};

