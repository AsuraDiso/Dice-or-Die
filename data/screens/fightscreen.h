#ifndef FIGHTSCREEN_H
#define FIGHTSCREEN_H

#include <QWidget>
#include "screen.h"

namespace Ui {
class FightScreen;
}

class FightScreen : public Screen
{
    Q_OBJECT

public:
    explicit FightScreen(QWidget *parent = nullptr, QStackedWidget *stacked = nullptr);
    void resizeScreen(QResizeEvent *event) override;
    void sizeInit();
    ~FightScreen();

private slots:
    void on_nextturn_clicked();

private:
    Ui::FightScreen *ui;
};

#endif // FIGHTSCREEN_H
