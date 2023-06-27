#include "fox.h"

Fox::Fox()
{
    setDiceAmount(2);
    setCardAmount(2);
    setCard("hardbite", 0);
    setCard("hardbite", 1);
    setHealth(20, 20);
    setName("Fox");
    setTexture("://assets/images/enemies/fox.gif");
    setSize(QSize(200, 200));
    setOffset(QPoint(0, 100));
}
