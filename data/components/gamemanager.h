#ifndef GAMEMANGER_H
#define GAMEMANGER_H

#include <QObject>
#include "mapgenerator.h"
#include "../chars/character.h"
#include "../enemies/enemy.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QStackedWidget>

class GameManager
{
public:
    GameManager();
    ~GameManager();

    static void generateNewLevel();
    static void playerMoved(int val, QStackedWidget *stacked);
    static void generateNewEnemy();
    static void setCharacter(QString charc);
    static void startFight();
    static void doAttack();
    static MapGenerator getMap();
    static QString getLevelDepth();
    static QString getLevelName();
    static QString getCharName();
    static QString getCharTexture();
    static Character getChar();
    static Enemy getEnemy();
    static int getBossLevel();
    static int getCurrentHealth();
    static int getMaxHealth();
    static int getCoins();
    static int generateDice(bool isenemy);

private:
    static GameManager *instance;
    static MapGenerator map;
    static QString levelname;
    static QString leveldepth;
    static Character *character;
    static Enemy *enemy;
    static int coins;
    static int bosslevel;
    //QString charinventory[6];
    //static EnemyData enemydata;
};

#endif // GAMEMANGER_H
