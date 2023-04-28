#include "Wolfberries.h"
#include "../../World/World.h"

Wolfberries::Wolfberries(point position)
        : Plant(position,
                "Wolfberries",
                'W',
                OrganismType::WOLFBERRIES
)
{

}

void Wolfberries::collision(std::shared_ptr<Organism> other)
{
    other->die(world.findOrganismByPosition(other->getPosition()));
    Plant::collision(other);
}



