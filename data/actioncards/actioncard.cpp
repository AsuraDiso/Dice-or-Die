#include "actioncard.h"
#include "ui_actioncard.h"

ActionCard::ActionCard(QWidget *parent) :
    QPushButton(parent),
    ui(new Ui::ActionCard)
{
    ui->setupUi(this);
}

ActionCard::~ActionCard()
{
    delete ui;
}
