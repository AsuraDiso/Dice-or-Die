#include "bat.h"

Bat::Bat()
{
    setDiceAmount(3);
    setCardAmount(2);
    setCard("corruptionbite", 0);
    setCard("poisonbite", 1);
    setHealth(20, 20);
    setName("Bat");
    setTexture("://assets/images/enemies/bat.gif");
    setSize(QSize(200, 200));
    setOffset(QPoint(0, 100));
}
