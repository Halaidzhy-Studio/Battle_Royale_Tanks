#include "director.h"


std::shared_ptr<Circle> Director::getCircle(const std::shared_ptr<Builder> & builder)
{
    if (!builder){
        return nullptr;
    }

    std::shared_ptr<Circle> circle = std::make_shared<Circle>();
    circle->setViewComponent(builder->getViewComponent());
    circle->setHandleInputComponent(builder->getHandleInputComponent());
    return circle;
}

std::shared_ptr<TankBody> Director::getTankBody(const std::shared_ptr<Builder> &builder)
{
    if (!builder){
        return nullptr;
    }

    std::shared_ptr<TankBody> body = std::make_shared<TankBody>();
    body->setViewComponent(builder->getViewComponent());
    body->setHandleInputComponent(builder->getHandleInputComponent());
    return body;
}
