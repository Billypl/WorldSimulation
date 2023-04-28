#include "Guarana.h"

const int Guarana::BONUS_STRENGTH = 3;

Guarana::Guarana(point position)
        : Plant(position,
                "Guarana",
                'g',
                OrganismType::GUARANA
                ) {}

void Guarana::collision(Organism *organism)
{
    organism->setStrength(organism->getStrength() + BONUS_STRENGTH);
}
