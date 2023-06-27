#include "sword.h"
#include "../entity.h"

Sword::Sword(QWidget *parent) :
    ActionCard(parent)
{
    name.setText("Sword");
    desc.setText("<=5");
    setPrice(2);
}

void Sword::onUse(Entity *caster, Entity *target){
    ActionCard::onUse(caster, target);
    target->deltaHealth(-cardval, caster);
}

bool Sword::canUse(int val){
    return val <= 5;
}

Sword::~Sword()
{
}
