#include "qtgraphicsadapter.h"
#include "qtgraphicsitemadapter.h"
#include "qtwidget.h"

QtGraphicsAdapter::QtGraphicsAdapter(const std::shared_ptr<Logger>& logger) : scene_(new QGraphicsScene()),
                       view_(new QGraphicsView()), logger_(logger)
{
    view_->setScene(scene_);
}

void QtGraphicsAdapter::setSceneRect(int xp, int yp, int x, int y)
{
    scene_->setSceneRect(xp, yp, x, y);
}

void QtGraphicsAdapter::addItem(GraphicsItem *item)
{
    auto qtItem = dynamic_cast<QtGraphicsItemAdapter*>(item);
    if (qtItem){
        scene_->addItem(qtItem);
    }else {
        logger_->printLog("Can't cast GraphicsItem* to QtGraphicsItemAdapter*", "[GRAPHICS]");
    }
}

void QtGraphicsAdapter::setControlable(GraphicsItem *item)
{
    auto qtItem = dynamic_cast<QtGraphicsItemAdapter*>(item);
    if (qtItem){
        qtItem->setFocus();
        qtItem->setFlag(QGraphicsItem::ItemIsFocusable);
    }else {
        logger_->printLog("Can't cast GraphicsItem* to QtGraphicsItemAdapter*", "[GRAPHICS]");
    }
}

void QtGraphicsAdapter::setViewParent(Widget *parent)
{
    auto qtWidget = dynamic_cast<QtWidget*>(parent);

    if (qtWidget){
        view_->setParent(qtWidget->getSourceWidget());
    }else {
        logger_->printLog("Can't cast Widget* to QtWidget*", "[GRAPHICS]");
    }

    view_->setFixedSize(parent->getW(), parent->getH());
}

void QtGraphicsAdapter::addWidget(Widget *widget)
{
    auto qtWidget = dynamic_cast<QtWidget*>(widget);

    if (qtWidget){
        scene_->addWidget(qtWidget->getSourceWidget());
    }else {
        logger_->printLog("Can't cast Widget* to QtWidget*", "[GRAPHICS]");
    }
}

void QtGraphicsAdapter::centerViewOn(int x, int y)
{
    view_->centerOn(x, y);
}
