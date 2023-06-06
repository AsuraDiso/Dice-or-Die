#include "progressbar.h"
#include <QVBoxLayout>

ProgressBar::ProgressBar(QWidget *parent):QProgressBar(parent)
{
    setStyleSheet("background-color: white");
    connect(this, &QProgressBar::valueChanged, [=](){
        doDelta();
    });
}

void ProgressBar::resize(double width, double height){
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
    QFont newFont = font();
    newFont.setPointSize(fontSize*deltaSize);
    setFont(newFont);
}

void ProgressBar::setPosition(int x, int y){
    pt.setX(x); pt.setY(y);
}

void ProgressBar::setScale(int w, int h){
    scale.setWidth(w); scale.setHeight(h);
}

void ProgressBar::setFontSize(int s){
    fontSize = s;
}

void ProgressBar::doDelta(){
    QString color;
    if (value() < 25) {
        color = "red";
    } else if (value() < 50) {
        color = "orange";
    } else if (value() < 75) {
        color = "yellow";
    } else {
        color = "green";
    }
    QString styleSheet = QString("QProgressBar::chunk { background-color: %1; }").arg(color);
    setStyleSheet(styleSheet);
}

ProgressBar::~ProgressBar(){}


