#include "fightscreen.h"
#include "ui_fightscreen.h"

FightScreen::FightScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FightScreen)
{
    ui->setupUi(this);
}

FightScreen::~FightScreen()
{
    delete ui;
}
