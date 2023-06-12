#include "mapscreen.h"
#include "ui_mapscreen.h"
#include "../components/gamemanager.h"

MapScreen::MapScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::MapScreen)
{
    ui->setupUi(this);
    ui->nextlevel_xp->setStaticColor("yellow");
}

void MapScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);

}

void MapScreen::sizeInit(){
    Screen::sizeInit();
    setBackGroundImage(":/assets/images/map.png");
    ui->levelname->setText(GameManager::getLevelName()+": "+GameManager::getLevelDepth());
    ui->coins->setText(QString::number(GameManager::getCoins()));
    ui->health_val->setValue(GameManager::getChar()->getCurrHealth());
    ui->health_val->setMaximum(GameManager::getChar()->getMaxHealth());
    ui->nextlevel_xp->setValue(GameManager::getChar()->getExp());
    ui->nextlevel_xp->setMaximum(GameManager::getChar()->getNextLevel());

    for (int i = ui->gridWidget->layout()->count() - 1; i >= 0; --i) {
        QWidget* widget = ui->gridWidget->layout()->itemAt(i)->widget();
        ui->gridWidget->layout()->removeWidget(widget);
        widget->deleteLater();
    }
    int val = 0;
    if (GameManager::getLevelDepth().toInt() >= GameManager::getBossLevel()){
        return;
    }
    for (int i = 0; i < GameManager::getMap().getSize().width(); i++){
        for (int j = 0; j <  GameManager::getMap().getSize().height(); j++){
            val =  GameManager::getMap().getValueInPoint(i, j);
            if (val != 0){
                QPushButton* label = new QPushButton(this);

                label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

                if (val == 2 || val == 3){
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
                connect(label, &QPushButton::clicked, [=](){
                    GameManager::playerMoved(val, stackwidget);
                    if (val == 3){
                        sizeInit();
                    }
                    label->setStyleSheet("background-color: purple");
                });
                ui->map->addWidget(label, i, j);
            }
        }
    }
}
MapScreen::~MapScreen()
{
    delete ui;
}
