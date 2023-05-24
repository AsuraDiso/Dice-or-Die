
#include "window.h"
#include "screen.h"
#include "ui_window.h"
#include "mainmenuscreen.h"
#include "creditsscreen.h"
#include "settingsscreen.h"
#include "gamescreen.h"
#include "tutorialscreen.h"
#include <QResizeEvent>
#include <QDebug>


Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    MainMenuScreen* mainscreen = new MainMenuScreen(this, ui->stackedWidget);
    GameScreen* gamescreen = new GameScreen(this, ui->stackedWidget);
    TutorialScreen* tutorialscreen = new TutorialScreen(this, ui->stackedWidget);
    SettingsScreen* settingsscreen = new SettingsScreen(this, ui->stackedWidget);
    CreditsScreen* creditsscreen = new CreditsScreen(this, ui->stackedWidget);
    ui->stackedWidget->addWidget(mainscreen);
    ui->stackedWidget->addWidget(gamescreen);
    ui->stackedWidget->addWidget(tutorialscreen);
    ui->stackedWidget->addWidget(settingsscreen);
    ui->stackedWidget->addWidget(creditsscreen);
    ui->stackedWidget->setCurrentWidget(mainscreen);
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

