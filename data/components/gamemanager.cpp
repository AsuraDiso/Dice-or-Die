#include "gamemanager.h"
#include "../chars/knight.h"
#include "../chars/archer.h"
#include "../chars/witch.h"
#include "../enemies/spider.h"
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

GameManager::GameManager()
{
    Q_ASSERT(instance == nullptr);
    instance = this;
    enemy = new Spider();
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
    setEnemy(new Spider());
}

void GameManager::startNewGame(){
    leveldepth = "1";
    coins = 0;
    levelname = "Forest";
    GameManager::getMap().clearMap();
}

void GameManager::EntitiesUpdate(){
    if (character->getCurrHealth() <= 0) {
        startNewGame();
    } else if (enemy->getCurrHealth() <= 0){
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
        qDebug() << "DEATH";
        overlay->setCurrentIndex(0);
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
    } else if (val == 5){
        stacked->setCurrentIndex(6);
    } else if (val == 6){
        qDebug() << "shop";
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
