#include "deathscreen.h"
#include "ui_deathscreen.h"
#include "../components/gamemanager.h"
DeathScreen::DeathScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::DeathScreen)
{
    ui->setupUi(this);

    parent->setStyleSheet("background-color: rgba(0,0,0,0.5)!important");
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

void DeathScreen::on_retrybtn_clicked()
{
    stackwidget->setCurrentIndex(4);
    GameManager::setOverlayScreen("hide");
    GameManager::startNewGame();
}


void DeathScreen::on_mainmenubtn_clicked()
{
    stackwidget->setCurrentIndex(0);
    GameManager::setOverlayScreen("hide");
}

