#include "Grass.h"
#include "../../World/World.h"
#include "../../Utilities/Console.h"

using namespace std;

using enum Console::ColorType;
using enum Console::Color;

Grass::Grass(point position)
    : Plant(position,
            "Grass",
            'G',
            OrganismType::GRASS,
            WHITE * FOREGROUND + GREEN * BACKGROUND
            )
{

}
