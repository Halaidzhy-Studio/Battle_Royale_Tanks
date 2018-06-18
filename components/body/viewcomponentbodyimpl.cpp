#include "viewcomponentbodyimpl.h"
#include "qdebug.h"
ViewComponentBodyImpl::ViewComponentBodyImpl(GraphicsItem *graphicsItem,
                                             const std::shared_ptr<LogicBodyComponent> &bodyInfo) :
    graphicsItem_(graphicsItem), bodyInfo_(bodyInfo)
{
}

void ViewComponentBodyImpl::update()
{
    graphicsItem_->setPos(bodyInfo_->coord());
    graphicsItem_->setRotation(bodyInfo_->angle());
}

GraphicsItem *ViewComponentBodyImpl::getGraphicsItem()
{
    return graphicsItem_;
}

Coordinate ViewComponentBodyImpl::getPos()
{
    return bodyInfo_->coord();
}
