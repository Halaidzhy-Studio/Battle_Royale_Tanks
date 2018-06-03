#include "bodyinfocomponent.h"


BodyInfoComponent::BodyInfoComponent(const TankBodyInfo &bodyInfo,
                                     const std::shared_ptr<Logger> &logger) :
    bodyInfoConst_(bodyInfo), bodyInfoDynamic_(bodyInfo), logger_(logger)
{
    // Изначально танк не двигается
    bodyInfoDynamic_.speed = 0;
    bodyInfoDynamic_.turnSpeed = 0;
    angle_ = 0;
}

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
    bodyInfoDynamic_.turnSpeed = -bodyInfoConst_.turnSpeed;
}

void BodyInfoComponent::turnL()
{
    bodyInfoDynamic_.turnSpeed = bodyInfoConst_.turnSpeed;
}

void BodyInfoComponent::turnTo(int angle)
{
    angle_ = angle;
}

void BodyInfoComponent::moveF()
{
    bodyInfoDynamic_.speed = bodyInfoConst_.speed;
}

void BodyInfoComponent::moveB()
{
    bodyInfoDynamic_.speed = -bodyInfoConst_.speed;

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

BodyInfoComponent::operator std::string()
{
    std::string res;
    res+= "[ ";
    res+= "\"speed = ";
    res+= std::to_string(bodyInfoDynamic_.speed);
    res+="\" , \"";
    res+="turnSpeed = ";
    res+= std::to_string(bodyInfoDynamic_.turnSpeed);
    res+="\ , \" ";
    res+="hp = ";
    res+= std::to_string(bodyInfoDynamic_.hp);
    res+="\" , \" ";
    res+="( ";
    res+=std::to_string(coord_.toQt().x());
    res+=" ; ";
    res+=std::to_string(coord_.toQt().y());
    res+=" ) \" , \" ";
    res+="angle = ";
    res+=std::to_string(angle_);
    res+=" \" ]";

    return res;
}
