#ifndef GAMEMANGER_H
#define GAMEMANGER_H

#include <QObject>
#include "mapgenerator.h"
#include "dynamiclist.h"
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
#include "../actioncards/magmaattack.h"
#include "../actioncards/poisonbite.h"
#include "../actioncards/corruptionbite.h"
#include "../actioncards/shieldattack.h"
#include "../actioncards/hardbite.h"
#include "../actioncards/bow.h"
#include "../actioncards/boomerang.h"
#include "../actioncards/poisonpotion.h"
#include "../actioncards/poisonpotiondouble.h"
#include "../actioncards/poisonpotionheal.h"

class GameManager
{
public:
    GameManager();
    ~GameManager();

    static void generateNewLevel();
    static void playerMoved(int val, QStackedWidget *stacked);
    static void generateNewEnemy();
    static void generateShopItems();
    static void setShopItem(int ind, QString name);
    static void setCharacter(QString charc);
    static void setEnemy(Enemy *en);
    static void startFight();
    static void doAttack();
    static void EntitiesUpdate();
    static void startNewGame();
    static ActionCard* getRandomCard(QWidget* parent, QString *name);
    static MapGenerator getMap();
    static ActionCard* getCard(QWidget* parent, const QString& name);
    static QString getLevelDepth();
    static QString getLevelName();
    static QString getCharName();
    static QString getCharTexture();
    static QString *getShopItems();
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
    static DynamicList *GetBackPack();

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
    static QString shopitems[3];
    static DynamicList *backpack;
};

#endif // GAMEMANGER_H
