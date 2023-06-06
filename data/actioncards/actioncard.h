#ifndef ACTIONCARD_H
#define ACTIONCARD_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class ActionCard;
}

class ActionCard : public QPushButton
{
    Q_OBJECT

public:
    explicit ActionCard(QWidget *parent = nullptr);
    void onUse();
    ~ActionCard();

private:
    Ui::ActionCard *ui;
    bool onlyone;
};

#endif // ACTIONCARD_H
