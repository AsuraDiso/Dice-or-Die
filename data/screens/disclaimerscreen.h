#ifndef DISCLAIMERSCREEN_H
#define DISCLAIMERSCREEN_H

#include <QWidget>
#include "screen.h"

namespace Ui {
class DisclaimerScreen;
}

class DisclaimerScreen : public Screen
{
    Q_OBJECT

public:
    explicit DisclaimerScreen(QWidget *parent = nullptr, QStackedWidget *stacked = nullptr);
    void resizeScreen(QResizeEvent *event) override;
    void sizeInit();
    ~DisclaimerScreen();

private slots:
    void on_pushButton_clicked();


private:
    Ui::DisclaimerScreen *ui;
};

#endif // DISCLAIMERSCREEN_H
