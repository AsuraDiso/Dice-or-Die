#include "fightscreen.h"
#include "ui_fightscreen.h"
#include "../components/gamemanager.h"
#include "../actioncards/actioncard.h"
#include <QPropertyAnimation>

bool areWidgetsClose(QWidget* widget1, QWidget* widget2, int threshold)
{
    QRect rect1 = widget1->geometry();
    QRect rect2 = widget2->geometry();

    rect1.adjust(-threshold, -threshold, threshold, threshold);
    rect2.adjust(-threshold, -threshold, threshold, threshold);

    return rect1.intersects(rect2);
}

ActionCard* getCard(QWidget* parent, const QString& name){
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
                    if (not card->inUse() and card->canUse(dice->getDiceVal())) {
                        card->setInUse(true);
                        qDebug() << card->canUse(dice->getDiceVal());
                        QPointF startPos = dice->pos();
                        QPointF endPos = QPointF(card->pos().x() + card->size().width()/3, card->pos().y() + card->size().height()/5);

                        QPropertyAnimation* animation = new QPropertyAnimation(dice, "pos");
                        animation->setDuration(1500);
                        animation->setStartValue(startPos);
                        animation->setEndValue(endPos);
                        animation->setEasingCurve(QEasingCurve::InOutBack);

                        connect(animation, &QPropertyAnimation::finished, this, [=]() {
                            card->setCardVal(dice->getDiceVal());
                            if (dice->isBurn()) {
                                ai->deltaHealth(-2, GameManager::getChar());
                            }
                            delete dice;
                            updateEntitiesTextures();
                        });

                        animation->start();
                        break;
                    }
                }
            }
            if (timepassed == 1600){
                for (ActionCard* card : this->findChildren<ActionCard*>()) {
                    QPointF startPos = card->pos();
                    QPointF endPos = QPointF(card->pos().x(), card->pos().y()-card->size().height()*1.5);
                    if (card->getCardVal() > 0){
                        endPos = QPointF(card->pos().x(), card->pos().y()+card->size().height()*1.5);
                    }
                    QPropertyAnimation* animation = new QPropertyAnimation(card, "pos");
                    animation->setDuration(1200);
                    animation->setStartValue(startPos);
                    animation->setEndValue(endPos);
                    animation->setEasingCurve(QEasingCurve::InOutBack);

                    connect(animation, &QPropertyAnimation::finished, this, [=]() {
                        delete card;
                    });

                    animation->start();
                }
                for (Dice* card : this->findChildren<Dice*>()) {
                    QPointF startPos = card->pos();
                    QPointF endPos = QPointF(card->pos().x(), card->pos().y()-card->size().height()*1.5);

                    QPropertyAnimation* animation = new QPropertyAnimation(card, "pos");
                    animation->setDuration(1200);
                    animation->setStartValue(startPos);
                    animation->setEndValue(endPos);
                    animation->setEasingCurve(QEasingCurve::InBack);

                    connect(animation, &QPropertyAnimation::finished, this, [=]() {
                        delete card;
                    });

                    animation->start();
                }
            }
            if (timepassed == 2200){
                for (ActionCard* card : this->findChildren<ActionCard*>()) {
                    if (card->getCardVal() > 0){
                        card->onUse(ai, GameManager::getChar());
                        if (ai->getRage() > 0) {
                            card->onUse(ai, GameManager::getChar());
                            ai->setRage(-1);
                        }
                        updateEntitiesTextures();
                    }
                }
                if (GameManager::getChar()->getCurrHealth() <= 0){
                    stopFight();
                    GameManager::setOverlayScreen("death");
                    return;
                }
            }
            if (timepassed == 2900){
                timepassed = 0;
                on_nextturn_clicked();
            }
        } else {
            for (ActionCard* card : this->findChildren<ActionCard*>()) {
                for (Dice* dice : this->findChildren<Dice*>()) {
                    if (dice && dice->isDice() && !dice->isMoving() && card && not card->inUse() && card->canUse(dice->getDiceVal()) && areWidgetsClose(dice, card, -75)) {
                        card->setInUse(true);
                        Entity* caster = GameManager::getChar();
                        Entity* target = GameManager::getEnemy();

                        if (caster->getCorruption() >= 1 && caster->getCorruption() <= 5) {
                            if (rand() % 10 < caster->getCorruption()) {
                                caster->setCorruption(-rand() % 3 + 1);
                                delete card;
                            }
                        } else {
                            timepassed = 0;
                            card->setCardVal(dice->getDiceVal());
                            delete dice;
                            QPointF startPos = card->pos();
                            QPointF endPos = QPointF(card->pos().x(), card->pos().y()-card->size().height()*1.5);
                            QPropertyAnimation* animation = new QPropertyAnimation(card, "pos");
                            animation->setDuration(1200);
                            animation->setStartValue(startPos);
                            animation->setEndValue(endPos);
                            animation->setEasingCurve(QEasingCurve::InOutBack);
                            ui->nextturn->hide();
                            QTimer::singleShot(800, [=]() {
                                card->onUse(caster, target);
                                if (caster->getRage() > 0) {
                                    card->setCardVal(dice->getDiceVal());
                                    card->onUse(caster, target);
                                    caster->setRage(-1);
                                }
                                if (dice->isBurn()) {
                                    caster->deltaHealth(-2, target);
                                }
                                if (GameManager::getEnemy()->getCurrHealth() <= 0){
                                    stopFight();
                                    //GameManager::setOverlayScreen("nextlvl");
                                }
                            });
                            connect(animation, &QPropertyAnimation::finished, this, [=]() {
                                updateEntitiesTextures();
                                ui->nextturn->show();
                                delete card;
                            });

                            animation->start();
                        }
                    }
                }
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
    setBackGroundImage(":/assets/images/backgrounds/"+GameManager::getLevelName().toLower());
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
void FightScreen::stopFight()
{
    timer->stop();
    updateEntitiesTextures();
    for (ActionCard* card : this->findChildren<ActionCard*>()) {
        delete card;
    }

    for (Dice* dice : this->findChildren<Dice*>()) {
        if (dice->isDice()){
            delete dice;
        }
    }

    sizeInit();
    wasplayer = false;
}
void FightScreen::startFight()
{
    timer->stop();
    updateEntitiesTextures();
    Entity *caster = GameManager::getChar();
    Entity *target = GameManager::getEnemy();
    int j = 0;
    int p = 380;
    QString str;

    if (wasplayer){
        caster = GameManager::getEnemy();
        target = GameManager::getChar();
        p = 40;
        ui->nextturn->hide();
    } else {
        //ui->nextturn->show();
    }

    for (int i = 0; i < caster->getActionCardsAmount(); i++) {
        ActionCard* card = GameManager::getCard(this, caster->getActionCards()[i]);
        card->setGeometry(-30 + ((i + 1) % 6) * 180, 100 - j * 60, 170, 300);
        card->setInUse(false);
        if ((i + 1) % 6 == 0)
            j++;
        card->resize(width(), height());
        QPointF startPos = QPointF(card->pos().x(), card->pos().y()+card->size().height()*1.5);
        QPointF endPos = card->pos();
        if (wasplayer){
            startPos = QPointF(card->pos().x(), card->pos().y()-card->size().height()*1.5);
        }

        QPropertyAnimation* animation = new QPropertyAnimation(card, "pos");
        animation->setDuration(1200);
        animation->setStartValue(startPos);
        animation->setEndValue(endPos);
        animation->setEasingCurve(QEasingCurve::InOutBack);

        connect(animation, &QPropertyAnimation::finished, this, [=]() {
            updateEntitiesTextures();
            if (wasplayer){
                ui->nextturn->show();
            }
            timer->start();
        });
        animation->start();

        QTimer::singleShot(100, [=]() {
            card->show();
            card->raise();
        });
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
        dice->raise();
        QPointF startPos = QPointF(dice->pos().x(), dice->pos().y()+dice->size().height()*1.5);
        QPointF endPos = dice->pos();
        if (wasplayer){
            startPos = QPointF(dice->pos().x(), dice->pos().y()-dice->size().height()*1.5);
        }

        QPropertyAnimation* animation = new QPropertyAnimation(dice, "pos");
        animation->setDuration(1200);
        animation->setStartValue(startPos);
        animation->setEndValue(endPos);
        animation->setEasingCurve(QEasingCurve::InOutBack);
        connect(animation, &QPropertyAnimation::finished, this, [=]() {
            updateEntitiesTextures();
        });
        if (caster->getBlindness() > 0){
            dice->setPixmap(QPixmap("://assets/images/dices/diceunknown.png"));
            caster->setBlindness(-1);
        }
        if (caster->getBurn() > 0){
            dice->setBurn(true);
            caster->setBurn(-1);
        }
        animation->start();

        QTimer::singleShot(101, [=]() {
            dice->show();
            dice->raise();
        });
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
    sizeInit();
    wasplayer = not wasplayer;
}

void FightScreen::on_nextturn_clicked()
{
    if (GameManager::getChar()->getCurrHealth() <= 0){
        GameManager::setOverlayScreen("death");
    } else {
        if (wasplayer){
            timer->stop();
            ui->nextturn->hide();
            for (ActionCard* card : this->findChildren<ActionCard*>()) {
                QPointF startPos = card->pos();
                QPointF endPos = QPointF(card->pos().x(), card->pos().y()+card->size().height()*1.5);
                QPropertyAnimation* animation = new QPropertyAnimation(card, "pos");
                animation->setDuration(1200);
                animation->setStartValue(startPos);
                animation->setEndValue(endPos);
                animation->setEasingCurve(QEasingCurve::InOutBack);

                connect(animation, &QPropertyAnimation::finished, this, [=]() {
                    delete card;
                });

                animation->start();
            }
            for (Dice* card : this->findChildren<Dice*>()) {
                QPointF startPos = card->pos();
                QPointF endPos = QPointF(card->pos().x(), card->pos().y()+card->size().height()*1.5);

                QPropertyAnimation* animation = new QPropertyAnimation(card, "pos");
                animation->setDuration(1200);
                animation->setStartValue(startPos);
                animation->setEndValue(endPos);
                animation->setEasingCurve(QEasingCurve::InBack);

                connect(animation, &QPropertyAnimation::finished, this, [=]() {
                    delete card;
                });

                animation->start();
            }

            QTimer::singleShot(1300, [=]() {
                startFight();
            });
        } else {
            startFight();
        }
    }
}
