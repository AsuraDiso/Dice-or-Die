#include "poisonbite.h"
#include "../entity.h"

PoisonBite::PoisonBite(QWidget *parent) :
    ActionCard(parent)
{
    name.setText("Poison Bite");
    desc.setText("<=2");
    setPrice(3);
}

void PoisonBite::onUse(Entity *caster, Entity *target){
    ActionCard::onUse(caster, target);
    target->setPoison(cardval);
}

bool PoisonBite::canUse(int val){
    return val <= 2;
}

PoisonBite::~PoisonBite()
{
}
