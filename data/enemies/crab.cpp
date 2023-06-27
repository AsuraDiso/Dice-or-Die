#include "crab.h"

Crab::Crab()
{
    setDiceAmount(2);
    setCardAmount(2);
    setCard("hardbite", 0);
    setCard("corruptionbite", 1);
    setHealth(20, 20);
    setName("Crab");
    setTexture("://assets/images/enemies/crab.gif");
    setSize(QSize(150, 150));
    setOffset(QPoint(0, 150));
}
