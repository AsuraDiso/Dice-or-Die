#include "entity.h"
#include "components/gamemanager.h"

Entity::Entity()
{
    diceamount = 2;
    cardsamount = 3;
    maxhealth = 24;
    currhealth = 24;
    name = "Spider";

    shield = 0;
    corruption = 0;
    poison = 0;
    burn = 0;
    reflect = 2;
    blindness = 0;
    rage = 0;

    texture = "://assets/images/enemies/ds_spider.gif";
    size = QSize(200, 200);
    offset = QPoint(0, 100);
}
void Entity::setHealth(int cur, int maxi){
    currhealth = cur;
    maxhealth = maxi;
}

void Entity::deltaHealth(int delta, Entity* entity){
    int dlt = 0;
    if (delta < 0){
        dlt = shield + reflect + delta;
        if (reflect > 0){
            entity->setHealth(entity->getCurrHealth()-reflect, entity->getMaxHealth());
            reflect -= rand()%3+1;
            if (reflect < 0){reflect = 0;}
        }
        if (dlt < 0){
            currhealth += dlt;
        } else {
            shield = dlt;
        }
    } else {
        currhealth += delta;
    }
    GameManager::EntitiesUpdate();
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

void Entity::setShield(int val){
    shield += val;
}

void Entity::setCorruption(int val){
    corruption += val;
}

void Entity::setPoison(int val){
    poison += val;
}

void Entity::setBurn(int val){
    burn += val;
}

void Entity::setBlindness(int val){
    blindness += val;
}

void Entity::setRage(int val){
    rage += val;
}

void Entity::setReflect(int val){
    reflect += val;
}

int Entity::getPoison()
{
    return poison;
}

int Entity::getCorruption()
{
    return corruption;
}

int Entity::getShield()
{
    return shield;
}

int Entity::getBurn()
{
    return burn;
}
int Entity::getReflect()
{
    return reflect;
}
int Entity::getBlindness()
{
    return blindness;
}
int Entity::getRage()
{
    return rage;
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

ActionCard *Entity::getActionCards(){
    return cards;
}

int Entity::getActionCardsAmount(){
    return cardsamount;
}
