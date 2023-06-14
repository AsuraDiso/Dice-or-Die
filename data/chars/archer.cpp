#include "archer.h"

Archer::Archer()
{
    setName("Archer");
    setDiceAmount(2);
    setHealth(20, 20);

    setTexture("://assets/images/chars/archer.gif");
    setSize(QSize(300, 300));
    setOffset(QPoint(0, 300 - getSize().height()));
}
