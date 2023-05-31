#ifndef GAMEMANGER_H
#define GAMEMANGER_H

#include <QObject>
#include "mapgenerator.h"
#include <QMediaPlayer>
#include <QAudioOutput>

class GameManager
{
public:
    GameManager();
    ~GameManager();

    static void generateNewLevel();
    static void generateNewEnemy();
    static MapGenerator getMap();

private:
    static GameManager *instance;
    static MapGenerator map;
};

#endif // GAMEMANGER_H
