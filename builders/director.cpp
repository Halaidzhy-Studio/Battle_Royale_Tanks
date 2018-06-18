#include "director.h"
#include <components/body/logicbodycomponent.h>

std::shared_ptr<Circle> Director::getCircle(const std::shared_ptr<Builder> & builder)
{
    if (!builder){
        return nullptr;
    }

    auto circle = std::make_shared<Circle>();

    circle->setViewComponent(builder->getViewComponent());
    circle->setHandleInputComponent(builder->getHandleInputComponent());
    circle->setContactComponent(builder->getContactComponent());

    return circle;
}

std::shared_ptr<Circle> Director::getShapeCircle(const std::shared_ptr<Builder> &builder)
{
    if (!builder){
        return nullptr;
    }

    auto circle = std::make_shared<Circle>();
    circle->setViewComponent(builder->getViewComponent());

    return circle;
}


std::shared_ptr<TankBody> Director::getTankBody(const std::shared_ptr<Builder> &builder)
{
    if (!builder){
        return nullptr;
    }

    auto body = std::make_shared<TankBody>();
    body->setViewComponent(builder->getViewComponent());
    body->setHandleInputComponent(builder->getHandleInputComponent());
    body->setPhysicsComponent(builder->getPhysicsComponent());
    body->setContactComponent(builder->getContactComponent());
    return body;
}

std::shared_ptr<Wall> Director::getWall(const std::shared_ptr<Builder> &builder)
{
    if (!builder){
        return nullptr;
    }
    auto wall = std::make_shared<Wall>();
    wall->setViewComponent(builder->getViewComponent());
    wall->setPhysicsComponent(builder->getPhysicsComponent());
    return wall;
}

std::shared_ptr<TankTurret> Director::getTurret(const std::shared_ptr<Builder> &builder)
{
    if (!builder){
        return nullptr;
    }
    auto turret = std::make_shared<TankTurret>();
    turret->setHandleInputComponent(builder->getHandleInputComponent());
    turret->setViewComponent(builder->getViewComponent());

    return turret;
}
