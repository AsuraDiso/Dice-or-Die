#include "bow.h"
#include "../entity.h"

Bow::Bow(QWidget *parent) :
    ActionCard(parent)
{
    name.setText("Bow");
    desc.setText("+2 poison");
    setPrice(3);
}

void Bow::onUse(Entity *caster, Entity *target){
    ActionCard::onUse(caster, target);
    target->deltaHealth(-cardval, caster);
    target->setPoison(2);
}

bool Bow::canUse(int val){
    return val <= 6;
}

Bow::~Bow()
{
}
