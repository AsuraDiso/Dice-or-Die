#ifndef POISONPOTIONDOUBLE_H
#define POISONPOTIONDOUBLE_H

#include <QWidget>
#include "actioncard.h"

class Entity;

class PoisonPotionDouble : public ActionCard
{
    Q_OBJECT

public:
    explicit PoisonPotionDouble(QWidget *parent = nullptr);
    void onUse(Entity *caster, Entity *target);
    bool canUse(int val);
    ~PoisonPotionDouble();

private:
};
#endif // POISONPOTIONDOUBLE_H
