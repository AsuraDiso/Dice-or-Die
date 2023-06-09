#ifndef SCREEN_H
#define SCREEN_H

#include <QWidget>
#include <QSizeF>
#include <QLabel>
#include <QStackedWidget>
#include <QResizeEvent>
#include <QShowEvent>
#include <QTimer>
#include "../widgets/widget.h"
#include "../widgets/stackedwidget.h"
#include "../widgets/button.h"
#include "../widgets/scrollarea.h"
#include "../widgets/textimage.h"
#include "../widgets/progressbar.h"
#include "../widgets/textedit.h"
#include "../actioncards/actioncard.h"
#include "../widgets/slider.h"
#include "../widgets/checkbox.h"

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
    virtual void sizeInit();
    void updateScale(QResizeEvent *event);
    void setAspectRatio(const QSizeF &aspectRatio);
    void setBackGroundImage(QString string);
    ~Screen();

protected:
    QStackedWidget *stackwidget;
    QLabel root;
    QTimer *timer;
    QSizeF aspectRatio{9, 16};
};

#endif // SCREEN_H
