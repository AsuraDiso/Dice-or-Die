#include "checkbox.h"
#include <QVBoxLayout>

CheckBox::CheckBox(QWidget *parent):QCheckBox(parent)
{
}

void CheckBox::resize(double width, double height){
    if (not pt.x()){
        pt = pos();
        scale = size();
    }

    int size = 450;
    QSize desiredSize(size, size);

    double deltaSize = qMin((double)width / desiredSize.width(), (double)height / desiredSize.height());
    move(pt.x()*deltaSize, pt.y()*deltaSize);
    setFixedSize(scale.width()*deltaSize, scale.height()*deltaSize);
    //setStyleSheet("QCheckBox::indicator { width: "+QString::number(deltaSize*50)+"px; height: "+QString::number(deltaSize*50)+"px; }");
}

void CheckBox::setPosition(int x, int y){
    pt.setX(x); pt.setY(y);
}

void CheckBox::setScale(int w, int h){
    scale.setWidth(w); scale.setHeight(h);
}


CheckBox::~CheckBox(){}
