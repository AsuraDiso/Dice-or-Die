
#include "window.h"
#include "screen.h"
#include "ui_window.h"
#include "mainmenuscreen.h"
#include "bossfightscreen.h"
#include "characterchoosescreen.h"
#include "fightscreen.h"
#include "mapscreen.h"
#include "creditsscreen.h"
#include "settingsscreen.h"
#include "backpackscreen.h"
#include "chestscreen.h"
#include "shopscreen.h"
#include "levelupscreen.h"
#include "disclaimerscreen.h"
#include "deathscreen.h"
#include "tutorialscreen.h"
#include <QResizeEvent>
#include <QDebug>
#include "../components/gamemanager.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    MainMenuScreen* mainscreen = new MainMenuScreen(this, ui->stackedWidget);
    CharacterChooseScreen* choosescreen = new CharacterChooseScreen(this, ui->stackedWidget);
    MapScreen* mapscreen = new MapScreen(this, ui->stackedWidget);
    FightScreen* fightscreen = new FightScreen(this, ui->stackedWidget);
    BossFightScreen* bossfightscreen = new BossFightScreen(this);//, ui->stackedWidget
    ChestScreen* chestscreen = new ChestScreen(this, ui->stackedWidget);
    ShopScreen* shopscreen = new ShopScreen(this, ui->stackedWidget);
    BackPackScreen* backpackscreen = new BackPackScreen(this, ui->stackedWidget);
    TutorialScreen* tutorialscreen = new TutorialScreen(this, ui->stackedWidget);
    SettingsScreen* settingsscreen = new SettingsScreen(this, ui->stackedWidget);
    CreditsScreen* creditsscreen = new CreditsScreen(this, ui->stackedWidget);
    ui->stackedWidget->addWidget(mainscreen);
    ui->stackedWidget->addWidget(tutorialscreen);
    ui->stackedWidget->addWidget(settingsscreen);
    ui->stackedWidget->addWidget(creditsscreen);
    ui->stackedWidget->addWidget(choosescreen);
    ui->stackedWidget->addWidget(mapscreen);
    ui->stackedWidget->addWidget(fightscreen);
    ui->stackedWidget->addWidget(bossfightscreen);
    ui->stackedWidget->addWidget(chestscreen);
    ui->stackedWidget->addWidget(shopscreen);
    ui->stackedWidget->addWidget(backpackscreen);
    ui->stackedWidget->setCurrentWidget(mainscreen);
    DeathScreen* deathscreen = new DeathScreen(this, ui->stackedWidget);
    //LevelUpScreen* levelupscreen = new LevelUpScreen(this, ui->stackedWidget);
    DisclaimerScreen* disclaimerscreen = new DisclaimerScreen(this, ui->stackedWidget);
    ui->overlays->addWidget(deathscreen);
    ui->overlays->addWidget(disclaimerscreen);
    //ui->overlays->addWidget(levelupscreen);
    ui->overlays->setCurrentWidget(disclaimerscreen);
    //ui->overlays->parentWidget()->hide();
    GameManager::setOverlay(ui->overlays);
}

void Window::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    if (Screen *widget = (Screen*)(ui->stackedWidget->currentWidget())) {
        widget->resizeScreen(event);
    }
    if (Screen *widget = (Screen*)(ui->overlays->currentWidget())) {
        widget->resizeScreen(event);
    }
}
Window::~Window()
{
    delete ui;
}

void Window::on_stackedWidget_currentChanged(int index)
{
    Screen* currentWidget = qobject_cast<Screen*>(ui->stackedWidget->widget(index));
    if (currentWidget) currentWidget->sizeInit();
}

