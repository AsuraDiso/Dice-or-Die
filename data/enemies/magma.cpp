#include "magma.h"

Magma::Magma()
{
    setDiceAmount(1);
    setCardAmount(2);
    setCard("magmaattack", 0);
    setCard("shield", 1);
    setHealth(20, 20);
    setName("Magma");
    setTexture("://assets/images/enemies/magma.gif");
    setSize(QSize(200, 200));
    setOffset(QPoint(0, 100));
}
