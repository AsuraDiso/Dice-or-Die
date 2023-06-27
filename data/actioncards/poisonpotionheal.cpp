#include "poisonpotionheal.h"
#include "../entity.h"

PoisonPotionHeal::PoisonPotionHeal(QWidget *parent) :
    ActionCard(parent)
{
    name.setText("Poison Heal Potion");
    desc.setText(">=5\nHeals+shield");
    setPrice(2);
}

void PoisonPotionHeal::onUse(Entity *caster, Entity *target){
    ActionCard::onUse(caster, target);
    caster->deltaHealth(target->getPoison(), target);
    caster->setShield(target->getPoison()/2);
}

bool PoisonPotionHeal::canUse(int val){
    return val >= 5;
}

PoisonPotionHeal::~PoisonPotionHeal()
{
}
