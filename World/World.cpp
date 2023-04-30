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
    Console::setCursorType(false);
//    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::WOLFBERRIES, point(3,4)));
    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::SHEEP, point(5,5)));
    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::SHEEP, point(9,8)));
//    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::SHEEP, point(8,7)));
//    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::SHEEP, point(7,8)));
//    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::SHEEP, point(8,9)));
//    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::FOX, point(8,8)));
//    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::GUARANA, point(3,3)));
    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::GRASS, point(3,1)));
    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::GRASS, point(3,3)));
    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::GRASS, point(2,2)));
//    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::GRASS, point(4,2)));
//    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::GRASS, point(2,2)));
//    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::GRASS, point(3,1)));
//    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::GRASS, point(4,2)));
    organisms.push_back(Organism::generateOrganism(Organism::OrganismType::HUMAN, point(4,4)));
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
        manipulateIterIfNecessary(organismsCount, i, organism);
    }
    sort(organisms.begin(), organisms.end());
    turnCounter++;
    GUI::printLogger(turnCounter);
}

void World::manipulateIterIfNecessary(int &organismsCount, int &i, weak_ptr<Organism> organism)
{
    // function sorts out deleting elements
    bool expiredCheck = false;
    while(organisms.size() < organismsCount)
    {
        if(organism.expired() && !expiredCheck)
        {
            i--;
            organismsCount--;
            expiredCheck = true;
        }
        else if(!expiredCheck)
        {
            shared_ptr<Organism> tmp = organism.lock();
            if(findOrganismIndexByPosition(tmp->getPosition()) < i)
            {
                i--;
            }
            organismsCount--;
        }
        else
        {
            organismsCount--;
        }
    }
}

bool World::isFieldTaken(shared_ptr<Organism> organism, Field field) const
{
    point fieldToCheck = getOffsettedField(organism, field);
    return isFieldTaken(fieldToCheck);
}

bool World::isFieldTaken(point field) const
{
    for(auto it : organisms)
        if(it->getPosition() == field)
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
    return organism->getPosition() + getOffset(field);
}

point World::getOffset(Field field)
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
    return offset;
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

std::shared_ptr<Organism> World::getOrganism(Organism *organism)
{
    return findOrganismByPosition(organism->getPosition());
}

