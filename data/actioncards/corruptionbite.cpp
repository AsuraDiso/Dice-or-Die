#include "corruptionbite.h"
#include "../entity.h"

CorruptionBite::CorruptionBite(QWidget *parent) :
    ActionCard(parent)
{
    name.setText("Corruption Bite");
    desc.setText("<=4 + 2 Corruption");
    setPrice(3);
}

void CorruptionBite::onUse(Entity *caster, Entity *target){
    ActionCard::onUse(caster, target);
    target->deltaHealth(-cardval, caster);
    target->setCorruption(2);
}

bool CorruptionBite::canUse(int val){
    return val <= 5;
}

CorruptionBite::~CorruptionBite()
{
}
