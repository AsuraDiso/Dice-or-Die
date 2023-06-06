#ifndef TEXTIMAGE_H
#define TEXTIMAGE_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QMovie>

class TextImage : public QLabel
{
    Q_OBJECT

public:
    explicit TextImage(QWidget *parent = nullptr);
    void resize(double width, double height);
    void setPosition(int x, int y);
    void setScale(int w, int h);
    void setFontSize(int s);
    void setMoveable(bool s);
    void setAnimatedTexture(QString filename);
    ~TextImage();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    QPoint pt;
    QSize scale;
    int fontSize;
    bool moveable;
    int lastMousePos[2]; //for some reason i can't add new QPoint
    QMovie tex;
    QLabel anim;
};

#endif // TEXTIMAGE_H
