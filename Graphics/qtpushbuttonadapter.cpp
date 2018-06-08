#include "qtpushbuttonadapter.h"
#include <Graphics/qtwidget.h>

QtPushButtonAdapter::QtPushButtonAdapter() : QObject(),  widget_(new QPushButton())
{      
   connect(widget_, &QPushButton::released, this, &QtPushButtonAdapter::callback);
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

void QtPushButtonAdapter::setParent(std::shared_ptr<Widget> widget)
{
    auto qWidget = std::dynamic_pointer_cast<QtWidget>(widget);
    if (qWidget){
        widget_->setParent(qWidget->getSourceWidget());
    }else {

    }
}

QPushButton *QtPushButtonAdapter::getSourceWidget()
{
    return widget_;
}

void QtPushButtonAdapter::callback()
{
    callbackFunc_();
}
