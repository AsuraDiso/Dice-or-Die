#include "slime.h"
#include <QDebug>
Slime::Slime()
{
    setDiceAmount(2);
    setCardAmount(3);
    setCard("poisonbite", 0);
    setCard("poisonbite", 1);
    setCard("shield", 2);
    setHealth(20, 20);
    setName("Slime");
    setTexture("://assets/images/enemies/slime.gif");
    setSize(QSize(200, 200));
    setOffset(QPoint(0, 100));
}
