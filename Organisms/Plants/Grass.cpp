#include "Grass.h"
#include "../../World/World.h"
#include "../../Utilities/Console.h"

using namespace std;

Grass::Grass(point position)
    : Plant(position,
            "Grass",
            'G',
            Console::Color::GREEN * Console::ColorType::BACKGROUND
            )
{

}
