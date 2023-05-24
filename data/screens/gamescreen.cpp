#include "gamescreen.h"
#include "bossfightscreen.h"
#include "fightscreen.h"
#include "mapscreen.h"
#include "ui_gamescreen.h"
#include "../components/mapgenerator.h"
#include <iostream>
#include <QLabel>

using namespace std;

GameScreen::GameScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::GameScreen)
{
    setBackGroundImage(":/assets/images/background.png");
    ui->setupUi(this);

    MapScreen* mapscreen = new MapScreen(this);//, ui->stackedWidget
    FightScreen* fightscreen = new FightScreen(this);//, ui->stackedWidget
    BossFightScreen* bossfightscreen = new BossFightScreen(this);//, ui->stackedWidget
    ui->stackedWidget->addWidget(mapscreen);
    ui->stackedWidget->addWidget(fightscreen);
    ui->stackedWidget->addWidget(bossfightscreen);
    ui->stackedWidget->setCurrentWidget(mapscreen);
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
