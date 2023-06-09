#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QWidget>
#include <QProgressBar>

class ProgressBar : public QProgressBar
{
    Q_OBJECT

public:
    explicit ProgressBar(QWidget *parent = nullptr);
    void resize(double width, double height);
    void setPosition(int x, int y);
    void setScale(int w, int h);
    void setFontSize(int s);
    void setStaticColor(QString color);
    void doDelta();
    void setMaximum(int maximum);
    ~ProgressBar();

private:
    QPoint pt;
    QSize scale;
    int fontSize;
    QString staticcolor;
};

#endif // PROGRESSBAR_H

