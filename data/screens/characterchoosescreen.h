#ifndef CHARACTERCHOOSESCREEN_H
#define CHARACTERCHOOSESCREEN_H

#include <QWidget>
#include "screen.h"

namespace Ui {
class CharacterChooseScreen;
}

class CharacterChooseScreen : public Screen
{
    Q_OBJECT

public:
    explicit CharacterChooseScreen(QWidget *parent = nullptr, QStackedWidget *stacked = nullptr);
    void resizeScreen(QResizeEvent *event) override;
    void sizeInit();
    ~CharacterChooseScreen();

private slots:
    void on_nextturn_clicked();

private:
    Ui::CharacterChooseScreen *ui;
};

#endif // CHARACTERCHOOSESCREEN_H
