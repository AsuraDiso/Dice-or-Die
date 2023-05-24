#include "scrollarea.h"
#include <QVBoxLayout>

ScrollArea::ScrollArea(QWidget *parent):QScrollArea(parent)
{
    //setStyleSheet("background-color: white");
}

void ScrollArea::resize(double width, double height){
    if (not pt.x()){
        pt = pos();
        scale = size();
    }

    int size = 450;
    QSize desiredSize(size, size);

    double deltaSize = qMin((double)width / desiredSize.width(), (double)height / desiredSize.height());
    move(pt.x()*deltaSize, pt.y()*deltaSize);
    setFixedSize(scale.width()*deltaSize, scale.height()*deltaSize);
}

void ScrollArea::setPosition(int x, int y){
    pt.setX(x); pt.setY(y);
}

void ScrollArea::setScale(int w, int h){
    scale.setWidth(w); scale.setHeight(h);
}

ScrollArea::~ScrollArea(){}


