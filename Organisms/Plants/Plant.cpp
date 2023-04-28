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
    Organism::action();
}

void Plant::collision(std::shared_ptr<Organism> other)
{
    die(other);
}
