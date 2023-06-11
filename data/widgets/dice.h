#ifndef DICE_H
#define DICE_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QMovie>

class Dice : public QLabel
{
    Q_OBJECT

public:
    explicit Dice(QWidget *parent = nullptr);
    void resize(double width, double height);
    void setPosition(int x, int y);
    void setScale(int w, int h);
    void setDiceVal(int dc);
    void setBurn(bool);
    int getDiceVal();
    QPoint getPos();
    bool isBurn();
    bool isDice();
    bool isMoving();
    void setFontSize(int s);
    void setMoveable(bool s);
    void setAnimatedTexture(QString filename);
    void setOffset(QPoint point);
    ~Dice();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    QPoint pt;
    QPoint offset;
    QSize scale;
    int fontSize;
    bool moveable;
    bool ismoving;
    int lastMousePos[2]; //for some reason i can't add new QPoint
    QMovie tex;
    QLabel anim;
    QLabel burneffect;
    int diceval;
    bool isburn;
};

#endif // DICE_H
