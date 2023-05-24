#include "bossfightscreen.h"
#include "ui_bossfightscreen.h"

BossFightScreen::BossFightScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BossFightScreen)
{
    ui->setupUi(this);
}

BossFightScreen::~BossFightScreen()
{
    delete ui;
}
