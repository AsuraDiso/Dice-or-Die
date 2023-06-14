#ifndef BACKPACKSCREEN_H
#define BACKPACKSCREEN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "screen.h"

namespace Ui {
class BackPackScreen;
}

class BackPackScreen : public Screen
{
    Q_OBJECT

public:
    explicit BackPackScreen(QWidget *parent = nullptr, QStackedWidget *stacked = nullptr);
    void resizeScreen(QResizeEvent *event) override;
    void sizeInit();
    void onListButtonClick(QString name);
    ~BackPackScreen();

private slots:
    void on_backbtn_clicked();

private:
    Ui::BackPackScreen *ui;
};

#endif // BACKPACKSCREEN_H
