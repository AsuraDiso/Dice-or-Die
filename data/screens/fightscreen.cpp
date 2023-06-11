#include "fightscreen.h"
#include "ui_fightscreen.h"
#include "../components/gamemanager.h"
#include "../actioncards/actioncard.h"
#include "../actioncards/bandage.h"
#include "../actioncards/sword.h"
#include "../actioncards/shield.h"
#include <QPropertyAnimation>

bool areWidgetsClose(QWidget* widget1, QWidget* widget2, int threshold)
{
    QRect rect1 = widget1->geometry();
    QRect rect2 = widget2->geometry();

    rect1.adjust(-threshold, -threshold, threshold, threshold);
    rect2.adjust(-threshold, -threshold, threshold, threshold);

    return rect1.intersects(rect2);
}

ActionCard* getCard(QWidget* parent, const QString& name)
{
    if (name == "bandage") {
        return new Bandage(parent);
    } else if (name == "sword") {
        return new Shield(parent);
    }
    return new Sword(parent);
}

FightScreen::FightScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::FightScreen)
{
    ui->setupUi(this);
    setBackGroundImage(":/assets/images/background.png");
    ui->enemy->setPixmap(ui->enemy->pixmap().transformed(QTransform().scale(-1, 1)));
    wasplayer = false;
    int timepassed= 0;
    connect(timer, &QTimer::timeout, this, [=, &timepassed]() {
        if (!wasplayer) {
            timepassed += 100;
            Dice* dices[3];
            int numDices = 0;

            for (Dice* dice : this->findChildren<Dice*>()) {
                dices[numDices] = dice;
                numDices++;
            }

            for (int i = 0; i < numDices - 1; i++) {
                for (int j = 0; j < numDices - i - 1; j++) {
                    if (dices[j]->getDiceVal() < dices[j + 1]->getDiceVal()) {
                        Dice* temp = dices[j];
                        dices[j] = dices[j + 1];
                        dices[j + 1] = temp;
                    }
                }
            }

            Entity* ai = GameManager::getEnemy();

            for (int i = 0; i < numDices; i++) {
                Dice* dice = dices[i];

                for (ActionCard* card : this->findChildren<ActionCard*>()) {
                    if (not card->inUse() and card->canUse(dice->getDiceVal()) && card->canUse(dice->getDiceVal())) {
                        card->setInUse(true);
                        QPointF startPos = dice->pos();
                        QPointF endPos = card->pos();

                        QPropertyAnimation* animation = new QPropertyAnimation(dice, "pos");
                        animation->setDuration(1500);
                        animation->setStartValue(startPos);
                        animation->setEndValue(endPos);
                        animation->setEasingCurve(QEasingCurve::InOutBack);

                        connect(animation, &QPropertyAnimation::finished, this, [=]() {
                            card->onUse(ai, GameManager::getChar(), dice->getDiceVal());
                            delete dice;
                            delete card;
                            updateEntitiesTextures();
                        });

                        animation->start();
                        break;
                    }
                }
            }
            if (timepassed == 2000){
                on_nextturn_clicked();
            }
        } else {
            timepassed = 0;
            ActionCard* cardsToDelete[this->findChildren<ActionCard*>().size()];
            Dice* diceToDelete[this->findChildren<Dice*>().size()];
            int cardCount = 0;
            int diceCount = 0;

            for (ActionCard* card : this->findChildren<ActionCard*>()) {
                for (Dice* dice : this->findChildren<Dice*>()) {
                    if (dice && dice->isDice() && !dice->isMoving() && card && card->canUse(dice->getDiceVal()) && areWidgetsClose(dice, card, -50)) {
                        Entity* caster = GameManager::getEnemy();
                        Entity* target = GameManager::getChar();

                        if (wasplayer) {
                            caster = GameManager::getChar();
                            target = GameManager::getEnemy();
                        }
                        if (caster->getCorruption() >= 1 && caster->getCorruption() <= 5) {
                            if (rand() % 10 < caster->getCorruption()) {
                                caster->setCorruption(-rand() % 3 + 1);
                            }
                        }
                        if (caster->getRage() > 0) {
                            card->onUse(caster, target, dice->getDiceVal());
                            caster->setRage(-1);
                        }
                        if (dice->isBurn()) {
                            caster->deltaHealth(-2, target);
                        }
                        card->onUse(caster, target, dice->getDiceVal());

                        cardsToDelete[cardCount] = card;
                        diceToDelete[diceCount] = dice;
                        cardCount++;
                        diceCount++;
                    }
                }
            }

            for (int i = 0; i < cardCount; i++) {
                delete cardsToDelete[i];
            }
            for (int i = 0; i < diceCount; i++) {
                delete diceToDelete[i];
            }

            updateEntitiesTextures();
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
    if (GameManager::getEnemy()->getCurrHealth() <= 0){
        stackwidget->setCurrentIndex(5);
    }
    for (ActionCard* card : this->findChildren<ActionCard*>()) {
        card->raise();
    }
    for (Dice* dice : this->findChildren<Dice*>()) {
        if (dice->isDice()){
            dice->raise();
        }
    }
}

FightScreen::~FightScreen()
{
    delete ui;
}

void FightScreen::updateEntitiesTextures()
{
    ui->enemy->setAnimatedTexture(GameManager::getEnemy()->getTexture());
    ui->enemy->setOffset(GameManager::getEnemy()->getOffset());
    ui->enemy->setScale(GameManager::getEnemy()->getSize().width(), GameManager::getEnemy()->getSize().height());

    ui->char_name->setText(GameManager::getChar()->getName());
    ui->char_hp->setValue(GameManager::getChar()->getCurrHealth());
    ui->char_hp->setMaximum(GameManager::getChar()->getMaxHealth());
    ui->enemy_name->setText(GameManager::getEnemy()->getName());
    ui->enemy_hp->setValue(GameManager::getEnemy()->getCurrHealth());
    ui->enemy_hp->setMaximum(GameManager::getEnemy()->getMaxHealth());
    ui->char_dices->setText(QString::number(GameManager::getChar()->getDiceAmount()) + "x");
    ui->enemy_dices->setText(QString::number(GameManager::getEnemy()->getDiceAmount()) + "x");
}

void FightScreen::startFight()
{
    updateEntitiesTextures();
    Entity *caster = GameManager::getChar();
    Entity *target = GameManager::getEnemy();
    int j = 0;
    int p = 380;
    QString str;
    for (ActionCard* card : this->findChildren<ActionCard*>()) {
        delete card;
    }

    for (Dice* dice : this->findChildren<Dice*>()) {
        if (dice->isDice()){
            delete dice;
        }
    }

    if (wasplayer){
        caster = GameManager::getEnemy();
        target = GameManager::getChar();
        p = 40;
    }

    for (int i = 0; i < caster->getActionCardsAmount(); i++) {
        ActionCard* card = getCard(this, caster->getActionCards()[i]);
        card->setGeometry(-30 + ((i + 1) % 6) * 180, 100 - j * 60, 170, 300);
        if ((i + 1) % 6 == 0)
            j++;
        card->show();
        card->raise();
        card->resize(width(), height());
    }

    for (int i = 0; i < caster->getDiceAmount(); i++) {
        Dice* dice = new Dice(this);
        dice->setMoveable(not wasplayer);
        dice->setDiceVal(GameManager::generateDice(false));
        dice->setScaledContents(true);
        dice->setGeometry(235 + ((i + 1) % 6) * 60, (p) - j * 60, 50, 50);
        dice->resize(root.width(), root.height());
        if ((i + 1) % 6 == 0)
            j++;
        dice->show();
        dice->raise();
        if (caster->getBlindness() > 0){
            dice->setPixmap(QPixmap("://assets/images/icon.png"));
            caster->setBlindness(-1);
        }
        qDebug() << caster->getBurn();
        if (caster->getBurn() > 0){
            dice->setBurn(true);
            caster->setBurn(-1);
        }
    }

    timer->setInterval(100);

    if (caster->getPoison() > 0){
        caster->setHealth(caster->getCurrHealth()-caster->getPoison(), caster->getMaxHealth());
        caster->setPoison(-1);
    }
    if (target->getPoison() > 0){
        target->setHealth(target->getCurrHealth()-target->getPoison(), target->getMaxHealth());
        target->setPoison(-1);
    }
    timer->start();
    sizeInit();
    wasplayer = not wasplayer;
}

void FightScreen::on_nextturn_clicked()
{

    if (GameManager::getChar()->getCurrHealth() <= 0){
        GameManager::setOverlayScreen("death");
    } else {
        startFight();
    }
}

void FightScreen::on_pushButton_clicked()
{
    stackwidget->setCurrentIndex(0);
}

