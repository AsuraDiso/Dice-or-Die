#include "backpackscreen.h"
#include "ui_backpackscreen.h"

BackPackScreen::BackPackScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::BackPackScreen)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop);

    for (int i = 0; i < 20; i++)
    {
        Button *button = new Button(this);
        button->setText("Button " + QString::number(i));
        connect(button, &Button::clicked, [=](){
            onListButtonClick(QString::number(i));
        });
        layout->addWidget(button);
    }

    ui->scrollAreaWidgetContents->setLayout(layout);
}

void BackPackScreen::onListButtonClick(QString name){
    qDebug() << "TEST";
}

void BackPackScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);
}

void BackPackScreen::sizeInit(){
    Screen::sizeInit();
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
