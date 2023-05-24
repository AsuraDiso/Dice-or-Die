#ifndef SCROLLAREA_H
#define SCROLLAREA_H

#include <QWidget>
#include <QScrollArea>

class ScrollArea : public QScrollArea
{
    Q_OBJECT

public:
    explicit ScrollArea(QWidget *parent = nullptr);
    void resize(double width, double height);
    void setPosition(int x, int y);
    void setScale(int w, int h);
    ~ScrollArea();

private:
    QPoint pt;
    QSize scale;
};

#endif // SCROLLAREA_H

