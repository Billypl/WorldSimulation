#pragma once
#include <string>
#include "World.h"

class FileParser
{

public:

    static void saveToFile(std::string filename, World* world);

    void loadFromFile(std::string filename, World *world);
};


