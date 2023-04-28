#include "Plant.h"

class Guarana : public Plant
{

public:

    static const int BONUS_STRENGTH;

    Guarana(point position);
    void collision(std::shared_ptr<Organism> organism) override;

};
