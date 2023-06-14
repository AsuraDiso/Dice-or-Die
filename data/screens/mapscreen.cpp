#include "mapscreen.h"
#include "ui_mapscreen.h"
#include "../components/gamemanager.h"

MapScreen::MapScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::MapScreen)
{
    ui->setupUi(this);
    ui->nextlevel_xp->setStaticColor("yellow");
    ui->playericon->setScaledContents(true);
}

void MapScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);

}

void MapScreen::sizeInit() {
    Screen::sizeInit();
    setBackGroundImage(":/assets/images/map.png");

    ui->levelname->setText(GameManager::getLevelName()+": "+GameManager::getLevelDepth());
    ui->coins->setText(QString::number(GameManager::getCoins()));
    ui->health_val->setValue(GameManager::getChar()->getCurrHealth());
    ui->health_val->setMaximum(GameManager::getChar()->getMaxHealth());
    ui->nextlevel_xp->setValue(GameManager::getChar()->getExp());
    ui->nextlevel_xp->setMaximum(GameManager::getChar()->getNextLevel());

    ui->name->setText(GameManager::getChar()->getName());

    ui->playericon->setAnimatedTexture(GameManager::getChar()->getTexture());
    ui->playericon->setOffset(GameManager::getChar()->getOffset());
    ui->playericon->setScale(GameManager::getChar()->getSize().width()/2, GameManager::getChar()->getSize().height()/2);
    ui->playericon->resize(root.width(), root.height());
    for (Button* path : this->findChildren<Button*>()) {
        if (path->objectName() == "path"){
            delete path;
        }
    }

    int val = 0;
    if (GameManager::getLevelDepth().toInt() >= GameManager::getBossLevel()) {
        return;
    }

    int gridSize = 400;
    int mapWidth = GameManager::getMap().getSize().width();
    int mapHeight = GameManager::getMap().getSize().height();
    int buttonSize = std::min(gridSize / mapWidth, gridSize / mapHeight);

    for (int i = 0; i < mapWidth; i++) {
        for (int j = 0; j < mapHeight; j++) {
            val = GameManager::getMap().getValueInPoint(i, j);
            Button* path = new Button(this);
            path->setStyleSheet("background-color: rgba(0,0,0,0)");
            path->setObjectName("path");
            int posX = 200 + j * buttonSize;
            int posY = 25 + i * buttonSize;
            path->setGeometry(posX, posY, buttonSize, buttonSize);
            path->raise();
            path->show();

            if (val != 0) {
                QIcon icon;
                if (val == 2) {
                    icon.addFile("://assets/images/path/pathtaken.png");
                } else if (val == 3) {
                    icon.addFile("://assets/images/path/exit.png");
                } else if (val == 4) {
                    icon.addFile("://assets/images/path/enemy.png");
                } else if (val == 5) {
                    icon.addFile("://assets/images/path/chest.png");
                } else if (val == 6) {
                    icon.addFile("://assets/images/path/shop.png");
                } else if (val == 7) {
                    icon.addFile("://assets/images/path/pathtaken.png");
                } else {
                    icon.addFile("://assets/images/path/path.png");
                }

                path->setIcon(icon);
                path->setIconSize(QSize(buttonSize, buttonSize));
                path->resize(root.width(), root.height());

                connect(path, &Button::clicked, [=]() {
                    if ((val == 6 and (GameManager::getShopItems()[1] == "" or GameManager::getShopItems()[2] == "" or GameManager::getShopItems()[3] == "")) or val < 6){
                        GameManager::getMap().setValueInPoint(7, i, j);
                        path->setIcon(QIcon("://assets/images/path/pathtaken.png"));
                    }
                    GameManager::playerMoved(val, stackwidget);
                    if (val == 3) {
                        sizeInit();
                    }
                });
            }
        }
    }
}


void MapScreen::on_backpackbtn_clicked()
{
    stackwidget->setCurrentIndex(9);
}

MapScreen::~MapScreen()
{
    delete ui;
}
