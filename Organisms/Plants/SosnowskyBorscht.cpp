#include "SosnowskyBorscht.h"
#include "../../World/World.h"

SosnowskyBorscht::SosnowskyBorscht(point position)
        : Plant(position,
                "SosnowskyBorscht",
                'S',
                OrganismType::SOSNOWSKY_BORSCHT
)
{
    this->strength = 10;
}

void SosnowskyBorscht::action()
{
    using enum World::Field;

    auto This = world.getOrganism(this);
    destroyNeighbour(This, UPPER_FIELD);
    destroyNeighbour(This, BOTTOM_FIELD);
    destroyNeighbour(This, RIGHT_FIELD);
    destroyNeighbour(This, LEFT_FIELD);

    Plant::action();
}

void SosnowskyBorscht::destroyNeighbour(std::shared_ptr<Organism> &This, World::Field field)
{
    if(world.isFieldTaken(This, field))
    {
        auto toDelete = world.findOrganismByPosition(World::getOffsettedField(This, field));
        if(toDelete->type == SOSNOWSKY_BORSCHT ||
                toDelete->type == WOLFBERRIES ||
                toDelete->type == GUARANA ||
                toDelete->type == DANDELION ||
                toDelete->type == GRASS
        )
            return;

        toDelete->die(This);
    }
}

void SosnowskyBorscht::collision(std::shared_ptr<Organism> other)
{
    other->die(world.getOrganism(this));
    Plant::collision(other);
}
