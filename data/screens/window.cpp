
#include "window.h"
#include "screen.h"
#include "ui_window.h"
#include "mainmenuscreen.h"
#include <QResizeEvent>
#include <QDebug>


Window::Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    MainMenuScreen* mainscreen = new MainMenuScreen(this);
    ui->stackedWidget->addWidget(mainscreen);
    ui->stackedWidget->setCurrentWidget(mainscreen);
}

void Window::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    if (Screen *widget = (Screen*)(ui->stackedWidget->currentWidget())) {
        widget->resizeScreen(event);
    }
}
Window::~Window()
{
    delete ui;
}


