#ifndef TUTORIALSCREEN_H
#define TUTORIALSCREEN_H

#include <QWidget>
#include "screen.h"

namespace Ui {
class TutorialScreen;
}

class TutorialScreen : public Screen
{
    Q_OBJECT

public:
    explicit TutorialScreen(QWidget *parent = nullptr, QStackedWidget *stacked = nullptr);
    void resizeScreen(QResizeEvent *event) override;
    ~TutorialScreen();

private:
    Ui::TutorialScreen *ui;
};

#endif // TUTORIALSCREEN_H
