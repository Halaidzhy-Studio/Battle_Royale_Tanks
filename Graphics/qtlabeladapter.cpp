#include "qtlabeladapter.h"
#include "qtwidget.h"

QtLabelAdapter::QtLabelAdapter(const std::shared_ptr<Logger> &logger) :
    logger_(logger), widget_(new QLabel())
{
}

void QtLabelAdapter::setGeometry(int x, int y, int w, int h)
{
    widget_->setGeometry(x, y, w, h);
}

void QtLabelAdapter::setText(const std::string & text)
{
    widget_->setText(QString::fromStdString(text));
}

void QtLabelAdapter::setTexture(int w, int h, const std::string &path)
{
    QPixmap pixmap(QString::fromStdString(path));
    widget_->setPixmap(pixmap.scaled(w, h));
}

void QtLabelAdapter::setParentWidget(std::shared_ptr<Widget> parent)
{
    auto qtWidget = std::dynamic_pointer_cast<QtWidget>(parent);
    if (qtWidget){
        widget_->setParent(qtWidget->getSourceWidget());
    }else {
        logger_->printLog("Can't cast Widget* to QtWidget*", "[QtLabelAdapter]");
    }
}

void QtLabelAdapter::setTextSize(int size)
{
    QFont font;
    font.setPointSize(size);
    widget_->setFont(font);
}

QLabel *QtLabelAdapter::getSourceWidget()
{
    return widget_;
}
