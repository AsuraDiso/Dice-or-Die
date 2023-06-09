#include "button.h"
#include <QVBoxLayout>

Button::Button(QWidget *parent):QPushButton(parent)
{
    setStyleSheet("background-color: white");
}

void Button::resize(double width, double height){
    if (not pt.x()){
        pt = pos();
        scale = size();
        fontSize = font().pointSize();
    }

    int size = 450;
    QSize desiredSize(size, size);

    double deltaSize = qMin((double)width / desiredSize.width(), (double)height / desiredSize.height());
    move(pt.x()*deltaSize, pt.y()*deltaSize);
    setFixedSize(scale.width()*deltaSize, scale.height()*deltaSize);
    setIconSize(scale*deltaSize);
    QFont newFont = font();
    newFont.setPointSize(fontSize*deltaSize);
    setFont(newFont);
}

void Button::setPosition(int x, int y){
    pt.setX(x); pt.setY(y);
}

void Button::setScale(int w, int h){
    scale.setWidth(w); scale.setHeight(h);
}

void Button::setFontSize(int s){
    fontSize = s;
}

Button::~Button(){}


