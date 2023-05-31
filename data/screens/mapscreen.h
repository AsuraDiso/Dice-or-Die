#ifndef MAPSCREEN_H
#define MAPSCREEN_H

#include <QWidget>
#include "screen.h"

namespace Ui {
class MapScreen;
}

class MapScreen : public Screen
{
    Q_OBJECT

public:
    explicit MapScreen(QWidget *parent = nullptr, QStackedWidget *stacked = nullptr);
    void resizeScreen(QResizeEvent *event) override;
    ~MapScreen();

private:
    Ui::MapScreen *ui;
};

#endif // MAPSCREEN_H
