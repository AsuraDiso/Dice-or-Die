#include "characterchoosescreen.h"
#include "ui_characterchoosescreen.h"
#include "../components/gamemanager.h"

CharacterChooseScreen::CharacterChooseScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::CharacterChooseScreen)
{
    ui->setupUi(this);
    setBackGroundImage(":/assets/images/background.png");
}

void CharacterChooseScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);

}

void CharacterChooseScreen::sizeInit(){
    Screen::sizeInit();

}

CharacterChooseScreen::~CharacterChooseScreen()
{
    delete ui;
}

