#include "fightscreen.h"
#include "ui_fightscreen.h"
#include "../components/gamemanager.h"


FightScreen::FightScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::FightScreen)
{
    ui->setupUi(this);
    setBackGroundImage(":/assets/images/background.png");
    ui->enemy->setPixmap(ui->enemy->pixmap().transformed(QTransform().scale(-1, 1)));
    ui->enemy->setMoveable(true);
}

void FightScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
    ui->char_hp->resize(root.width(), root.height());
    ui->char_2->resize(root.width(), root.height());
    ui->enemy->resize(root.width(), root.height());
    ui->enemy_hp->resize(root.width(), root.height());
    ui->char_name->resize(root.width(), root.height());
    ui->enemy_name->resize(root.width(), root.height());
    ui->char_dices->resize(root.width(), root.height());
    ui->enemy_dices->resize(root.width(), root.height());
    ui->dice_image->resize(root.width(), root.height());
    ui->dice_image_2->resize(root.width(), root.height());
}

void FightScreen::sizeInit(){
    Screen::sizeInit();
    ui->char_name->setText(GameManager::getChar().getName());
    ui->char_hp->setValue(GameManager::getChar().getCurrHealth());
    ui->char_hp->setMaximum(GameManager::getChar().getMaxHealth());
    ui->enemy_name->setText(GameManager::getEnemy().getName());
    ui->enemy_hp->setValue(GameManager::getEnemy().getCurrHealth());
    ui->enemy_hp->setMaximum(GameManager::getEnemy().getMaxHealth());
    ui->char_dices->setText(QString::number(GameManager::getChar().getDiceAmount())+"x");
    ui->enemy_dices->setText(QString::number(GameManager::getEnemy().getDiceAmount())+"x");
}

FightScreen::~FightScreen()
{
    delete ui;
}
