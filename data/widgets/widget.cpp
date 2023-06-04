#include "widget.h"

Widget::Widget(QWidget *parent):QWidget(parent)
{
    setStyleSheet("background-color: white");
}

void Widget::resize(double width, double height){
    if (not pt.x()){
        pt = pos();
        scale = size();
    }

    int size = 450;
    QSize desiredSize(size, size);

    double deltaSize = qMin((double)width / desiredSize.width(), (double)height / desiredSize.height());
    setGeometry(pt.x()*deltaSize, pt.y()*deltaSize, scale.width()*deltaSize, scale.height()*deltaSize);
}

void Widget::setPosition(int x, int y){
    pt.setX(x); pt.setY(y);
}

void Widget::setScale(int w, int h){
    scale.setWidth(w); scale.setHeight(h);
}

Widget::~Widget(){}


