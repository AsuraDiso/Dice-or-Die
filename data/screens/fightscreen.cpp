#include "fightscreen.h"
#include "ui_fightscreen.h"
#include "../components/gamemanager.h"
#include "../actioncards/actioncard.h"

bool areWidgetsClose(QWidget* widget1, QWidget* widget2, int threshold)
{
    QRect rect1 = widget1->geometry();
    QRect rect2 = widget2->geometry();

    rect1.adjust(-threshold, -threshold, threshold, threshold);
    rect2.adjust(-threshold, -threshold, threshold, threshold);

    return rect1.intersects(rect2);
}

FightScreen::FightScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::FightScreen)
{
    ui->setupUi(this);
    setBackGroundImage(":/assets/images/background.png");
    ui->enemy->setPixmap(ui->enemy->pixmap().transformed(QTransform().scale(-1, 1)));
    updateEntitiesTextures();

    connect(timer, &QTimer::timeout, this, [=]() {
        for (ActionCard* card : this->findChildren<ActionCard*>()) {
            for (TextImage* dice : this->findChildren<TextImage*>()) {
                if (dice && dice->isDice() && card && card->canUse(dice->getDiceVal()) && areWidgetsClose(dice, card, -50)) {
                    Entity *caster = GameManager::getChar();
                    Entity *enemy = GameManager::getEnemy();
                    if (caster->getCorruption() >=1 and caster->getCorruption() <= 5){
                        if (rand()%10 < caster->getCorruption()){
                            caster->setCorruption(-rand()%3+1);
                        }
                    }

                    if (dice->isBurn()){
                        caster->deltaHealth(-2);
                    }
                    card->onUse(caster, enemy, dice->getDiceVal());
                    delete dice;
                    sizeInit();
                }
            }
        }
    });
}

void FightScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
}

void FightScreen::sizeInit()
{
    Screen::sizeInit();
    ui->char_name->setText(GameManager::getChar()->getName());
    ui->char_hp->setValue(GameManager::getChar()->getCurrHealth());
    ui->char_hp->setMaximum(GameManager::getChar()->getMaxHealth());
    ui->enemy_name->setText(GameManager::getEnemy()->getName());
    ui->enemy_hp->setValue(GameManager::getEnemy()->getCurrHealth());
    ui->enemy_hp->setMaximum(GameManager::getEnemy()->getMaxHealth());
    ui->char_dices->setText(QString::number(GameManager::getChar()->getDiceAmount()) + "x");
    ui->enemy_dices->setText(QString::number(GameManager::getEnemy()->getDiceAmount()) + "x");
    if (GameManager::getEnemy()->getCurrHealth() <= 0){
        stackwidget->setCurrentIndex(5);
    }
    for (ActionCard* card : this->findChildren<ActionCard*>()) {
        card->raise();
    }
    for (TextImage* dice : this->findChildren<TextImage*>()) {
        dice->raise();
    }
}

FightScreen::~FightScreen()
{
    delete ui;
}

void FightScreen::updateEntitiesTextures()
{
    ui->enemy->setAnimatedTexture(GameManager::getEnemy()->getTexture());
    ui->enemy->setPosition(ui->enemy->pos().x() + GameManager::getEnemy()->getOffset().x(), ui->enemy->pos().y() + GameManager::getEnemy()->getOffset().y());
    ui->enemy->setScale(GameManager::getEnemy()->getSize().width(), GameManager::getEnemy()->getSize().height());
}

void FightScreen::on_nextturn_clicked()
{
    int j = 0;
    QString str;

    for (int i = 0; i < GameManager::getChar()->getActionCardsAmount(); i++) {
        ActionCard* card = new ActionCard(this);
        card->setGeometry(-30 + ((i + 1) % 6) * 180, 100 - j * 60, 170, 300);
        card->resize(root.width(), root.height());
        if ((i + 1) % 6 == 0)
            j++;
        card->show();
        card->raise();
    }

    for (int i = 0; i < GameManager::getChar()->getDiceAmount(); i++) {      
        TextImage* dice = new TextImage(this);
        dice->setMoveable(true);
        dice->setDiceVal(GameManager::generateDice(false));
        dice->setScaledContents(true);
        dice->setGeometry(235 + ((i + 1) % 6) * 60, 380 - j * 60, 50, 50);
        dice->resize(root.width(), root.height());
        if ((i + 1) % 6 == 0)
            j++;
        dice->show();
        dice->raise();
        if (GameManager::getChar()->getBlindness() > 0){
            dice->setPixmap(QPixmap("://assets/images/icon.png"));
            GameManager::getChar()->setBlindness(-1);
        }
        if (GameManager::getChar()->getBurn() > 0){
            dice->setBurn(true);
            GameManager::getChar()->setBurn(-1);
        }
    }

    timer->setInterval(100);

    qDebug() << GameManager::getChar()->getPoison();
    if (GameManager::getChar()->getPoison() > 0){
        GameManager::getChar()->setHealth(GameManager::getChar()->getCurrHealth()-GameManager::getChar()->getPoison(), GameManager::getChar()->getMaxHealth());
        GameManager::getChar()->setPoison(-1);
    }
    if (GameManager::getEnemy()->getPoison() > 0){
        GameManager::getEnemy()->setHealth(GameManager::getEnemy()->getCurrHealth()-GameManager::getEnemy()->getPoison(), GameManager::getEnemy()->getMaxHealth());
        GameManager::getEnemy()->setPoison(-1);
    }
    sizeInit();
    // Start the timer
    timer->start();
}

void FightScreen::on_pushButton_clicked()
{
    stackwidget->setCurrentIndex(0);
}

