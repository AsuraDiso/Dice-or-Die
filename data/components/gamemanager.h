#ifndef GAMEMANGER_H
#define GAMEMANGER_H

#include <QObject>
#include "mapgenerator.h"
#include "../chars/character.h"
#include "../enemies/enemy.h"
#include "../actioncards/actioncard.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QStackedWidget>
#include <QVBoxLayout>

#include "../actioncards/bandage.h"
#include "../actioncards/sword.h"
#include "../actioncards/shield.h"

class GameManager
{
public:
    GameManager();
    ~GameManager();

    static void generateNewLevel();
    static void playerMoved(int val, QStackedWidget *stacked);
    static void generateNewEnemy();
    static void setCharacter(QString charc);
    static void setEnemy(Enemy *en);
    static void startFight();
    static void doAttack();
    static void EntitiesUpdate();
    static void startNewGame();
    static MapGenerator getMap();
    static ActionCard* getCard(QWidget* parent, const QString& name);
    static QString getLevelDepth();
    static QString getLevelName();
    static QString getCharName();
    static QString getCharTexture();
    static Character *getChar();
    static Enemy *getEnemy();
    static bool isNoChar();
    static int getBossLevel();
    static int getCurrentHealth();
    static int getMaxHealth();
    static int getCoins();
    static int generateDice(bool isenemy);
    static void setOverlay(QStackedWidget *overlay);
    static void setOverlayScreen(QString page);

private:
    static GameManager *instance;
    static MapGenerator map;
    static QString levelname;
    static QString leveldepth;
    static Character *character;
    static Enemy *enemy;
    static int coins;
    static int bosslevel;
    static QStackedWidget *overlay;
    //QString charinventory[6];
    //static EnemyData enemydata;
};

#endif // GAMEMANGER_H
