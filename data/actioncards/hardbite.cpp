#include "hardbite.h"
#include "../entity.h"

HardBite::HardBite(QWidget *parent) :
    ActionCard(parent)
{
    name.setText("Hard Bite");
    desc.setText("<=4\n2xDMG");
    setPrice(3);
}

void HardBite::onUse(Entity *caster, Entity *target){
    ActionCard::onUse(caster, target);
    target->deltaHealth(-2*cardval, caster);
}

bool HardBite::canUse(int val){
    return val <= 4;
}

HardBite::~HardBite()
{
}
