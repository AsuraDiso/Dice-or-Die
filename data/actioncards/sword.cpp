#include "sword.h"
#include "../entity.h"

Sword::Sword(QWidget *parent) :
    ActionCard(parent)
{
    name.setText("Sword");
    setPrice(2);
}

void Sword::onUse(Entity *caster, Entity *target){
    ActionCard::onUse(caster, target);
    target->deltaHealth(-cardval, caster);
}

bool Sword::canUse(int val){
    return true;
}

Sword::~Sword()
{
}
