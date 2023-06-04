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
    static QString getLevelDepth();
    static QString getLevelName();
    static QString getCharName();
    static QString getCharTexture();
    static int getCoins();

private:
    static GameManager *instance;
    static MapGenerator map;
    static QString levelname;
    static QString leveldepth;
    static QString charname;
    static QString chartexture;
    static int coins;
    static int charhealthmax;
    static int charhealthcurr;
    //QString charinventory[6];
    //static EnemyData enemydata;
};

#endif // GAMEMANGER_H
