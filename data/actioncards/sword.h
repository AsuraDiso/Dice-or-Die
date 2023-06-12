#ifndef SWORD_H
#define SWORD_H

#include <QWidget>
#include "actioncard.h"

class Entity;

class Sword : public ActionCard
{
    Q_OBJECT

public:
    explicit Sword(QWidget *parent = nullptr);
    void onUse(Entity *caster, Entity *target);
    bool canUse(int val);
    ~Sword();

private:
};

#endif // SWORD_H
