#include "gamemanager.h"
#include <QDebug>

GameManager *GameManager::instance = nullptr;

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
GameManager::~GameManager()
{
    Q_ASSERT(instance != nullptr);
    instance = nullptr;
}
