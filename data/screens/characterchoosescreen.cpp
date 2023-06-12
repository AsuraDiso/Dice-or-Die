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


void CharacterChooseScreen::startGame()
{
    stackwidget->setCurrentIndex(5);
}

void CharacterChooseScreen::on_charicon_clicked()
{
    GameManager::setCharacter("Knight");
    startGame();
}


void CharacterChooseScreen::on_charicon_2_clicked()
{
    GameManager::setCharacter("Archer");
    startGame();
}


void CharacterChooseScreen::on_charicon_3_clicked()
{
    GameManager::setCharacter("Witch");
    startGame();
}

CharacterChooseScreen::~CharacterChooseScreen()
{
    delete ui;
}
