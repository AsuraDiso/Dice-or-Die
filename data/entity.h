#ifndef ENTITY_H
#define ENTITY_H
#include <QString>
#include <QSize>
#include <QPoint>
class ActionCard; // Forward declaration

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
        void setCards(ActionCard card, int index);

        QString getName();
        int getDiceAmount();
        int getMaxHealth();
        int getCurrHealth();
        QString getTexture();
        QSize getSize();
        QPoint getOffset();
        ActionCard *getActionCards();
        int getActionCardsAmount();
        ActionCard *getBackPack();

    private:
        int diceamount;
        int maxhealth;
        int currhealth;
        int cardsamount;
        ActionCard *cards;
        ActionCard *backpack;
        QString name;
        QString texture;
        QSize size;
        QPoint offset;
};

#endif // ENTITY_H
