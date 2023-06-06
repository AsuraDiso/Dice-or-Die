#include "gamemanager.h"
#include "../chars/knight.h"
#include <QDebug>
#include <QTimer>
#include <QObject>

GameManager *GameManager::instance = nullptr;
int GameManager::coins = 0;
int GameManager::bosslevel = 5;
QString GameManager::levelname = "Forest";
QString GameManager::leveldepth = "1";
Character *GameManager::character = nullptr;
Enemy *GameManager::enemy = nullptr;

GameManager::GameManager()
{
    Q_ASSERT(instance == nullptr);
    instance = this;
    character = new Knight();
    enemy = new Enemy();
}

void GameManager::generateNewLevel()
{
    map.generateRandomMaze(leveldepth.toInt()*2+2);
}

MapGenerator GameManager::getMap()
{
    return map;
}

void GameManager::generateNewEnemy(){

}
Character GameManager::getChar(){
    return *character;
}

Enemy GameManager::getEnemy(){
    return *enemy;
}

QString GameManager::getLevelDepth(){
    return leveldepth;
}

QString GameManager::getLevelName(){
    return levelname;
}

int GameManager::getCoins(){
    return coins;
}

int GameManager::getBossLevel(){
    return bosslevel;
}

int GameManager::generateDice(bool isplayer){
    int val = rand()%6+1;
    return val;
}

void GameManager::playerMoved(int val, QStackedWidget *stacked){
    if (val == 3){
        leveldepth = QString::number(leveldepth.toInt() + 1);
        generateNewLevel();
    } else if (val == 4){
        stacked->setCurrentIndex(5);
    } else if (val == 5){
        stacked->setCurrentIndex(5);
    } else if (val == 6){
        qDebug() << "shop";
    }
}
void GameManager::setCharacter(QString charc){
    delete character;
    if (charc == "Knight"){
        character = new Knight();
    } else {
        character = new Knight();
    }
}

void GameManager::startFight(){
    int turn = 0; //0 - player, 1 - mob
    if (turn == 1){
        turn = 0;
    } else {
        turn = 1;
    }
}

void GameManager::doAttack(){
    //enemy->deltaHealth(delta);

    //here will be AI turn

    int dices[enemy->getDiceAmount()];
    /*for (int i = 0; i < enemy->getDiceAmount(); i++){
        dices[i] = generateDice();
    }

    for (int i = 0; i < enemy->cardsamount(); i++){
        enemy->doAttack(dices[1]);
    }
    */

}

GameManager::~GameManager()
{
    Q_ASSERT(instance != nullptr);
    instance = nullptr;
}
