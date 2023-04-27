#include "World.h"
#include "../GUI/GUI.h"
#include "InputParser.h"
#include "../Organisms/Plants/Grass.h"
#include <iostream>

using namespace std;


World::World()
{

}

World::~World()
{
    for(auto organism : organisms)
    {
        delete organism;
    }
}

World &World::Get()
{
    static World world;
    return world;
}

void World::start()
{
    GUI::printBoard();
    organisms.push_back(new Grass(point(3,2)));
    while(true)
    {
        doTurn();
    }
}

void World::doTurn()
{
    drawOrganisms();
    InputParser::chooseMovementInput();
    int organismsCount = organisms.size();
    for(int i = 0; i < organismsCount; i++)
    {
        organisms[i]->action();
    }
    GUI::printToLogger();
}

bool World::isFieldTaken(Organism *organism, Field field)
{
    point fieldToCheck = getOffsettedField(organism, field);
    for(Organism* it : organisms)
        if(it->getPosition() == fieldToCheck)
            return true;
    return false;
}

void World::drawOrganisms()
{
    for(Organism* organism : organisms)
        organism->draw();
}

vector<Organism *> &World::getOrganisms()
{
    return organisms;
}

optional<point> World::getFreeField(Organism *organism)
{
    if(!isFieldTaken(organism, Field::UPPER_FIELD))
        return getOffsettedField(organism, Field::UPPER_FIELD);
    if(!isFieldTaken(organism, Field::RIGHT_FIELD))
        return getOffsettedField(organism, Field::RIGHT_FIELD);
    if(!isFieldTaken(organism, Field::BOTTOM_FIELD))
        return getOffsettedField(organism, Field::BOTTOM_FIELD);
    if(!isFieldTaken(organism, Field::LEFT_FIELD))
        return getOffsettedField(organism, Field::LEFT_FIELD);
    return nullopt;
}

point World::getOffsettedField(Organism *organism, Field field)
{
    point offset;
    switch (field)
    {
        case UPPER_FIELD:
            offset = point(0, -1);
            break;
        case BOTTOM_FIELD:
            offset = point(0, 1);
            break;
        case LEFT_FIELD:
            offset = point(-1, 0);
            break;
        case RIGHT_FIELD:
            offset = point(1, 0);
            break;
    }
    return organism->getPosition() + offset;
}

bool World::isInBounds(point position)
{
    return  position.x >= 0 &&
            position.x <= BOARD_SIZE.first &&
            position.y >= 0 &&
            position.y <= BOARD_SIZE.second;
}

Organism *World::findOrganismByPosition(point position)
{
    for(auto organism : organisms)
    {
        if(organism->getPosition() == position)
            return organism;
    }
}


