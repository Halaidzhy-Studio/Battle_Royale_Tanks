#include "qtpushbuttonadapter.h"

QtPushButtonAdapter::QtPushButtonAdapter() : widget_(new QPushButton())
{      
    connect(widget_, &QPushButton::released, callbackFunc_);
}
void QtPushButtonAdapter::setGeometry(int x, int y, int w, int h)
{
    widget_->setGeometry(x, y, w, h);
}

void QtPushButtonAdapter::setText(const std::string &text)
{
    widget_->setText(QString::fromStdString(text));
}

void QtPushButtonAdapter::setCallback(std::function<void()> func)
{
    callbackFunc_ = func;
}
