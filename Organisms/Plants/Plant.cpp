#include "Plant.h"
#include <optional>
#include "../../World/World.h"
#include "../../Utilities/Random.h"

using namespace std;

void Plant::action()
{
    if(Random::isProbable(reproductionProbability))
    {
        this->reproduce(type);
    }
}
