#include "Guarana.h"

const int Guarana::BONUS_STRENGTH = 3;

Guarana::Guarana(point position)
        : Plant(position,
                "Guarana",
                'g',
                OrganismType::GUARANA
                ) {}

void Guarana::collision(std::shared_ptr <Organism> organism)
{
    organism->setStrength(organism->getStrength() + BONUS_STRENGTH);
}
