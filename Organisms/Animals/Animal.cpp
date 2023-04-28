#include "Animal.h"


Animal::Animal(point position, const std::string &name, char symbol, OrganismType type, int colorCode)
        : Organism(position, name, symbol, type, colorCode) {}
