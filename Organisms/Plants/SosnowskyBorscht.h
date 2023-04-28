#pragma once
#include "Plant.h"
#include "../../World/World.h"


class SosnowskyBorscht : public Plant
{

public:

    SosnowskyBorscht(point position);

    void action() override;

    void collision(std::shared_ptr<Organism> other) override;

private:

    void destroyNeighbour(std::shared_ptr<Organism> &tmp, World::Field field);

};


