
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
#include "tutorialscreen.h"
#include <QResizeEvent>
#include <QDebug>


Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    MainMenuScreen* mainscreen = new MainMenuScreen(this, ui->stackedWidget);
    CharacterChooseScreen* choosescreen = new CharacterChooseScreen(this, ui->stackedWidget);
    MapScreen* mapscreen = new MapScreen(this, ui->stackedWidget);
    FightScreen* fightscreen = new FightScreen(this);//, ui->stackedWidget
    BossFightScreen* bossfightscreen = new BossFightScreen(this);//, ui->stackedWidget
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
    ui->stackedWidget->setCurrentWidget(mainscreen); //mainscreen
}

void Window::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    if (Screen *widget = (Screen*)(ui->stackedWidget->currentWidget())) {
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

