#include "sword.h"
#include "ui_sword.h"
#include "../entity.h"

Sword::Sword(QWidget *parent) :
    ActionCard(parent),
    ui(new Ui::Sword)
{
    ui->setupUi(this);
    name.setText("Sword");
}

void Sword::onUse(Entity *caster, Entity *target, int val){
    ActionCard::onUse(caster, target, val);
    target->deltaHealth(-val, caster);
}

bool Sword::canUse(int val){
    return val <= 6;
}

Sword::~Sword()
{
    delete ui;
}
