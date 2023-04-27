#include "Plant.h"
#include <optional>
#include "../../World/World.h"
#include "../Organism.h"
#include "../../Utilities/Random.h"

using namespace std;

const double Plant::reproductionProbability = 0.1;

void Plant::action()
{
    if(Random::isProbable(reproductionProbability))
        this->reproduce(type);
}
