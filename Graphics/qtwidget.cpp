#include "qtwidget.h"

QtWidget::QtWidget() : widget_(new QWidget())
{
}


void QtWidget::resize(int w, int h)
{
    widget_->resize(w, h);
}

QWidget *QtWidget::getSourceWidget() const
{
    return widget_;
}

int QtWidget::getW()
{
    return widget_->size().width();
}

int QtWidget::getH()
{
    return widget_->size().height();
}

void QtWidget::show()
{
    widget_->show();
}
