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
    ui->nextturn->resize(root.width(), root.height());

    foreach (TextImage* button, this->findChildren<TextImage*>()) {
        button->resize(root.width(), root.height());
    }
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

    ui->enemy->setAnimatedTexture(GameManager::getEnemy().getTexture());
    ui->enemy->setPosition(ui->enemy->pos().x()+GameManager::getEnemy().getOffset().x(), ui->enemy->pos().y()+GameManager::getEnemy().getOffset().y());
    ui->enemy->setScale(GameManager::getEnemy().getSize().width(), GameManager::getEnemy().getSize().height());
}

FightScreen::~FightScreen()
{
    delete ui;
}

void FightScreen::on_nextturn_clicked()
{
    int j = 0;
    QString str;
    for (int i = 0; i < GameManager::getChar().getDiceAmount(); i++) {
        TextImage *button = new TextImage(this);
        button->setMoveable(true);
        str = QString::number(GameManager::generateDice(false));
        button->setText(str);
        button->setPixmap(QPixmap("://assets/images/dice"+str+".png"));//":/assets/dice"+str+".png"
        button->setScaledContents(true);
        button->setGeometry(235 + ((i+1) % 6) * 60, 400 - j * 60, 50, 50);
        button->resize(root.width(), root.height());
        if ((i+1) % 6 == 0)
            j++;
        button->show();
    }
}

