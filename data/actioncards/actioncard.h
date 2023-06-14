#ifndef ACTIONCARD_H
#define ACTIONCARD_H

#include <QLabel>
#include "../widgets/textimage.h"
class Entity;

class ActionCard : public TextImage
{
    Q_OBJECT

public:
    explicit ActionCard(QWidget *parent = nullptr);
    virtual void onUse(Entity *caster, Entity *target);
    virtual bool canUse(int val);
    bool inUse();
    bool isAttack();
    void setCardVal(int dc);
    int getCardVal();
    int getPrice();
    void setPrice(int price);
    void setInUse(bool in);
    void setPosition(int x, int y);
    void setScale(int w, int h);
    void setIsAttack(bool isatk);
    void resize(double width, double height);
    virtual ~ActionCard();

protected:
    QPoint pt;
    QSize scale;
    bool inuse;
    bool isattack;
    int cardval;
    int price;
    TextImage name;
    TextImage diceimg;
    TextImage desc;
};

#endif // ACTIONCARD_H
