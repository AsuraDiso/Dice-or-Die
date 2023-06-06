#ifndef ENTITY_H
#define ENTITY_H
#include <QString>

class Entity
{
    public:
        Entity();
        void setHealth(int cur, int maxi);
        void deltaHealth(int delta);
        void setDiceAmount(int amount);
        void setName(QString exp);

        QString getName();
        int getDiceAmount();
        int getMaxHealth();
        int getCurrHealth();

    private:
        int diceamount;
        int maxhealth;
        int currhealth;
        QString *cards;
        QString name;
};

#endif // ENTITY_H
