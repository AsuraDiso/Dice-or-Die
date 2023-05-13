#ifndef MAINMENUSCREEN_H
#define MAINMENUSCREEN_H

#include <QWidget>
#include <QSize>
#include <QLabel>
#include "screen.h"

namespace Ui {
    class MainMenuScreen;
}

class MainMenuScreen : public Screen
{
    Q_OBJECT

public:
    explicit MainMenuScreen(QWidget *parent = nullptr);
    void resizeScreen(QResizeEvent *event) override;
    ~MainMenuScreen();

private:
    Ui::MainMenuScreen *ui;
    QLabel title;
};

#endif // MAINMENUSCREEN_H
