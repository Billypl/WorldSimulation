#include "FileParser.h"
#include <fstream>
#include "../GUI/GUI.h"

using namespace std;

void FileParser::saveToFile(std::string filename, World *world)
{
    fstream file(filename, ios::out);
    int i = 0;
    for(auto organism : world->getOrganisms())
    {
        i++;
        file << "Organism " << i << endl;
        file << "Position: (" << organism->getPosition().x << ", " << organism->getPosition().y << ")\n";
        file << "Code: " << organism->getType() << endl;
    }
    GUI::logMessage += "Game saved!\n";
}

void FileParser::loadFromFile(std::string filename, World *world)
{

}
