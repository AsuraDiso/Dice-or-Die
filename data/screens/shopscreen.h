#ifndef SHOPSCREEN_H
#define SHOPSCREEN_H

#include <QWidget>
#include "screen.h"

namespace Ui {
class ShopScreen;
}

class ShopScreen : public Screen
{
    Q_OBJECT

public:
    explicit ShopScreen(QWidget *parent = nullptr, QStackedWidget *stacked = nullptr);
    void resizeScreen(QResizeEvent *event) override;
    void sizeInit();
    void spawnShopItems();
    ~ShopScreen();

private slots:

    void on_backbtn_clicked();

private:
    Ui::ShopScreen *ui;
};

#endif // SHOPSCREEN_H
