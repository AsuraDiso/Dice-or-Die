#include "screen.h"

Screen::Screen(QWidget *parent): QWidget(parent){
    setStyleSheet("background-color: transparent");
    setAspectRatio(QSizeF(16, 9));

    parent->setMinimumSize(800, 450);
    parent->setStyleSheet("background-color: black");
    root.setParent(this);
    root.setScaledContents(true);
    root.setPixmap(QPixmap(":/assets/background.png"));
}

QSize Screen::sizeHint() const
{
    return QSize(m_aspectRatio.width() * this->size().width(), m_aspectRatio.height() * this->size().width());
}

void Screen::setAspectRatio(const QSizeF &aspectRatio)
{
    m_aspectRatio = aspectRatio;
    updateGeometry();
}

Screen::~Screen()
{
}
