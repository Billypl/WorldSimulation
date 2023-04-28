#include "Wolfberries.h"
#include "../../World/World.h"

Wolfberries::Wolfberries(point position)
        : Plant(position,
                "Wolfberries",
                'W',
                OrganismType::WOLFBERRIES
)
{
    this->strength = 99;
}

void Wolfberries::collision(std::shared_ptr<Organism> other)
{
    other->die(world.getOrganism(this));
    Plant::collision(other);
}



