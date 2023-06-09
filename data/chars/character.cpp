#include "character.h"

Character::Character()
{
    setLevel(0,2,0);
}

void Character::setLevel(int lvl, int nextlvl, int e){
    level = lvl;
    nextlevel = nextlvl;
    exp = e;
    if (exp == nextlvl){
        exp = 0;
        nextlevel = 4;
        level++;
        int newhealth = getMaxHealth()*1.1;
        setHealth(newhealth, newhealth);
    }
}

void Character::deltaExp(int e){
    exp += e;
}

int Character::getLevel(){
    return level;
}
int Character::getNextLevel(){
    return nextlevel;
}
int Character::getExp(){
    return exp;
}
