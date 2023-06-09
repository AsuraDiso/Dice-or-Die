#ifndef ACTIONCARD_H
#define ACTIONCARD_H

#include "../widgets/button.h"
class Entity;

namespace Ui {
class ActionCard;
}

class ActionCard : public Button
{
    Q_OBJECT

public:
    explicit ActionCard(QWidget *parent = nullptr);
    void onUse(Entity *caster, Entity *target, int val);
    bool canUse(int val);
    void setPosition(int x, int y);
    void setScale(int w, int h);
    ~ActionCard();

protected:
    Ui::ActionCard *ui;
    QPoint pt;
    QSize scale;
    int fontSize;
};

#endif // ACTIONCARD_H
