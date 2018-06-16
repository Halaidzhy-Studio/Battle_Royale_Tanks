#include "viewcomponentbodyimpl.h"

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
