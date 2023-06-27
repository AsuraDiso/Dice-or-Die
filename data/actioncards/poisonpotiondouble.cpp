#include "poisonpotiondouble.h"
#include "../entity.h"

PoisonPotionDouble::PoisonPotionDouble(QWidget *parent) :
    ActionCard(parent)
{
    name.setText("Poison Double Potion");
    desc.setText("=6");
    setPrice(2);
}

void PoisonPotionDouble::onUse(Entity *caster, Entity *target){
    ActionCard::onUse(caster, target);
    target->setPoison(target->getPoison());
}

bool PoisonPotionDouble::canUse(int val){
    return val == 6;
}

PoisonPotionDouble::~PoisonPotionDouble()
{
}
