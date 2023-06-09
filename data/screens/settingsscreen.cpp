#include "settingsscreen.h"
#include "ui_settingsscreen.h"
#include "../components/musicmanager.h"

SettingsScreen::SettingsScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::SettingsScreen)
{
    setBackGroundImage(":/assets/images/background.png");
    ui->setupUi(this);
}

void SettingsScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
}

SettingsScreen::~SettingsScreen()
{
    delete ui;
}

void SettingsScreen::on_backbtn_clicked()
{
    stackwidget->setCurrentIndex(0);
}


void SettingsScreen::on_music_volume_valueChanged(int value)
{
    MusicManager::setMusicVolume(value);
}


void SettingsScreen::on_sounds_volume_valueChanged(int value)
{
    MusicManager::setSoundsVolume(value);
}

