#include "witch.h"

Witch::Witch()
{
    setName("Witch");
    setDiceAmount(1);
    setHealth(16, 16);

    setCardAmount(3);
    setCard("poisonpotion", 0);
    setCard("poisonpotiondouble", 1);
    setCard("poisonpotionheal", 2);

    setTexture("://assets/images/chars/witch.gif");
    setSize(QSize(300, 300));
    setOffset(QPoint(0, 300 - getSize().height()));
}
