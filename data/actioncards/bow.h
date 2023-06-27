#ifndef BOW_H
#define BOW_H

#include <QWidget>
#include "actioncard.h"

class Entity;

class Bow : public ActionCard
{
    Q_OBJECT

public:
    explicit Bow(QWidget *parent = nullptr);
    void onUse(Entity *caster, Entity *target);
    bool canUse(int val);
    ~Bow();

private:
};

#endif // BOW_H
