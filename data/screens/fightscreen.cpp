#include "fightscreen.h"
#include "ui_fightscreen.h"
#include "../components/gamemanager.h"
#include "../actioncards/actioncard.h"

FightScreen::FightScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::FightScreen)
{
    ui->setupUi(this);
    setBackGroundImage(":/assets/images/background.png");
    ui->enemy->setPixmap(ui->enemy->pixmap().transformed(QTransform().scale(-1, 1)));
    updateEntitiesTextures();
}

bool areWidgetsClose(QWidget* widget1, QWidget* widget2, int threshold)
{
    QRect rect1 = widget1->geometry();
    QRect rect2 = widget2->geometry();

    rect1.adjust(-threshold, -threshold, threshold, threshold);
    rect2.adjust(-threshold, -threshold, threshold, threshold);

    return rect1.intersects(rect2);
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
    }

    QTimer* timer = new QTimer(this);
    timer->setInterval(100);

    connect(timer, &QTimer::timeout, this, [=]() {
        for (ActionCard* card : this->findChildren<ActionCard*>()) {
            for (TextImage* dice : this->findChildren<TextImage*>()) {
                if (dice && dice->isDice() && card && card->canUse(dice->getDiceVal()) && areWidgetsClose(dice, card, -50)) {
                    Entity *test = GameManager::getChar();
                    card->onUse(test, dice->getDiceVal());
                    delete dice;
                    sizeInit();
                }
            }
        }
    });


    // Start the timer
    timer->start();
}
