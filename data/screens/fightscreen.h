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
    void startFight();
    void stopFight();
    void updateEntitiesTextures();
    void playAnimation(QWidget *widget, bool isattack, int val, Entity *caster, Entity *target);
    ~FightScreen();

private slots:
    void on_nextturn_clicked();

private:
    Ui::FightScreen *ui;
    bool wasplayer;
};

#endif // FIGHTSCREEN_H
