#ifndef POISONBITE_H
#define POISONBITE_H

#include <QWidget>
#include "actioncard.h"

class Entity;

class PoisonBite : public ActionCard
{
    Q_OBJECT

public:
    explicit PoisonBite(QWidget *parent = nullptr);
    void onUse(Entity *caster, Entity *target);
    bool canUse(int val);
    ~PoisonBite();

private:
};

#endif // POISONBITE_H
