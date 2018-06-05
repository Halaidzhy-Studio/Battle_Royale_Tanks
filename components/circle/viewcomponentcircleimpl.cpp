#include "viewcomponentcircleimpl.h"

ViewComponentCircleImpl::ViewComponentCircleImpl(const std::shared_ptr<GraphicsItem> &graphicsItem,
                                                 const std::shared_ptr<LogicCircleComponent> &logicCircle,
                                                 const std::shared_ptr<Logger> &logger) :
    graphicsItem_(graphicsItem), logicCircle_(logicCircle), logger_(logger)
{
}

void ViewComponentCircleImpl::update()
{
    int radius = logicCircle_->getRadius();
    graphicsItem_->setRect(radius*2, radius*2);
}
