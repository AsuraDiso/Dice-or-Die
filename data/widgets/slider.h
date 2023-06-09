#ifndef SLIDER_H
#define SLIDER_H

#include <QWidget>
#include <QSlider>

class Slider : public QSlider
{
    Q_OBJECT

public:
    explicit Slider(QWidget *parent = nullptr);
    void resize(double width, double height);
    void setPosition(int x, int y);
    void setScale(int w, int h);
    ~Slider();

private:
    QPoint pt;
    QSize scale;
};

#endif // SLIDER_H

