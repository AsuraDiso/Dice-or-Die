#ifndef BOOMERANG_H
#define BOOMERANG_H

#include <QWidget>
#include "actioncard.h"

class Entity;

class Boomerang : public ActionCard
{
    Q_OBJECT

public:
    explicit Boomerang(QWidget *parent = nullptr);
    void onUse(Entity *caster, Entity *target);
    bool canUse(int val);
    ~Boomerang();

private:
};

#endif // BOOMERANG_H
