#include "deathscreen.h"
#include "ui_deathscreen.h"

DeathScreen::DeathScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::DeathScreen)
{
    ui->setupUi(this);

    //setBackGroundImage(":/assets/images/background.png");
}

void DeathScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
}

void DeathScreen::sizeInit(){
    Screen::sizeInit();

}
DeathScreen::~DeathScreen()
{
    delete ui;
}
