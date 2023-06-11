#include "spider.h"
#include <QDebug>
Spider::Spider()
{
    setDiceAmount(2);
    setCardAmount(2);
    setCard("poisonbite", 0);
    setCard("poisonbite", 1);
    setHealth(20, 20);
    setName("Spider");
    setTexture("://assets/images/enemies/ds_spider.gif");
    setSize(QSize(200, 200));
    setOffset(QPoint(0, 100));
}
