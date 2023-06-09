#ifndef SWORD_H
#define SWORD_H

#include <QWidget>
#include "actioncard.h"

class Entity;

namespace Ui {
class Sword;
}

class Sword : public ActionCard
{
    Q_OBJECT

public:
    explicit Sword(QWidget *parent = nullptr);
    void onUse(Entity *caster, Entity *target, int val);
    bool canUse(int val);
    ~Sword();

private:
    Ui::Sword *ui;
};

#endif // SWORD_H
