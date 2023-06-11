#include "chestscreen.h"
#include "ui_chestscreen.h"

ChestScreen::ChestScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::ChestScreen)
{
    ui->setupUi(this);

    setBackGroundImage(":/assets/images/background.png");
}

void ChestScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
}

void ChestScreen::sizeInit(){
    Screen::sizeInit();

}
ChestScreen::~ChestScreen()
{
    delete ui;
}
