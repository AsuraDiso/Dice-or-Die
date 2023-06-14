#ifndef CHESTSCREEN_H
#define CHESTSCREEN_H

#include <QWidget>
#include "screen.h"

namespace Ui {
class ChestScreen;
}

class ChestScreen : public Screen
{
    Q_OBJECT

public:
    explicit ChestScreen(QWidget *parent = nullptr, QStackedWidget *stacked = nullptr);
    void resizeScreen(QResizeEvent *event) override;
    void sizeInit();
    void spawnCard();
    ~ChestScreen();

private slots:

    void on_take_clicked();

    void on_throw_2_clicked();

private:
    Ui::ChestScreen *ui;
    ActionCard* card;
};

#endif // CHESTSCREEN_H
