#ifndef CREDITSSCREEN_H
#define CREDITSSCREEN_H

#include <QWidget>
#include "screen.h"

namespace Ui {
class CreditsScreen;
}

class CreditsScreen : public Screen
{
    Q_OBJECT

public:
    explicit CreditsScreen(QWidget *parent = nullptr, QStackedWidget *stacked = nullptr);
    void resizeScreen(QResizeEvent *event) override;
    void sizeInit();
    ~CreditsScreen();

private slots:
    void on_backbutton_clicked();

private:
    Ui::CreditsScreen *ui;
};

#endif // CREDITSSCREEN_H
