#include "mapscreen.h"
#include "ui_mapscreen.h"
#include "../components/gamemanager.h"

MapScreen::MapScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::MapScreen)
{
    ui->setupUi(this);
}

void MapScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
    ui->coins->resize(root.width(), root.height());
    ui->levelname->resize(root.width(), root.height());
    ui->level_depth->resize(root.width(), root.height());
    ui->widget->resize(root.width(), root.height());
    ui->widget_2->resize(root.width(), root.height());
}

void MapScreen::sizeInit(){
    Screen::sizeInit();
    setBackGroundImage(":/assets/images/map.png");
    ui->levelname->setText(GameManager::getLevelName()+": "+GameManager::getLevelDepth());
    ui->coins->setText(QString::number(GameManager::getCoins()));
    int val = 0;
    for (int i = 0; i < GameManager::getMap().getSize().width(); i++){
        for (int j = 0; j <  GameManager::getMap().getSize().height(); j++){
            val =  GameManager::getMap().getValueInPoint(i, j);
            if (val != 0){
                QLabel* label = new QLabel(this);
                label->setText(QString::number(val));
                if (val == 2 or val == 3){
                    label->setStyleSheet("background-color: green");
                } else if (val == 4) {
                    label->setStyleSheet("background-color: red");
                } else if (val == 5) {
                    label->setStyleSheet("background-color: yellow");
                } else if (val == 6){
                    label->setStyleSheet("background-color: blue");
                } else {
                    label->setStyleSheet("background-color: black");
                }
                ui->map->addWidget(label, i, j);
            }
        }
    }
}
MapScreen::~MapScreen()
{
    delete ui;
}
