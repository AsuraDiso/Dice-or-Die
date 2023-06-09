#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QWidget>
#include <QCheckBox>

class CheckBox : public QCheckBox
{
    Q_OBJECT

public:
    explicit CheckBox(QWidget *parent = nullptr);
    void resize(double width, double height);
    void setPosition(int x, int y);
    void setScale(int w, int h);
    ~CheckBox();

private:
    QPoint pt;
    QSize scale;
};

#endif // CHECKBOX_H

