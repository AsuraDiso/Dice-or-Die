#ifndef STACKEDWIDGET_H
#define STACKEDWIDGET_H

#include <QWidget>
#include <QStackedWidget>

class StackedWidget : public QStackedWidget{
    Q_OBJECT

public:
    explicit StackedWidget(QWidget *parent = nullptr);
    void resize(double width, double height);
    void setPosition(int x, int y);
    void setScale(int w, int h);
    void setFontSize(int s);
    ~StackedWidget();
private:
    QPoint pt;
    QSize scale;
    int fontSize;

};

#endif // STACKEDWIDGET_H
