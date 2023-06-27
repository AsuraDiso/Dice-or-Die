#ifndef POISONPOTION_H
#define POISONPOTION_H

#include <QWidget>
#include "actioncard.h"

class Entity;

class PoisonPotion : public ActionCard
{
    Q_OBJECT

public:
    explicit PoisonPotion(QWidget *parent = nullptr);
    void onUse(Entity *caster, Entity *target);
    bool canUse(int val);
    ~PoisonPotion();

private:
};

#endif // POISONPOTION_H
