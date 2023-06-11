#ifndef DEATHSCREEN_H
#define DEATHSCREEN_H

#include <QWidget>
#include "screen.h"

namespace Ui {
class DeathScreen;
}

class DeathScreen : public Screen
{
    Q_OBJECT

public:
    explicit DeathScreen(QWidget *parent = nullptr, QStackedWidget *stacked = nullptr);
    void resizeScreen(QResizeEvent *event) override;
    void sizeInit();
    ~DeathScreen();

private:
    Ui::DeathScreen *ui;
};

#endif // DEATHSCREEN_H
