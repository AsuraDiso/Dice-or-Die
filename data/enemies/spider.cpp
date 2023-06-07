#include "spider.h"

Spider::Spider()
{
    setDiceAmount(2);
    setHealth(100, 100);
    setName("Spider");
    setTexture("://assets/images/enemies/ds_spider.gif");
    setSize(QSize(200, 200));
    setOffset(QPoint(0, 100));
}