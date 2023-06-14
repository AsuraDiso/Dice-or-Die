#include "witch.h"

Witch::Witch()
{
    setName("Witch");
    setDiceAmount(2);
    setHealth(16, 16);

    setTexture("://assets/images/chars/witch.gif");
    setSize(QSize(300, 300));
    setOffset(QPoint(0, 300 - getSize().height()));
}
