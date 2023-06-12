#include "levelupscreen.h"
#include "ui_levelupscreen.h"

LevelUpScreen::LevelUpScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LevelUpScreen)
{
    ui->setupUi(this);
}

LevelUpScreen::~LevelUpScreen()
{
    delete ui;
}
