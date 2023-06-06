#include "character.h"

Character::Character()
{

}

void Character::setLevel(int lvl, int nextlvl, int e){
    level = lvl;
    nextlevel = nextlvl;
    exp = e;
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
