#include "settingsscreen.h"
#include "ui_settingsscreen.h"

SettingsScreen::SettingsScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::SettingsScreen)
{
    setBackGroundImage(":/assets/images/background.png");
    ui->setupUi(this);
}

void SettingsScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
}

SettingsScreen::~SettingsScreen()
{
    delete ui;
}
