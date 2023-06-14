#include "musicmanager.h"
#include "gamemanager.h"
#include "../chars/knight.h"
#include "../chars/archer.h"
#include "../chars/witch.h"
#include "../enemies/spider.h"
#include "../screens/fightscreen.h"
#include "../screens/chestscreen.h"
#include "../screens/shopscreen.h"

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
QStackedWidget *GameManager::overlay = nullptr;
QString GameManager::shopitems[3] = { "", "", "" };

QStringList cards = { "bandage", "sword", "shield" };
QStringList enemies = { "spider" };

GameManager::GameManager()
{
    Q_ASSERT(instance == nullptr);
    instance = this;
}
void GameManager::generateNewLevel()
{
    QStringList levels = { "Forest", "Volcano", "Library" };
    levelname = levels[rand()%levels.size()];
    generateShopItems();
    map.generateRandomMaze(leveldepth.toInt()*2+2);
}

MapGenerator GameManager::getMap()
{
    return map;
}

ActionCard* GameManager::getCard(QWidget* parent, const QString& name){
    if (name == "bandage") { return new Bandage(parent);}
    else if (name == "shield") {return new Shield(parent);}
    return new Sword(parent);
}

ActionCard* GameManager::getRandomCard(QWidget* parent){
    return getCard(parent, cards[rand()%cards.size()]);
}

Enemy* createEnemy(QString name){
    return new Spider();
}

void GameManager::generateNewEnemy(){
    setEnemy(createEnemy(enemies[rand()%enemies.size()]));
}

void GameManager::generateShopItems(){
    for (int i = 0; i < 3; i++){
        shopitems[i] = cards[rand()%cards.size()];
    }
}

void GameManager::setShopItem(int ind, QString name){
    for (int i = 0; i < 3; i++){
        shopitems[ind] = name;
    }
}

QString* GameManager::getShopItems(){
    return shopitems;
}
void GameManager::startNewGame(){
    leveldepth = "1";
    coins = 0;
    GameManager::getMap().clearMap();
    generateNewLevel();
}

void GameManager::EntitiesUpdate(){
    if (enemy->getCurrHealth() <= 0){
        character->setLevel(character->getLevel(), character->getNextLevel(), character->getExp()+1);
        coins += 1;
    }
}

Character *GameManager::getChar(){
    return character;
}

Enemy *GameManager::getEnemy(){
    return enemy;
}

bool GameManager::isNoChar(){
    return (character == nullptr || dynamic_cast<Character*>(character) == nullptr);
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

void GameManager::setOverlay(QStackedWidget *over){
    overlay = over;
}

void GameManager::setOverlayScreen(QString page){
    overlay->parentWidget()->show();
    if (page == "death"){
        overlay->setCurrentIndex(0);
        MusicManager::play("/assets/music/omori_trees.mp3");
    } else if (page == "nextlvl"){
        overlay->setCurrentIndex(1);
    } else {
        overlay->parentWidget()->hide();
    }
}

void GameManager::playerMoved(int val, QStackedWidget *stacked){
    if (val == 3){
        leveldepth = QString::number(leveldepth.toInt() + 1);
        generateNewLevel();
    } else if (val == 4){
        generateNewEnemy();
        stacked->setCurrentIndex(6);
        FightScreen* fightscreen = qobject_cast<FightScreen*>(stacked->currentWidget());
        if (fightscreen){
            fightscreen->startFight();
        }
    } else if (val == 5){
        stacked->setCurrentIndex(8);
        ChestScreen* chestscreen = qobject_cast<ChestScreen*>(stacked->currentWidget());
        if (chestscreen){
            chestscreen->spawnCard();
        }
    } else if (val == 6){
        stacked->setCurrentIndex(9);
        ShopScreen* shopscreen = qobject_cast<ShopScreen*>(stacked->currentWidget());
        if (shopscreen){
            shopscreen->spawnShopItems();
        }
    }
}
void GameManager::setCharacter(QString charc){
    if (charc == "Knight"){
        character = new Knight();
    } else if (charc == "Archer"){
        character = new Archer();
    } else {
        character = new Witch();
    }
}

void GameManager::setEnemy(Enemy *en){
    delete enemy;
    enemy = en;
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
