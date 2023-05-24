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
    ui->logo->resize(root.width(), root.height());
    ui->start->resize(root.width(), root.height());
    ui->tutorial->resize(root.width(), root.height());
    ui->options->resize(root.width(), root.height());
    ui->credits->resize(root.width(), root.height());
    ui->exit->resize(root.width(), root.height());
}

void MainMenuScreen::on_exit_clicked()
{
    QApplication::exit();
}

void MainMenuScreen::on_start_clicked()
{
    stackwidget->setCurrentIndex(1);
}

void MainMenuScreen::on_tutorial_clicked()
{
    stackwidget->setCurrentIndex(2);
}

void MainMenuScreen::on_options_clicked()
{
    stackwidget->setCurrentIndex(3);
}

void MainMenuScreen::on_credits_clicked()
{
    stackwidget->setCurrentIndex(4);
}

MainMenuScreen::~MainMenuScreen()
{
    delete ui;
}
