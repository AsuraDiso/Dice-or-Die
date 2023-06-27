#ifndef POISONPOTIONHEAL_H
#define POISONPOTIONHEAL_H

#include <QWidget>
#include "actioncard.h"

class Entity;

class PoisonPotionHeal : public ActionCard
{
    Q_OBJECT

public:
    explicit PoisonPotionHeal(QWidget *parent = nullptr);
    void onUse(Entity *caster, Entity *target);
    bool canUse(int val);
    ~PoisonPotionHeal();

private:
};
#endif // POISONPOTIONHEAL_H
