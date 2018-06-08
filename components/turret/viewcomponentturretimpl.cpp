#include "viewcomponentturretimpl.h"

ViewComponentTurretImpl::ViewComponentTurretImpl(
        GraphicsItem *item,
        const std::shared_ptr<LogicTurretComponent> &logicTurret) :
    graphicsItem_(item), logicTurret_(logicTurret)
{
}

GraphicsItem *ViewComponentTurretImpl::getGraphicsItem()
{
    return graphicsItem_;
}

void ViewComponentTurretImpl::update()
{
    graphicsItem_->setRotation(logicTurret_->getAngle());
}
