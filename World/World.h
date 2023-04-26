#pragma once

#include "Board.h"
#include "../Organisms/Organism.h"

class World
{

private:

    Board board;
    std::vector<Organism*> organisms;

private:

    World();

public:

    static World& Get();



};

