#include "knight.h"

Knight::Knight()
{
    setName("Knight");
    setDiceAmount(3);
    setHealth(24, 24);

    setCardAmount(3);
    setCard("bandage", 0);
    setCard("sword", 1);
    setCard("shield", 2);

    setTexture("://assets/images/chars/knight.gif");
    setSize(QSize(300, 300));
    setOffset(QPoint(0, 300 - getSize().height()));
}
