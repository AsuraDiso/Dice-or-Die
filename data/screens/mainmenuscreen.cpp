#include "mainmenuscreen.h"
#include "screen.h"
#include "ui_mainmenuscreen.h"
#include <QDebug>
#include <QResizeEvent>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QPushButton>

MainMenuScreen::MainMenuScreen(QWidget *parent) :
    Screen(parent),
    ui(new Ui::MainMenuScreen)
{
    ui->setupUi(this);
    setAspectRatio(QSizeF(16, 9));

    root.setParent(this);
    root.setScaledContents(true);
    root.setPixmap(QPixmap(":/assets/images/background.png"));

    ui->label->setParent(&root);
    ui->label->setAlignment(Qt::AlignCenter);

    ui->label_2->setParent(&root);
    ui->label_2->setAlignment(Qt::AlignCenter);

    ui->progressBar->setParent(&root);
    ui->progressBar->setAlignment(Qt::AlignCenter);

    ui->progressBar_2->setParent(&root);
    ui->progressBar_2->setAlignment(Qt::AlignCenter);
}

void MainMenuScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    int width = event->size().width();
    int height = event->size().height();

    int max_width = (int)(height * m_aspectRatio.width() / m_aspectRatio.height());
    int max_height = (int)(width * m_aspectRatio.height() / m_aspectRatio.width());

    int label_width = qMin(width, max_width);
    int label_height = qMin(height, max_height);
    int x = (width - label_width) / 2;
    int y = (height - label_height) / 2;
    root.setFixedSize(label_width, label_height);
    parentWidget()->parentWidget()->setGeometry(x, y, label_width, label_height);

    QSize desiredSize(ui->label->pixmap().width()*2, ui->label->pixmap().height()*2);

    double deltaSize = qMin((double)root.width() / desiredSize.width(), (double)root.height() / desiredSize.height());
    ui->label->setFixedSize(deltaSize * ui->label->pixmap().size());
    ui->label->move((ui->label->x()+1000)*deltaSize, (ui->label->y())*deltaSize);
}

MainMenuScreen::~MainMenuScreen()
{
    delete ui;
}
