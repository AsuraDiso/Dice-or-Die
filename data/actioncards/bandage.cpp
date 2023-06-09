#include "bandage.h"
#include "ui_bandage.h"
#include "../entity.h"

Bandage::Bandage(QWidget *parent) :
    ActionCard(parent),
    ui(new Ui::Bandage)
{
    ui->setupUi(this);
}

void Bandage::onUse(Entity *caster, Entity *target, int val){
    caster->deltaHealth(val, target);
}

bool Bandage::canUse(int val){
    return val <= 3;
}

Bandage::~Bandage()
{
    delete ui;
}
