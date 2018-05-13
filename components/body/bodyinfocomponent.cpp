#include "bodyinfocomponent.h"


TankBodyInfo BodyInfoComponent::bodyInfoConst() const
{
    return bodyInfoConst_;
}

TankBodyInfo BodyInfoComponent::bodyInfoDynamic() const
{
    return bodyInfoDynamic_;
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
}

void BodyInfoComponent::moveB()
{
}

void BodyInfoComponent::moveTo(int x, int y)
{
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
