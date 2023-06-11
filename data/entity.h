#ifndef ENTITY_H
#define ENTITY_H
#include <QString>
#include <QSize>
#include <QPoint>

class Entity
{
    public:
        Entity();
        void setHealth(int cur, int maxi);
        void deltaHealth(int delta, Entity* entity);
        void setDiceAmount(int amount);
        void setName(QString exp);
        void setTexture(QString tex);
        void setSize(QSize sz);
        void setOffset(QPoint point);
        void setCard(QString card, int index);
        void setCardAmount(int amount);

        void setShield(int val);
        void setCorruption(int val);
        void setPoison(int val);
        void setBurn(int val);
        void setReflect(int val);
        void setBlindness(int val);
        void setRage(int val);

        int getShield();
        int getCorruption();
        int getPoison();
        int getBurn();
        int getReflect();
        int getBlindness();
        int getRage();

        QString getName();
        int getDiceAmount();
        int getMaxHealth();
        int getCurrHealth();
        QString getTexture();
        QSize getSize();
        QPoint getOffset();
        QString *getActionCards();
        int getActionCardsAmount();

    private:
        int diceamount;
        int maxhealth;
        int currhealth;
        int cardsamount;

        int shield;
        int corruption;
        int poison;
        int burn;
        int reflect;
        int blindness;
        int rage;

        QString *cards;
        QString name;
        QString texture;
        QSize size;
        QPoint offset;
};


#endif // ENTITY_H
