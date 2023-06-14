#include "bandage.h"
#include "../entity.h"

Bandage::Bandage(QWidget *parent) :
    ActionCard(parent)
{
    name.setText("Bandage");
    setPrice(3);
}

void Bandage::onUse(Entity *caster, Entity *target){
    ActionCard::onUse(caster, target);
    caster->deltaHealth(cardval, target);
}

bool Bandage::canUse(int val){
    return val <= 3;
}

Bandage::~Bandage()
{
}
