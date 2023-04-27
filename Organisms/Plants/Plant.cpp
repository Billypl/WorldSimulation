#include "Plant.h"
#include <optional>
#include "../../World/World.h"
#include "../Organism.h"
#include "../../Utilities/Random.h"

using namespace std;

void Plant::action()
{
    this->reproduce(OrganismType::GRASS);
}
