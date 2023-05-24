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
    explicit MainMenuScreen(QWidget *parent = nullptr, QStackedWidget *stacked = nullptr);
    void resizeScreen(QResizeEvent *event) override;
    ~MainMenuScreen();

private slots:
    void on_exit_clicked();
    void on_credits_clicked();

    void on_start_clicked();

    void on_tutorial_clicked();

    void on_options_clicked();

private:
    Ui::MainMenuScreen *ui;
    QLabel title;
};

#endif // MAINMENUSCREEN_H
