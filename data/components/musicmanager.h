#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>

class MusicManager
{
    public:
        MusicManager();
        ~MusicManager();

        static void play(QString song);
        static void setLoop(bool isloop);
        static void setVolume(int vol);
        static void setMute(bool val);
        static void stop();

    private:
        static MusicManager *instance;

        static QMediaPlayer *player;
        static QAudioOutput *output;
};

#endif // MUSICMANAGER_H
