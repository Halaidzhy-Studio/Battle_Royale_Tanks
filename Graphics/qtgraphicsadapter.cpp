#include "qtgraphicsadapter.h"
#include "qtgraphicsitemadapter.h"
#include "qtwidget.h"
#include "qtpushbuttonadapter.h"
#include "qtlabeladapter.h"

QtGraphicsAdapter::QtGraphicsAdapter(const std::shared_ptr<Logger>& logger) : scene_(new QGraphicsScene()),
                       view_(new QGraphicsView()), logger_(logger)
{
    view_->setScene(scene_);
}

void QtGraphicsAdapter::setSceneRect(int xp, int yp, int x, int y)
{
    scene_->setSceneRect(xp, yp, x, y);
    view_->resize(scene_->width(), scene_->height());
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


void QtGraphicsAdapter::setViewParent(std::shared_ptr<Widget> parent)
{
    auto qtWidget = std::dynamic_pointer_cast<QtWidget>(parent);

    if (qtWidget){
        view_->setParent(qtWidget->getSourceWidget());
    }else {
        logger_->printLog("Can't cast Widget* to QtWidget*", "[GRAPHICS]");
    }

    view_->setFixedSize(parent->getW(), parent->getH());
}

void QtGraphicsAdapter::addWidget(std::shared_ptr<Widget> widget)
{
    auto qtWidget = std::dynamic_pointer_cast<QtWidget>(widget);

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

void QtGraphicsAdapter::addPushButtonWidget(std::shared_ptr<PushButtonWidget> pushButton)
{
    auto qtPushButton = std::dynamic_pointer_cast<QtPushButtonAdapter>(pushButton);
    if (qtPushButton){
        scene_->addWidget(qtPushButton->getSourceWidget());
    } else {
        logger_->printLog("Can't cast PushButtonWidget* to QtPushButtonAdapter*", "[GRAPHICS]");
    }
}

void QtGraphicsAdapter::addLabelWidget(std::shared_ptr<LabelWidget>)
{
    auto qtLabelWidget = std::dynamic_pointer_cast<QtLabelAdapter>(logger_);
    if (qtLabelWidget){
        scene_->addWidget(qtLabelWidget->getSourceWidget());
    }else {
        logger_->printLog("Can't cast LabelWidget* to QtLabelAdapter*", "[GRAPHICS]");
    }
}

