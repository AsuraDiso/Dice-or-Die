#ifndef SETTINGSSCREEN_H
#define SETTINGSSCREEN_H

#include <QWidget>
#include "screen.h"

namespace Ui {
class SettingsScreen;
}

class SettingsScreen : public Screen
{
    Q_OBJECT

public:
    explicit SettingsScreen(QWidget *parent = nullptr, QStackedWidget *stacked = nullptr);
    void resizeScreen(QResizeEvent *event) override;
    ~SettingsScreen();

private slots:
    void on_backbtn_clicked();

    void on_music_volume_valueChanged(int value);

    void on_sounds_volume_valueChanged(int value);

private:
    Ui::SettingsScreen *ui;
};

#endif // SETTINGSSCREEN_H
