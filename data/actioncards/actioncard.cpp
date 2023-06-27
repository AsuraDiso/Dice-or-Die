#include "actioncard.h"
#include <QDebug>
#include "../entity.h"

ActionCard::ActionCard(QWidget *parent) :
    TextImage(parent)
{
    cardval = -1;
    setPixmap(QPixmap("://assets/images/map.png"));
    setScaledContents(true);

    diceimg.setParent(this);
    diceimg.show();
    diceimg.setPixmap(QPixmap("://assets/images/dices/dice1.png"));
    diceimg.setScaledContents(true);
    diceimg.setFixedSize(50, 50);

    name.setParent(this);
    name.show();
    name.setText("Empty");

    desc.setParent(this);
    desc.show();
    desc.setText("---======---");
    name.setGeometry(60 ,20,120,50);
    desc.setGeometry(60,160,120,50);
    diceimg.setGeometry(60,60,50,50);
}
void ActionCard::resize(double width, double height){
    if (pt.isNull()){
        setPosition(pos().x(), pos().y());
        scale = size();
    }

    int size = 450;
    QSize desiredSize(size, size);

    double deltaSize = qMin(width / desiredSize.width(), height / desiredSize.height());
    move(pt.x() * deltaSize, pt.y() * deltaSize);
    setFixedSize(scale.width() * deltaSize, scale.height() * deltaSize);
}

void ActionCard::onUse(Entity *caster, Entity *target){
    inuse = true;
}

bool ActionCard::canUse(int val){
    return true;
}

bool ActionCard::inUse(){
    return inuse;
}

bool ActionCard::isAttack(){
    return isattack;
}

void ActionCard::setCardVal(int dc){
    cardval = dc;
}

int ActionCard::getCardVal(){
    return cardval;
}
int ActionCard::getPrice(){
    return price;
}
void ActionCard::setPrice(int val){
    price = val;
}

void ActionCard::setInUse(bool in){
    inuse = in;
}
void ActionCard::setPosition(int x, int y){
    pt.setX(x); pt.setY(y);
}

void ActionCard::setScale(int w, int h){
    scale.setWidth(w); scale.setHeight(h);
}

ActionCard::~ActionCard()
{
}
