#include "creditsscreen.h"
#include "ui_creditsscreen.h"
#include <QTimer>
#include <QScrollBar>
#include <QDebug>

CreditsScreen::CreditsScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::CreditsScreen)
{
    ui->setupUi(this);

    setBackGroundImage(":/assets/images/background.png");
    QScrollBar* verticalScrollBar = ui->scrollArea->verticalScrollBar();
    connect(timer, &QTimer::timeout, [=](){
        verticalScrollBar->setValue(verticalScrollBar->value()+1);
    });
}

void CreditsScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
}

void CreditsScreen::sizeInit(){
    Screen::sizeInit();
    timer->start(10);
    ui->scrollArea->verticalScrollBar()->setValue(0);

}
CreditsScreen::~CreditsScreen()
{
    delete ui;
}

void CreditsScreen::on_backbutton_clicked()
{
    stackwidget->setCurrentIndex(0);
    timer->stop();
}

