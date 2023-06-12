#ifndef SHIELD_H
#define SHIELD_H

#include <QWidget>
#include "actioncard.h"

class Entity;

class Shield : public ActionCard
{
    Q_OBJECT

public:
    explicit Shield(QWidget *parent = nullptr);
    void onUse(Entity *caster, Entity *target);
    bool canUse(int val);
    ~Shield();

private:
};

#endif // SHIELD_H
