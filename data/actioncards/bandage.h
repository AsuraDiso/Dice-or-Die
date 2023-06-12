#ifndef BANDAGE_H
#define BANDAGE_H

#include <QWidget>
#include <QLabel>
#include "actioncard.h"

class Entity;

class Bandage : public ActionCard
{
    Q_OBJECT

public:
    explicit Bandage(QWidget *parent = nullptr);
    void onUse(Entity *caster, Entity *target);
    bool canUse(int val);
    ~Bandage();

private:
};

#endif // BANDAGE_H
