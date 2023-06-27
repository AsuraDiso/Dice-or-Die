#include "disclaimerscreen.h"
#include "ui_disclaimerscreen.h"
#include "../components/gamemanager.h"
DisclaimerScreen::DisclaimerScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::DisclaimerScreen)
{
    ui->setupUi(this);

    parent->setStyleSheet("background-color: rgba(0,0,0,0.5)!important");
}

void DisclaimerScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
}

void DisclaimerScreen::sizeInit(){
    Screen::sizeInit();

}

DisclaimerScreen::~DisclaimerScreen()
{
    delete ui;
}

void DisclaimerScreen::on_pushButton_clicked()
{
    GameManager::setOverlayScreen("hide");
}
