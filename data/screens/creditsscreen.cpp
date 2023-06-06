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
    timer->start(10);
    QScrollBar* verticalScrollBar = ui->scrollArea->verticalScrollBar();
    connect(timer, &QTimer::timeout, [=](){
        verticalScrollBar->setValue(verticalScrollBar->value()+1);
    });
}

void CreditsScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
    ui->backbutton->resize(root.width(), root.height());
    ui->scrollArea->resize(root.width(), root.height());
    ui->scrollAreaWidgetContents->resize(root.width(), root.height());
    for (int i = 1; i < 17; i++) {
        QString labelName = "label_" + QString::number(i);
        QLabel* label = findChild<QLabel*>(labelName);

        if (label) {
            label->resize(root.width(), root.height());
        }
    }
}

CreditsScreen::~CreditsScreen()
{
    delete ui;
}

void CreditsScreen::on_backbutton_clicked()
{
    stackwidget->setCurrentIndex(0);
}

