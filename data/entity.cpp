#include "entity.h"

Entity::Entity()
{
    diceamount = 2;
    maxhealth = 100;
    currhealth = 75;
    name = "Spider";
    texture = "://assets/images/enemies/ds_spider.gif";
    size = QSize(200, 200);
    offset = QPoint(0, 100);
}
void Entity::setHealth(int cur, int maxi){
    currhealth = cur;
    maxhealth = maxi;
}

void Entity::deltaHealth(int delta){
    currhealth += delta;
}

void Entity::setDiceAmount(int amount){
    diceamount = amount;
}
void Entity::setTexture(QString tex){
    texture = tex;
}
void Entity::setSize(QSize sz){
    size = sz;
}
void Entity::setOffset(QPoint point){
    offset = point;
}
void Entity::setName(QString n){
    name = n;
}
QString Entity::getName(){
    return name;
}
int Entity::getDiceAmount(){
    return diceamount;
}
int Entity::getMaxHealth(){
    return maxhealth;
}
int Entity::getCurrHealth(){
    return currhealth;
}

QString Entity::getTexture(){
    return texture;
}

QSize Entity::getSize(){
    return size;
}

QPoint Entity::getOffset(){
    return offset;
}
