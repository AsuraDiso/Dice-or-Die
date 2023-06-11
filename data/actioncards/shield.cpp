#include "shield.h"
#include "ui_shield.h"
#include "../entity.h"

Shield::Shield(QWidget *parent) :
    ActionCard(parent),
    ui(new Ui::Shield)
{
    ui->setupUi(this);
    name.setText("Shield");
}

void Shield::onUse(Entity *caster, Entity *target, int val){
    ActionCard::onUse(caster, target, val);
    caster->setShield(val);
}

bool Shield::canUse(int val){
    return val <= 6;
}

Shield::~Shield()
{
    delete ui;
}
