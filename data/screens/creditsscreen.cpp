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
    qDebug() << "CREAS";
}

void CreditsScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
    ui->backbutton->resize(root.width(), root.height());
    ui->scrollArea->resize(root.width(), root.height());
}

CreditsScreen::~CreditsScreen()
{
    delete ui;
}

void CreditsScreen::on_backbutton_clicked()
{
    stackwidget->setCurrentIndex(0);
}

