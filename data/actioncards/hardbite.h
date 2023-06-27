#ifndef HARDBITE_H
#define HARDBITE_H

#include <QWidget>
#include "actioncard.h"

class Entity;

class HardBite : public ActionCard
{
    Q_OBJECT

public:
    explicit HardBite(QWidget *parent = nullptr);
    void onUse(Entity *caster, Entity *target);
    bool canUse(int val);
    ~HardBite();

private:
};

#endif // HARDBITE_H
