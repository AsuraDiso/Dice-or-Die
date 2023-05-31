#include "gamescreen.h"
#include "ui_gamescreen.h"
#include <iostream>
#include <QLabel>

using namespace std;

GameScreen::GameScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::GameScreen)
{
    ui->setupUi(this);
}

void GameScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
}

GameScreen::~GameScreen()
{
    delete ui;
}
