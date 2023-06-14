#include "shield.h"
#include "../entity.h"

Shield::Shield(QWidget *parent) :
    ActionCard(parent)
{
    name.setText("Shield");
    setPrice(4);
}

void Shield::onUse(Entity *caster, Entity *target){
    ActionCard::onUse(caster, target);
    caster->setShield(cardval);
}

bool Shield::canUse(int val){
    return val <= 6;
}

Shield::~Shield()
{
}
