#include "textimage.h"
#include <QPixmap>

TextImage::TextImage(QWidget *parent): QLabel(parent)//, moveable(false)
{
    moveable = false;
    burneffect.setScaledContents(true);
    burneffect.setParent(parent);
    burneffect.setPixmap(QPixmap("://assets/images/dices/diceburn.png"));
    burneffect.hide();
    burneffect.setParent(this);
    anim.setScaledContents(true);
    anim.setParent(parent);
    anim.setMovie(&tex);
    diceval = -1;
}

void TextImage::setAnimatedTexture(QString filename){
    if (tex.fileName() == filename){
        return;
    }
    tex.setFileName(filename);
    tex.start();
    clear();
}

void TextImage::setOffset(QPoint point){
    offset = point;
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
    move((pt.x()+offset.x()) * deltaSize, (pt.y()+offset.y()) * deltaSize);
    setFixedSize(scale.width() * deltaSize, scale.height() * deltaSize);
    anim.setFixedSize(scale.width() * deltaSize, scale.height() * deltaSize);
    anim.move((pt.x()+offset.x()) * deltaSize, (pt.y()+offset.y()) * deltaSize);
    burneffect.setFixedSize(50 * deltaSize, 50 * deltaSize);
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

void TextImage::setDiceVal(int dc){
    setText(QString::number(dc));
    setPixmap(QPixmap("://assets/images/dices/dice" + QString::number(dc) + ".png"));
    diceval = dc;
}

int TextImage::getDiceVal(){
    return diceval;
}
QPoint TextImage::getPos(){
    return pt;
}

void TextImage::setBurn(bool val){
    isburn = val;
    if (val){
        burneffect.show();
    } else {
        burneffect.hide();
    }
}

bool TextImage::isBurn(){
    return isburn;
}

bool TextImage::isDice(){
    return diceval > 0;
}

TextImage::~TextImage(){
}
