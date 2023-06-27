#ifndef MAGMAATTACK_H
#define MAGMAATTACK_H

#include <QWidget>
#include "actioncard.h"

class Entity;

class MagmaAttack : public ActionCard
{
    Q_OBJECT

public:
    explicit MagmaAttack(QWidget *parent = nullptr);
    void onUse(Entity *caster, Entity *target);
    bool canUse(int val);
    ~MagmaAttack();

private:
};

#endif // MAGMAATTACK_H
