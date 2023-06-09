#include "tutorialscreen.h"
#include "ui_tutorialscreen.h"

TutorialScreen::TutorialScreen(QWidget *parent, QStackedWidget *stackwidg) :
    Screen(parent, stackwidg),
    ui(new Ui::TutorialScreen)
{
    setBackGroundImage(":/assets/images/background.png");
    ui->setupUi(this);
}

void TutorialScreen::resizeScreen(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    Screen::updateScale(event);

}

void TutorialScreen::on_backbtn_clicked()
{
    stackwidget->setCurrentIndex(0);
}

TutorialScreen::~TutorialScreen()
{
    delete ui;
}

void TutorialScreen::on_prev_btn_clicked()
{
    ui->next_btn->setDisabled(false);
    int ind = ui->pages->currentIndex()-1;
    if (ind <= 0){
        if (ind < 0){
            return;
        } else {
            ui->prev_btn->setDisabled(true);
        }
    }
    ui->pages->setCurrentIndex(ind);
}


void TutorialScreen::on_next_btn_clicked()
{
    ui->prev_btn->setDisabled(false);
    int ind = ui->pages->currentIndex()+1;
    if (ind >= ui->pages->count()){
        if (ind > ui->pages->count()) {
            return;
        } else ui->next_btn->setDisabled(true);
    }
    ui->pages->setCurrentIndex(ind);
}

void TutorialScreen::sizeInit(){
    Screen::sizeInit();
    ui->pages->setCurrentIndex(0);
}
