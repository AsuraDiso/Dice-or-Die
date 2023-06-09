#include "actioncard.h"
#include "ui_actioncard.h"
#include <QDebug>
#include "../entity.h"

ActionCard::ActionCard(QWidget *parent) :
    Button(parent),
    ui(new Ui::ActionCard)
{
    ui->setupUi(this);
}

void ActionCard::onUse(Entity *caster, Entity *target, int val){
    target->deltaHealth(-val*2);
    caster->deltaHealth(-val);
}

bool ActionCard::canUse(int val){
    return true;
}

void ActionCard::setPosition(int x, int y){
    pt.setX(x); pt.setY(y);
}

void ActionCard::setScale(int w, int h){
    scale.setWidth(w); scale.setHeight(h);
}

ActionCard::~ActionCard()
{
    delete ui;
}
