#ifndef BANDAGE_H
#define BANDAGE_H

#include <QWidget>
#include "actioncard.h"

class Entity;

namespace Ui {
class Bandage;
}

class Bandage : public ActionCard
{
    Q_OBJECT

public:
    explicit Bandage(QWidget *parent = nullptr);
    void onUse(Entity *caster, Entity *target, int val);
    bool canUse(int val);
    ~Bandage();

private:
    Ui::Bandage *ui;
};

#endif // BANDAGE_H
