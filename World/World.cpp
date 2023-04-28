#include "World.h"
#include "../GUI/GUI.h"
#include "InputParser.h"
#include "../Organisms/Plants/Grass.h"
#include "../Organisms/Plants/Dandelion.h"
#include <iostream>
#include <memory>

using namespace std;


World::World()
{

}

World &World::Get()
{
    static World world;
    return world;
}

void World::start()
{
    GUI::printBoard();
    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::GRASS, point(3,2)));
    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::GRASS, point(3,3)));
    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::GRASS, point(3,4)));
    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::DANDELION, point(10,10)));

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
        weak_ptr<Organism> organism = organisms[i];
        organisms[i]->action();
        organisms[i]->incrementLivedTurnsCounter();
        manipulateIterIfNecessary(organismsCount, i, organism);
    }

    sort(organisms.begin(), organisms.end());
    turnCounter++;
    GUI::printLogger(turnCounter);
}

void World::manipulateIterIfNecessary(int organismsCount, int &i, weak_ptr<Organism> organism)
{
    // function sorts out deleting elements
    if(organisms.size() < organismsCount)
    {
        if(organism.expired())
        {
            i--;
        }
        else
        {
            shared_ptr<Organism> tmp = organism.lock();
            if(findOrganismIndexByPosition(tmp->getPosition()) < i)
            {
                i--;
            }
        }
    }
}

bool World::isFieldTaken(shared_ptr<Organism> organism, Field field)
{
    point fieldToCheck = getOffsettedField(organism, field);
    for(auto it : organisms)
        if(it->getPosition() == fieldToCheck)
            return true;
    return false;
}

void World::drawOrganisms()
{
    for(auto organism : organisms)
        organism->draw();
}

vector<shared_ptr<Organism>> &World::getOrganisms()
{
    return organisms;
}

optional<point> World::getFreeField(shared_ptr<Organism> organism)
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

point World::getOffsettedField(shared_ptr<Organism> organism, Field field)
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

shared_ptr<Organism> World::findOrganismByPosition(point position)
{
    return organisms[findOrganismIndexByPosition(position)];
}

int World::findOrganismIndexByPosition(point position)
{
    for(int i = 0; i < organisms.size(); i++)
    {
        if(organisms[i]->getPosition() == position)
        {
            return i;
        }
    }
    return -1;
}
