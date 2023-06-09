#ifndef SHIELD_H
#define SHIELD_H

#include <QWidget>
#include "actioncard.h"

class Entity;

namespace Ui {
class Shield;
}

class Shield : public ActionCard
{
    Q_OBJECT

public:
    explicit Shield(QWidget *parent = nullptr);
    void onUse(Entity *caster, Entity *target, int val);
    bool canUse(int val);
    ~Shield();

private:
    Ui::Shield *ui;
};

#endif // SHIELD_H
