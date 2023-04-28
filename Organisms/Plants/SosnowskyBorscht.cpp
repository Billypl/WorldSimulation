#include "SosnowskyBorscht.h"
#include "../../World/World.h"

SosnowskyBorscht::SosnowskyBorscht(point position)
        : Plant(position,
                "SosnowskyBorscht",
                'S',
                OrganismType::SOSNOWSKY_BORSCHT
)
{

}

void SosnowskyBorscht::action()
{
    using enum World::Field;

    auto tmp = world.findOrganismByPosition(this->getPosition());
    destroyNeighbour(tmp, UPPER_FIELD);
    destroyNeighbour(tmp, BOTTOM_FIELD);
    destroyNeighbour(tmp, RIGHT_FIELD);
    destroyNeighbour(tmp, LEFT_FIELD);

    Plant::action();
}

void SosnowskyBorscht::destroyNeighbour(std::shared_ptr<Organism> &tmp, World::Field field)
{
    if(world.isFieldTaken(tmp, field))
    {
        auto toDelete = world.findOrganismByPosition(World::getOffsettedField(tmp, field));
        if(toDelete->type == SOSNOWSKY_BORSCHT ||
                toDelete->type == WOLFBERRIES ||
                toDelete->type == GUARANA ||
                toDelete->type == DANDELION ||
                toDelete->type == GRASS
        )
            return;

        toDelete->die(tmp);
    }
}

void SosnowskyBorscht::collision(std::shared_ptr<Organism> other)
{
    other->die(world.findOrganismByPosition(other->getPosition()));
    Plant::collision(other);
}
