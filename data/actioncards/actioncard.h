#ifndef ACTIONCARD_H
#define ACTIONCARD_H

#include <QLabel>
#include "../widgets/textimage.h"
class Entity;

namespace Ui {
class ActionCard;
}

class ActionCard : public TextImage
{
    Q_OBJECT

public:
    explicit ActionCard(QWidget *parent = nullptr);
    virtual void onUse(Entity *caster, Entity *target, int val);
    virtual bool canUse(int val);
    bool inUse();
    void setInUse(bool in);
    void setPosition(int x, int y);
    void setScale(int w, int h);
    void resize(double width, double height);
    ~ActionCard();

protected:
    Ui::ActionCard *ui;
    QPoint pt;
    QSize scale;
    bool inuse;
    TextImage name;
    TextImage diceimg;
    TextImage desc;
};

#endif // ACTIONCARD_H
