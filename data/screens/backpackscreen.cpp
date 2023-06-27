#include "backpackscreen.h"
#include "ui_backpackscreen.h"
#include "../components/gamemanager.h"

BackPackScreen::BackPackScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::BackPackScreen)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop);

    ui->scrollAreaWidgetContents->setLayout(layout);
    card = nullptr;
    btn = new Button(this);
    btn->setText("Pick up");
    btn->setGeometry(315, 375, 170, 35);
    btn->hide();
    connect(btn, &Button::clicked, [=](){
        for (int i = 0; i < 3; i++) {
            ActionCard* cardtemp = nullptr;
            if (i > GameManager::getChar()->getActionCardsAmount()-1){
                cardtemp = new ActionCard(this);
            } else {
                cardtemp = GameManager::getCard(this, GameManager::getChar()->getActionCards()[i]);
            }
            cardtemp->setGeometry(-150 + ((i + 1) % 6) * 180, 50, 170, 300);
            cardtemp->resize(width(), height());
            cardtemp->show();
            Button *btntemp = new Button(this);
            btntemp->setText("Replace");
            btntemp->setGeometry(-150 + ((i + 1) % 6) * 180, 350, 170, 35);
            btntemp->show();
            btntemp->setObjectName("temp");
            connect(btntemp, &Button::clicked, [=](){
                ui->scrollArea->show();
                if (i > GameManager::getChar()->getActionCardsAmount()-1){
                    GameManager::getChar()->setCardAmount(i+1);
                    GameManager::getChar()->setCard(cardname, i);
                    GameManager::GetBackPack()->remove(cardind);
                    sizeInit();
                } else {
                    GameManager::GetBackPack()->remove(cardind);
                    GameManager::GetBackPack()->insert(GameManager::getChar()->getActionCards()[i]);
                    GameManager::getChar()->setCard(cardname, i);
                }
                for (ActionCard* cardd : this->findChildren<ActionCard*>()) {
                    delete cardd;
                }
                for (Button* cardd : this->findChildren<Button*>()) {
                    if (cardd->objectName() == "temp"){
                        delete cardd;
                    }
                }
            });
        }
        card->hide();
        card->deleteLater();
        card = GameManager::getCard(this, cardname);
        card->setGeometry(575, 50, 170, 300);
        card->resize(width(), height());
        card->show();
        card->raise();
        btn->hide();
        ui->scrollArea->hide();
    });
}

void BackPackScreen::onListButtonClick(QString name, int ind){
    cardname = name;
    cardind = ind;
    card = GameManager::getCard(this, name);
    card->setGeometry(315, 50, 170, 300);
    card->resize(width(), height());
    card->show();
    card->raise();
    btn->show();
}

void BackPackScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
}

void BackPackScreen::sizeInit(){
    Screen::sizeInit();
    for (Button* card : this->findChildren<Button*>()) {
        if (card->objectName() == "card"){
            delete card;
        }
    }
    for (int i = 0; i < GameManager::GetBackPack()->getAmount(); i++)
    {
        Button *button = new Button(this);
        button->setObjectName("card");
        button->setText(GameManager::GetBackPack()->getItem(i)->cardname);
        button->resize(width(), height());
        connect(button, &Button::clicked, [=](){
            onListButtonClick(GameManager::GetBackPack()->getItem(i)->cardname, i);
        });
        ui->scrollAreaWidgetContents->layout()->addWidget(button);
    }

    setBackGroundImage(":/assets/images/map.png");
}

void BackPackScreen::on_backbtn_clicked()
{
    stackwidget->setCurrentIndex(5);
}


BackPackScreen::~BackPackScreen()
{
    delete ui;
}
