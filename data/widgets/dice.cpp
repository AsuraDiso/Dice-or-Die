#include "dice.h"
#include <QPixmap>

Dice::Dice(QWidget *parent): QLabel(parent)//, moveable(false)
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
    isburn = false;
}

void Dice::setAnimatedTexture(QString filename){
    if (tex.fileName() == filename){
        return;
    }
    tex.setFileName(filename);
    tex.start();
    clear();
}

void Dice::setOffset(QPoint point){
    offset = point;
}

void Dice::resize(double width, double height){
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

void Dice::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && moveable)
    {
        lastMousePos[0] = event->pos().x();
        lastMousePos[1] = event->pos().y();
        ismoving = true;
    }
}

void Dice::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton && moveable)
    {
        QPoint delta(event->pos().x() - lastMousePos[0], event->pos().y() - lastMousePos[1]);

        QPoint newTopLeft = pos() + delta;
        move(newTopLeft);
        ismoving = true;
    }
}

void Dice::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        ismoving = false;  // Set the ismoving variable to false when the dice movement is completed
    }
}

void Dice::setPosition(int x, int y){
    pt.setX(x); pt.setY(y);
}

void Dice::setScale(int w, int h){
    scale.setWidth(w); scale.setHeight(h);
}

void Dice::setFontSize(int s){
    fontSize = s;
}

void Dice::setMoveable(bool s){
    moveable = s;
}

void Dice::setDiceVal(int dc){
    setText(QString::number(dc));
    setPixmap(QPixmap("://assets/images/dices/dice" + QString::number(dc) + ".png"));
    diceval = dc;
}

int Dice::getDiceVal(){
    return diceval;
}
QPoint Dice::getPos(){
    return pt;
}

void Dice::setBurn(bool val){
    isburn = val;
    if (val){
        burneffect.show();
    } else {
        burneffect.hide();
    }
}

bool Dice::isBurn(){
    return isburn;
}

bool Dice::isDice(){
    return diceval > 0;
}

bool Dice::isMoving(){
    return ismoving;
}

Dice::~Dice(){
}
