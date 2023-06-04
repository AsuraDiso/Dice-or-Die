#include "gamemanager.h"
#include <QDebug>

GameManager *GameManager::instance = nullptr;
int GameManager::coins = 0;
int GameManager::charhealthmax = 100;
int GameManager::charhealthcurr = 100;
QString GameManager::levelname = "Forest";
QString GameManager::leveldepth = "1";
QString GameManager::charname = "Knight";
QString GameManager::chartexture = "knight";

GameManager::GameManager()
{
    Q_ASSERT(instance == nullptr);
    instance = this;
}

void GameManager::generateNewLevel()
{
    map.generateRandomMaze();
}

MapGenerator GameManager::getMap()
{
    return map;
}

void GameManager::generateNewEnemy(){

}

QString GameManager::getLevelDepth(){
    return leveldepth;
}

QString GameManager::getLevelName(){
    return levelname;
}

QString GameManager::getCharName(){
    return charname;
}

QString GameManager::getCharTexture(){
    return chartexture;
}

int GameManager::getCoins(){
    return coins;
}

GameManager::~GameManager()
{
    Q_ASSERT(instance != nullptr);
    instance = nullptr;
}
