#ifndef SCREEN_H
#define SCREEN_H

#include <QWidget>
#include <QSizeF>
#include <QLabel>
#include <QStackedWidget>
#include <QResizeEvent>
#include <QShowEvent>

namespace Ui {
class Screen;
}

class Screen : public QWidget
{
    Q_OBJECT

public:
    explicit Screen(QWidget *parent = nullptr, QStackedWidget *stacked = nullptr);
    virtual void resizeScreen(QResizeEvent *event) = 0;
    QSize sizeHint() const;
    void sizeInit();
    void updateScale(QResizeEvent *event);
    void setAspectRatio(const QSizeF &aspectRatio);
    void setBackGroundImage(QString string);
    ~Screen();

protected:
    QStackedWidget *stackwidget;
    QLabel root;
    QSizeF aspectRatio{9, 16};
};

#endif // SCREEN_H