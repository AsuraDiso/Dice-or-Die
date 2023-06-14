#include "shopscreen.h"
#include "ui_shopscreen.h"
#include "../actioncards/actioncard.h"
#include "../components/gamemanager.h"
ShopScreen::ShopScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::ShopScreen)
{
    ui->setupUi(this);

    setBackGroundImage(":/assets/images/backgrounds/shop.png");
}

void ShopScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
}

void ShopScreen::sizeInit(){
    Screen::sizeInit();
    ui->coins->setText("x"+QString::number(GameManager::getCoins()));
}

void ShopScreen::spawnShopItems(){
    for (int i = 0; i < 3; i++){
        if (GameManager::getShopItems()[i] != ""){
            ActionCard *card = GameManager::getCard(this, GameManager::getShopItems()[i]);
            card->setGeometry(185 + i * 180, 50, 170, 300);
            card->resize(width(), height());
            card->show();
            card->raise();

            TextImage *price = new TextImage(this);
            price->setGeometry(280 + i * 180, 350, 170, 40);
            ActionCard *cardd = GameManager::getCard(this, GameManager::getShopItems()[i]);
            int priceval = cardd->getPrice();
            price->setText("x"+QString::number(priceval));
            delete cardd;
            price->resize(width(), height());
            price->show();
            price->raise();

            TextImage *priceimg = new TextImage(this);
            priceimg->setGeometry(250 + i * 180, 355, 30, 30);
            priceimg->setScaledContents(true);
            priceimg->resize(width(), height());
            priceimg->show();
            priceimg->raise();
            priceimg->setPixmap(QPixmap("://assets/images/coin.png"));

            Button *btn = new Button(this);
            btn->setGeometry(235 + i * 180, 395, 70, 30);
            btn->setText("Buy");
            btn->resize(width(), height());
            btn->show();
            btn->raise();

            connect(btn, &Button::clicked, this, [=](){
                if (GameManager::getCoins() >= priceval){
                    delete card;
                    delete btn;
                    delete price;
                    delete priceimg;
                    GameManager::setShopItem(i, ""); //all bought items will be like that
                }
            });
        }
    }
}
ShopScreen::~ShopScreen()
{
    delete ui;
}

void ShopScreen::on_backbtn_clicked()
{
    stackwidget->setCurrentIndex(5);
}

