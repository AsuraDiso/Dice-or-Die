#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QWidget>
#include <QTextEdit>

class TextEdit : public QTextEdit
{
    Q_OBJECT

public:
    explicit TextEdit(QWidget *parent = nullptr);
    void resize(double width, double height);
    void setPosition(int x, int y);
    void setScale(int w, int h);
    void setFontSize(int s);
    ~TextEdit();

private:
    QPoint pt;
    QSize scale;
    int fontSize;
};

#endif // TEXTEDIT_H

