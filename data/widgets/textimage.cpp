#include "textimage.h"
#include <QVBoxLayout>

TextImage::TextImage(QWidget *parent): QLabel(parent)//, moveable(false)
{
    moveable = true;
   //
}

void TextImage::resize(double width, double height){
    if (pt.isNull()){
        setPosition(pos().x(), pos().y());
        scale = size();
        fontSize = font().pointSize();
    }

    int size = 450;
    QSize desiredSize(size, size);

    double deltaSize = qMin(width / desiredSize.width(), height / desiredSize.height());
    move(pt.x() * deltaSize, pt.y() * deltaSize);
    setFixedSize(scale.width() * deltaSize, scale.height() * deltaSize);
    QFont newFont = font();
    newFont.setPointSize(fontSize * deltaSize);
    setFont(newFont);
}

void TextImage::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && moveable)
    {
        lastMousePos[0] = event->pos().x();
        lastMousePos[1] = event->pos().y();
    }
}

void TextImage::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton && moveable)
    {
        QPoint delta(event->pos().x() - lastMousePos[0], event->pos().y() - lastMousePos[1]);

        QPoint newTopLeft = pos() + delta;
        move(newTopLeft);
    }
}

void TextImage::setPosition(int x, int y){
    pt.setX(x); pt.setY(y);
}

void TextImage::setScale(int w, int h){
    scale.setWidth(w); scale.setHeight(h);
}

void TextImage::setFontSize(int s){
    fontSize = s;
}

void TextImage::setMoveable(bool s){
    moveable = s;
}

TextImage::~TextImage(){
}