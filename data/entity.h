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
        void deltaHealth(int delta);
        void setDiceAmount(int amount);
        void setName(QString exp);
        void setTexture(QString tex);
        void setSize(QSize sz);
        void setOffset(QPoint point);

        QString getName();
        int getDiceAmount();
        int getMaxHealth();
        int getCurrHealth();
        QString getTexture();
        QSize getSize();
        QPoint getOffset();

    private:
        int diceamount;
        int maxhealth;
        int currhealth;
        QString *cards;
        QString name;
        QString texture;
        QSize size;
        QPoint offset;
};

#endif // ENTITY_H
