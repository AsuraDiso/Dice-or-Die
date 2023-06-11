#include "shopscreen.h"
#include "ui_shopscreen.h"

ShopScreen::ShopScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::ShopScreen)
{
    ui->setupUi(this);

    setBackGroundImage(":/assets/images/background.png");
}

void ShopScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
}

void ShopScreen::sizeInit(){
    Screen::sizeInit();

}
ShopScreen::~ShopScreen()
{
    delete ui;
}
