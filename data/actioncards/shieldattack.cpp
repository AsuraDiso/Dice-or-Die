#include "shieldattack.h"
#include "../entity.h"

ShieldAttack::ShieldAttack(QWidget *parent) :
    ActionCard(parent)
{
    name.setText("Shield Attack");
    desc.setText("<=4");
    setPrice(3);
}

void ShieldAttack::onUse(Entity *caster, Entity *target){
    ActionCard::onUse(caster, target);
    caster->setShield(cardval);
    target->deltaHealth(caster->getShield(), caster);
}

bool ShieldAttack::canUse(int val){
    return val <= 4;
}

ShieldAttack::~ShieldAttack()
{
}
