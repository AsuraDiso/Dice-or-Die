#include "boomerang.h"
#include "../entity.h"

Boomerang::Boomerang(QWidget *parent) :
    ActionCard(parent)
{
    name.setText("Boomerang");
    desc.setText("2xDMG and DMG back");
    setPrice(3);
}

void Boomerang::onUse(Entity *caster, Entity *target){
    ActionCard::onUse(caster, target);
    caster->deltaHealth(-cardval, target);
    target->deltaHealth(-2*cardval, caster);
}

bool Boomerang::canUse(int val){
    return val <= 6;
}

Boomerang::~Boomerang()
{
}
