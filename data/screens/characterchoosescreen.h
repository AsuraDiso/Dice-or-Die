#ifndef CHARACTERCHOOSESCREEN_H
#define CHARACTERCHOOSESCREEN_H

#include <QWidget>
#include "screen.h"
#include "../widgets/stackedwidget.h"

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
    void startGame();
    ~CharacterChooseScreen();

private slots:
    void on_charicon_clicked();

    void on_charicon_2_clicked();

    void on_charicon_3_clicked();

    void on_backbtn_clicked();

private:
    Ui::CharacterChooseScreen *ui;
};

#endif // CHARACTERCHOOSESCREEN_H
