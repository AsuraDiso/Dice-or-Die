#ifndef LEVELUPSCREEN_H
#define LEVELUPSCREEN_H

#include <QWidget>

namespace Ui {
class LevelUpScreen;
}

class LevelUpScreen : public QWidget
{
    Q_OBJECT

public:
    explicit LevelUpScreen(QWidget *parent = nullptr);
    ~LevelUpScreen();

private:
    Ui::LevelUpScreen *ui;
};

#endif // LEVELUPSCREEN_H
