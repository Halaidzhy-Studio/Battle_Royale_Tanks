#include "bodyinfocomponent.h"


TankBodyInfo BodyInfoComponent::bodyInfoConst() const
{
    return bodyInfoConst_;
}

TankBodyInfo BodyInfoComponent::bodyInfoDynamic() const
{
    return bodyInfoDynamic_;
}

TankBodyInfo *BodyInfoComponent::bodyInfoDynamicPtr()
{
    return &bodyInfoDynamic_;
}

void BodyInfoComponent::setBodyInfoDynamic(const TankBodyInfo &bodyInfoDynamic)
{
    bodyInfoDynamic_ = bodyInfoDynamic;
}


void BodyInfoComponent::turnR()
{
}

void BodyInfoComponent::turnL()
{
}

void BodyInfoComponent::turnTo(int angle)
{
}

void BodyInfoComponent::moveF()
{
    bodyInfoDynamic_.speed = bodyInfoConst_.speed;
}

void BodyInfoComponent::moveB()
{

}

void BodyInfoComponent::moveTo(int x, int y)
{
    coord_.setX(x, Coordinate::CoordTypes::QT);
    coord_.setY(y, Coordinate::CoordTypes::QT);
}

Coordinate BodyInfoComponent::coord() const
{
    return coord_;
}

void BodyInfoComponent::setCoord(const Coordinate &coord)
{
    coord_ = coord;
}

int BodyInfoComponent::angle() const
{
    return angle_;
}

void BodyInfoComponent::setAngle(int angle)
{
    angle_ = angle;
}
