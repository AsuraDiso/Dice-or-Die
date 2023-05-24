#ifndef FIGHTSCREEN_H
#define FIGHTSCREEN_H

#include <QWidget>

namespace Ui {
class FightScreen;
}

class FightScreen : public QWidget
{
    Q_OBJECT

public:
    explicit FightScreen(QWidget *parent = nullptr);
    ~FightScreen();

private:
    Ui::FightScreen *ui;
};

#endif // FIGHTSCREEN_H
