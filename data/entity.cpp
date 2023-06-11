#include "entity.h"
#include "components/gamemanager.h"

Entity::Entity()
{
    diceamount = 2;
    cardsamount = 0;
    maxhealth = 24;
    currhealth = 24;
    name = "Spider";
    cards = new QString[1];

    shield = 0;
    corruption = 0;
    poison = 0;
    burn = 0;
    reflect = 0;
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

void Entity::deltaHealth(int delta, Entity* entity) {
    if (delta < 0) {
        if (delta > -shield) {
            shield += delta;
        } else {
            currhealth += delta + shield;
            shield = 0;
        }
    } else {
        currhealth += delta;
    }
    GameManager::EntitiesUpdate();
}
void Entity::setCardAmount(int val){
    cardsamount = val;
    delete []cards;
    cards = new QString[val];
}

void Entity::setCard(QString card, int index){
    if (index > cardsamount-1){
        return;
    }
    cards[index]=card;
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

QString *Entity::getActionCards(){
    return cards;
}

int Entity::getActionCardsAmount(){
    return cardsamount;
}
