#include "data/screens/window.h"
#include <QApplication>
#include "data/components/gamemanager.h"
#include "data/components/musicmanager.h"
#include "data/components/mapgenerator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/assets/images/icon.png"));
    a.setApplicationDisplayName("Dice or Die");
    GameManager manager;
    MusicManager music;
    Window w;
    w.show();
    return a.exec();
}
