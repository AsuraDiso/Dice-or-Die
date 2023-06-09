#include "MusicManager.h"
#include <QDebug>

MusicManager *MusicManager::instance = nullptr;
QMediaPlayer *MusicManager::player = nullptr;
QAudioOutput *MusicManager::output = nullptr;
QMediaPlayer *MusicManager::player_sounds = nullptr;
QAudioOutput *MusicManager::output_sounds = nullptr;

MusicManager::MusicManager()
{
    Q_ASSERT(instance == nullptr);
    instance = this;
    player = new QMediaPlayer();
    output = new QAudioOutput();
    player_sounds = new QMediaPlayer();
    output_sounds = new QAudioOutput();
    player->setAudioOutput(output);
    player_sounds->setAudioOutput(output_sounds);
}

MusicManager::~MusicManager()
{
    Q_ASSERT(instance != nullptr);
    instance = nullptr;
}

void MusicManager::play(QString song)
{
    player->setSource(QUrl("qrc:"+song));
    player->setLoops(-1);
    player->play();
}

void MusicManager::playSound(QString song)
{
    player_sounds->setSource(QUrl("qrc:"+song));
    player_sounds->setLoops(-1);
    player_sounds->play();
}

void MusicManager::setLoop(bool isloop)
{
    if (isloop) {player->setLoops(-1);} else {player->setLoops(0); }
}

void MusicManager::setMusicVolume(int vol)
{
    output->setVolume(vol/100.0);
}

void MusicManager::setSoundsVolume(int vol)
{
    output_sounds->setVolume(vol/100.0);
}

void MusicManager::setMute(bool val)
{
    output->setMuted(val);
    output_sounds->setMuted(val);
}

void MusicManager::stop()
{
    player->setLoops(0);
    player->stop();
}




