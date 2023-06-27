#ifndef CORRUPTIONBITE_H
#define CORRUPTIONBITE_H

#include <QWidget>
#include "actioncard.h"

class Entity;

class CorruptionBite : public ActionCard
{
    Q_OBJECT

public:
    explicit CorruptionBite(QWidget *parent = nullptr);
    void onUse(Entity *caster, Entity *target);
    bool canUse(int val);
    ~CorruptionBite();

private:
};
#endif // CORRUPTIONBITE_H
