#include "poisonpotion.h"
#include "../entity.h"

PoisonPotion::PoisonPotion(QWidget *parent) :
    ActionCard(parent)
{
    name.setText("Poison Potion");
    desc.setText("<=4");
    setPrice(3);
}

void PoisonPotion::onUse(Entity *caster, Entity *target){
    ActionCard::onUse(caster, target);
    target->setPoison(cardval);
}

bool PoisonPotion::canUse(int val){
    return val <= 4;
}

PoisonPotion::~PoisonPotion()
{
}
