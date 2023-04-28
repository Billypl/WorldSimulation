#include "Plant.h"

class Guarana : public Plant
{

public:

    static const int BONUS_STRENGTH;

    Guarana(point position);
    void collision(Organism* organism) override;

};
