#include "slider.h"
#include <QVBoxLayout>

Slider::Slider(QWidget *parent):QSlider(parent)
{
    setStyleSheet("QSlider::handle:horizontal { background-color: yellow; }");
}

void Slider::resize(double width, double height){
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

void Slider::setPosition(int x, int y){
    pt.setX(x); pt.setY(y);
}

void Slider::setScale(int w, int h){
    scale.setWidth(w); scale.setHeight(h);
}

Slider::~Slider(){}


