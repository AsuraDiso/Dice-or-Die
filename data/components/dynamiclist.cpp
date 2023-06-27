#include "dynamiclist.h"
#include <iostream>
#include <QDebug>

Item::Item(QString val1, int ind) : index(ind), cardname(val1), next(nullptr) {}

DynamicList::DynamicList() : head(nullptr), amount(0){}
Item* DynamicList::getHead(){
    return head;
}
Item* DynamicList::getItem(int index){
    Item* curr = head;
    while (curr != nullptr && (curr->index != index)) {
        curr = curr->next;
    }
    return curr;
}
int DynamicList::getAmount(){
    return amount;
}

void DynamicList::insert(QString val1) {
    Item* newNode = new Item(val1, amount);
    amount++;

    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    qDebug() << getAmount();
}

void DynamicList::remove(int val1) {
    amount--;
    Item* curr = head;
    Item* prev = nullptr;

    while (curr != nullptr && (curr->index != val1)) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != nullptr) {
        if (prev == nullptr) {
            head = curr->next;
        } else {
            prev->next = curr->next;
        }

        delete curr;
    }
}
