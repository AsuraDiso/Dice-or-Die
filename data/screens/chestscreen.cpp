#include "chestscreen.h"
#include "ui_chestscreen.h"
#include "../components/gamemanager.h"
#include <QPropertyAnimation>
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

void ChestScreen::spawnCard(){
    ui->take->hide();
    ui->throw_2->hide();
    card = GameManager::getRandomCard(this);
    card->setGeometry(315, 100, 170, 300);
    card->resize(width(), height());
    card->show();
    card->raise();
    ui->chest_front->raise();
    QPointF startPos = QPointF(card->pos().x(), card->pos().y()+card->size().height()*2);
    QPointF endPos = card->pos();
    QPointF endPos2 = QPointF(endPos.x(), endPos.y()-card->pos().y()+card->size().height()/5);

    QPropertyAnimation* animation = new QPropertyAnimation(card, "pos");
    animation->setDuration(1200);
    animation->setStartValue(startPos);
    animation->setEndValue(endPos2);
    animation->setEasingCurve(QEasingCurve::InOutBack);

    QTimer::singleShot(800, [=]() {
        card->raise();
    });
    connect(animation, &QPropertyAnimation::finished, this, [=]() {
        QPropertyAnimation* animation2 = new QPropertyAnimation(card, "pos");
        animation2->setDuration(1200);
        animation2->setStartValue(endPos2);
        animation2->setEndValue(endPos);
        animation2->setEasingCurve(QEasingCurve::OutCubic);
        animation2->start();
        ui->take->show();
        ui->throw_2->show();
    });

    animation->start();
}

void ChestScreen::on_take_clicked()
{
    ui->take->hide();
    ui->throw_2->hide();
    QPointF startPos = card->pos();
    QPointF endPos = QPointF(card->pos().x(), card->pos().y()+card->size().height()*2);

    QPropertyAnimation* animation = new QPropertyAnimation(card, "pos");
    animation->setDuration(1200);
    animation->setStartValue(startPos);
    animation->setEndValue(endPos);
    animation->setEasingCurve(QEasingCurve::InBack);

    connect(animation, &QPropertyAnimation::finished, this, [=]() {
        stackwidget->setCurrentIndex(5);
        delete card;
    });

    animation->start();
}

ChestScreen::~ChestScreen()
{
    delete ui;
}


void ChestScreen::on_throw_2_clicked()
{
    ui->take->hide();
    ui->throw_2->hide();
    QPointF startPos = card->pos();
    QPointF endPos = QPointF(card->pos().x(), card->pos().y()-card->size().height()*2);

    QPropertyAnimation* animation = new QPropertyAnimation(card, "pos");
    animation->setDuration(1200);
    animation->setStartValue(startPos);
    animation->setEndValue(endPos);
    animation->setEasingCurve(QEasingCurve::InBack);

    connect(animation, &QPropertyAnimation::finished, this, [=]() {
        stackwidget->setCurrentIndex(5);
        delete card;
    });

    animation->start();
}

