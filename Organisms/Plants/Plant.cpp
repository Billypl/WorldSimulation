#include "Plant.h"
#include "../../World/World.h"
#include "../../Utilities/Random.h"

using namespace std;

void Plant::action()
{
    if(Random::isProbable(reproductionProbability))
    {
        reproduce(type);
    }
    Organism::action();
}

void Plant::collision(std::shared_ptr<Organism> other)
{
    point pos = this->position;
    die(other);
    other->setPosition(pos);
}
