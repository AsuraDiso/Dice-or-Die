#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

    public:
        explicit Widget(QWidget *parent = nullptr);
        void resize(double width, double height);
        void setPosition(int x, int y);
        void setScale(int w, int h);
        ~Widget();

    protected:
        QPoint pt;
        QSize scale;
        int fontSize;
};

#endif // WIDGET_H

