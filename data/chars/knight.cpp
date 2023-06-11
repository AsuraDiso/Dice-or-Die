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
}
