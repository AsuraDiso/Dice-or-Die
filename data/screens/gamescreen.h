#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QWidget>
#include "screen.h"

namespace Ui {
class GameScreen;
}

class GameScreen : public Screen
{
    Q_OBJECT

public:
    explicit GameScreen(QWidget *parent = nullptr, QStackedWidget *stacked = nullptr);
    void resizeScreen(QResizeEvent *event) override;
    ~GameScreen();

private:
    Ui::GameScreen *ui;
};

#endif // GAMESCREEN_H
