
#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QMainWindow

{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::Window *ui;
};

#endif // WINDOW_H
