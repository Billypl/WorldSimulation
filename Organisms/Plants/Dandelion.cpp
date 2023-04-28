#include "Dandelion.h"

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
    Plant::action();
    Plant::action();
    Plant::action();
}
