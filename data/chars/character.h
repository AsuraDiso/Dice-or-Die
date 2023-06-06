#ifndef CHARACTER_H
#define CHARACTER_H
#include <QString>
#include "../entity.h"

class Character : public Entity
{
    public:
        Character();
        void setLevel(int level, int nextlevel, int exp);
        void deltaExp(int exp);
        int getLevel();
        int getNextLevel();
        int getExp();


    private:
        int level;
        int nextlevel;
        int exp;

};

#endif // CHARACTER_H
