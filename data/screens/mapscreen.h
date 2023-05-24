#ifndef MAPSCREEN_H
#define MAPSCREEN_H

#include <QWidget>

namespace Ui {
class MapScreen;
}

class MapScreen : public QWidget
{
    Q_OBJECT

public:
    explicit MapScreen(QWidget *parent = nullptr);
    ~MapScreen();

private:
    Ui::MapScreen *ui;
};

#endif // MAPSCREEN_H
