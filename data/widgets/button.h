#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QPushButton>

class Button : public QPushButton
{
    Q_OBJECT

public:
    explicit Button(QWidget *parent = nullptr);
    void resize(double width, double height);
    void setPosition(int x, int y);
    void setScale(int w, int h);
    void setFontSize(int s);
    ~Button();

private:
    QPoint pt;
    QSize scale;
    int fontSize;
};

#endif // BUTTON_H

