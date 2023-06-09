#include "mainmenuscreen.h"
#include "screen.h"
#include "ui_mainmenuscreen.h"
#include <QDebug>
#include <QApplication>
#include <QResizeEvent>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "../components/musicmanager.h"
#include "../components/gamemanager.h"

MainMenuScreen::MainMenuScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::MainMenuScreen)
{
    ui->setupUi(this);

    setBackGroundImage(":/assets/images/background.png");
    MusicManager::play("/assets/music/omori_trees.mp3");
}

void MainMenuScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);

}

void MainMenuScreen::on_exit_clicked()
{
    QApplication::exit();
}

void MainMenuScreen::on_start_clicked()
{
    if (GameManager::getMap().getSize().width() == 0){
        stackwidget->setCurrentIndex(4);
        GameManager::generateNewLevel();
    } else {
        stackwidget->setCurrentIndex(5);
    }
}

void MainMenuScreen::on_tutorial_clicked()
{
    stackwidget->setCurrentIndex(1);
}

void MainMenuScreen::on_options_clicked()
{
    stackwidget->setCurrentIndex(2);
}

void MainMenuScreen::on_credits_clicked()
{
    stackwidget->setCurrentIndex(3);
}

MainMenuScreen::~MainMenuScreen()
{
    delete ui;
}
