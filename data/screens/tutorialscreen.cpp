#include "tutorialscreen.h"
#include "ui_tutorialscreen.h"

TutorialScreen::TutorialScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::TutorialScreen)
{
    setBackGroundImage(":/assets/images/background.png");
    ui->setupUi(this);
}

void TutorialScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
}

TutorialScreen::~TutorialScreen()
{
    delete ui;
}
