#ifndef SCREEN_H
#define SCREEN_H

#include <QWidget>
#include <QSizeF>
#include <QLabel>
#include <QResizeEvent>

namespace Ui {
class Screen;
}

class Screen : public QWidget
{
    Q_OBJECT

public:
    explicit Screen(QWidget *parent = nullptr);
    virtual void resizeScreen(QResizeEvent *event) = 0;
    QSize sizeHint() const;
    void setAspectRatio(const QSizeF &aspectRatio);
    ~Screen();

protected:
    QLabel root;
    QSizeF m_aspectRatio{1.0, 1.5};
    int m_width{1280};
};

#endif // SCREEN_H
