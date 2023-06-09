#include "progressbar.h"
#include <QVBoxLayout>

ProgressBar::ProgressBar(QWidget *parent):QProgressBar(parent)
{
    setStyleSheet("background-color: white");
    staticcolor = "";
    doDelta();
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

void ProgressBar::setStaticColor(QString color){
    staticcolor = color;
}

void ProgressBar::doDelta(){
    QString color = staticcolor;
    if (staticcolor == ""){
        double percent = (double)value() / maximum() * 100.0;

        if (percent < 25) {
            color = "red";
        } else if (percent < 50) {
            color = "orange";
        } else if (percent < 75) {
            color = "yellow";
        } else {
            color = "green";
        }
    }

    QString styleSheet = QString("QProgressBar::chunk { background-color: %1; }").arg(color);
    setStyleSheet(styleSheet);
}

void ProgressBar::setMaximum(int maximum){
    QProgressBar::setMaximum(maximum);
    doDelta();
}

ProgressBar::~ProgressBar(){}


