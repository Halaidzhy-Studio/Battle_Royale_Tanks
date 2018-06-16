#include "qtgraphicsadapter.h"
#include "qtgraphicsitemadapter.h"
#include "qtwidget.h"
#include "qtpushbuttonadapter.h"
#include "qtlabeladapter.h"
#include "qtgraphicssceneadapter.h"

QtGraphicsAdapter::QtGraphicsAdapter(const std::shared_ptr<Logger>& logger,
                                     const std::shared_ptr<GraphicsScene>& scene) :
                       view_(new QGraphicsView()), logger_(logger), scene_(scene)
{

    auto qtScene = std::dynamic_pointer_cast<QtGraphicsSceneAdapter>(scene);
    if (qtScene){
        view_->setScene(qtScene->sourceScene());
    }else
        logger_->printLog("Can't cast GraphicsScene* to QGraphicsScene", "[GRAPHICS]");

}

void QtGraphicsAdapter::setSceneRect(int xp, int yp, int x, int y)
{
    scene_->setRect(xp, yp, x, y);
    view_->resize(scene_->width(), scene_->height());
}

void QtGraphicsAdapter::addItem(GraphicsItem *item)
{
    scene_->addItem(item);
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
    scene_->addWidget(widget);
}

void QtGraphicsAdapter::centerViewOn(int x, int y)
{
    view_->centerOn(x, y);
}

void QtGraphicsAdapter::addPushButtonWidget(std::shared_ptr<PushButtonWidget> pushButton)
{
    scene_->addPushButtonWidget(pushButton);
}

void QtGraphicsAdapter::addLabelWidget(std::shared_ptr<LabelWidget> label)
{
    scene_->addLabelWidget(label);
}

int QtGraphicsAdapter::getActiveKeys()
{
    return scene_->getActiveKeys();
}

