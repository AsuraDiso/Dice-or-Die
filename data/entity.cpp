#include "entity.h"

Entity::Entity()
{
    diceamount = 3;
    maxhealth = 100;
    currhealth = 50;
    name = "Spider";
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
