#include "Grass.h"
#include "../../World/World.h"

Grass::Grass(point position)
    : Plant(position,
            "Grass",
            'G',
            OrganismType::GRASS
            )
{

}