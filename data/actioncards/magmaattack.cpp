#include "magmaattack.h"
#include "../entity.h"

MagmaAttack::MagmaAttack(QWidget *parent) :
    ActionCard(parent)
{
    name.setText("Magma Attack");
    desc.setText("Tylko nie parzyste");
    setPrice(3);
}

void MagmaAttack::onUse(Entity *caster, Entity *target){
    ActionCard::onUse(caster, target);
    target->deltaHealth(-cardval, caster);
    target->setBurn(2);
}

bool MagmaAttack::canUse(int val){
    return (val % 2) == 1;
}

MagmaAttack::~MagmaAttack()
{
}
