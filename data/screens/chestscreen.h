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
    ~ChestScreen();

private slots:

private:
    Ui::ChestScreen *ui;
};

#endif // CHESTSCREEN_H
