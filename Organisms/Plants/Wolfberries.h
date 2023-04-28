#pragma once
#include "Plant.h"
#include "../../World/World.h"

class Wolfberries : public Plant
{

public:

    Wolfberries(point position);

    void collision(std::shared_ptr<Organism> other) override;

};


