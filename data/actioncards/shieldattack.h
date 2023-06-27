#ifndef SHIELDATTACK_H
#define SHIELDATTACK_H

#include <QWidget>
#include "actioncard.h"

class Entity;

class ShieldAttack : public ActionCard
{
    Q_OBJECT

public:
    explicit ShieldAttack(QWidget *parent = nullptr);
    void onUse(Entity *caster, Entity *target);
    bool canUse(int val);
    ~ShieldAttack();

private:
};

#endif // SHIELDATTACK_H
