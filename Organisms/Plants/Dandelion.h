#pragma once
#include "Plant.h"

class Dandelion : public Plant
{

public:

    Dandelion(point position);

    void action() override;

};
