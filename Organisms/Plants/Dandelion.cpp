#include "Dandelion.h"
#include "../../Utilities/Random.h"

Dandelion::Dandelion(point position)
        : Plant(position,
                "Dandelion",
                'D',
                OrganismType::DANDELION
)
{
}

void Dandelion::action()
{
    for (int i = 0; i < 3; i++)
    {
        if (Random::isProbable(reproductionProbability))
        {
            this->reproduce(type);
        }
    }
    Organism::action();
}
