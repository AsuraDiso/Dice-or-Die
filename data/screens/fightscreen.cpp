#include "fightscreen.h"
#include "ui_fightscreen.h"


FightScreen::FightScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::FightScreen)
{
    ui->setupUi(this);
    setBackGroundImage(":/assets/images/background.png");

}

void FightScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
    ui->char_hp->resize(root.width(), root.height());
    ui->char_2->resize(root.width(), root.height());
    ui->enemy->resize(root.width(), root.height());
    ui->enemy_hp->resize(root.width(), root.height());
//    ui->credits->resize(root.width(), root.height());
//    ui->exit->resize(root.width(), root.height());
}

FightScreen::~FightScreen()
{
    delete ui;
}
