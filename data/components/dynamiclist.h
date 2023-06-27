#ifndef DYNAMICLIST
#define DYNAMICLIST

#include <QString>

struct Item {
    int index;
    QString cardname;
    Item* next;

    Item(QString val1, int val2);
};

class DynamicList {
private:
    Item* head;
    int amount;

public:
    DynamicList();

    Item* getHead();
    Item* getItem(int index);
    int getAmount();
    void insert(QString val1);
    void remove(int val1);
};

#endif  // DYNAMICLIST
