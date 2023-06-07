#include "screen.h"
#include <QCoreApplication>

Screen::Screen(QWidget *parent, QStackedWidget *stacked): QWidget(parent){
    setStyleSheet("background-color: transparent");
    setAspectRatio(QSizeF(16, 9));

    stackwidget = stacked;
    parent->setMinimumSize(800, 450);
    parent->setStyleSheet("background-color: black");
    root.setParent(this);
    root.setScaledContents(true);
    root.setPixmap(QPixmap(":/assets/background.png"));
    timer = new QTimer;
}

QSize Screen::sizeHint() const
{
    return QSize(aspectRatio.width() * this->size().width(), aspectRatio.height() * this->size().width());
}

void Screen::setAspectRatio(const QSizeF &aspectRatio)
{
    this->aspectRatio = aspectRatio;
    updateGeometry();
}

void Screen::updateScale(QResizeEvent *event){
    int width = event->size().width();
    int height = event->size().height();

    int max_width = (int)(height * aspectRatio.width() / aspectRatio.height());
    int max_height = (int)(width * aspectRatio.height() / aspectRatio.width());

    int label_width = qMin(width, max_width);
    int label_height = qMin(height, max_height);
    int x = (width - label_width) / 2;
    int y = (height - label_height) / 2;
    root.setFixedSize(label_width, label_height);
    parentWidget()->parentWidget()->setGeometry(x, y, label_width, label_height);
    foreach (Widget* widget, this->findChildren<Widget*>()) {widget->resize(label_width, label_height); widget->raise();}
    foreach (Button* widget, this->findChildren<Button*>()) {widget->resize(label_width, label_height); widget->raise();}
    foreach (ScrollArea* widget, this->findChildren<ScrollArea*>()) {widget->resize(label_width, label_height); widget->raise();}
    foreach (ProgressBar* widget, this->findChildren<ProgressBar*>()) {widget->resize(label_width, label_height); widget->raise();}
    foreach (TextImage* widget, this->findChildren<TextImage*>()) {widget->resize(label_width, label_height); widget->raise();}
    foreach (StackedWidget* widget, this->findChildren<StackedWidget*>()) {widget->resize(label_width, label_height); widget->raise();}

}

void Screen::setBackGroundImage(QString string)
{
    root.setPixmap(QPixmap(string));
}

void Screen::sizeInit()
{
    QSize newSize(parentWidget()->parentWidget()->parentWidget()->size().width(), parentWidget()->parentWidget()->parentWidget()->size().height());

    QResizeEvent *resizeEvent = new QResizeEvent(newSize, newSize);
    resizeScreen(resizeEvent);
}

Screen::~Screen()
{
}
