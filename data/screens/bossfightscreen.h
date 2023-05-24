#ifndef BOSSFIGHTSCREEN_H
#define BOSSFIGHTSCREEN_H

#include <QWidget>

namespace Ui {
class BossFightScreen;
}

class BossFightScreen : public QWidget
{
    Q_OBJECT

public:
    explicit BossFightScreen(QWidget *parent = nullptr);
    ~BossFightScreen();

private:
    Ui::BossFightScreen *ui;
};

#endif // BOSSFIGHTSCREEN_H
