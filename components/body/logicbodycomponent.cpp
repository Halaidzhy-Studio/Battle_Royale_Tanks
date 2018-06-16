#include "logicbodycomponent.h"


LogicBodyComponent::LogicBodyComponent(const TankBodyInfo &bodyInfo,
                                     const std::shared_ptr<Logger> &logger) :
    bodyInfoConst_(bodyInfo), bodyInfoDynamic_(bodyInfo), logger_(logger)
{
    // Изначально танк не двигается
    bodyInfoDynamic_.speed = 0;
    bodyInfoDynamic_.turnSpeed = 0;
    angle_ = 0;
}

TankBodyInfo LogicBodyComponent::bodyInfoConst() const
{
    return bodyInfoConst_;
}

TankBodyInfo LogicBodyComponent::bodyInfoDynamic() const
{
    return bodyInfoDynamic_;
}

TankBodyInfo *LogicBodyComponent::bodyInfoDynamicPtr()
{
    return &bodyInfoDynamic_;
}

void LogicBodyComponent::setBodyInfoDynamic(const TankBodyInfo &bodyInfoDynamic)
{
    bodyInfoDynamic_ = bodyInfoDynamic;
}

int LogicBodyComponent::hp() const
{
    return bodyInfoDynamic_.hp;
}


void LogicBodyComponent::turnR()
{
    bodyInfoDynamic_.turnSpeed = -bodyInfoConst_.turnSpeed;
}

void LogicBodyComponent::turnL()
{
    bodyInfoDynamic_.turnSpeed = bodyInfoConst_.turnSpeed;
}

void LogicBodyComponent::turnTo(int angle)
{
    angle_ = angle;
}

void LogicBodyComponent::moveF()
{
    bodyInfoDynamic_.speed = bodyInfoConst_.speed;
}

void LogicBodyComponent::moveB()
{
    bodyInfoDynamic_.speed = -bodyInfoConst_.speed;

}

void LogicBodyComponent::moveTo(int x, int y)
{
    coord_.setX(x, Coordinate::CoordTypes::QT);
    coord_.setY(y, Coordinate::CoordTypes::QT);
}

Coordinate LogicBodyComponent::coord() const
{
    return coord_;
}

void LogicBodyComponent::setCoord(const Coordinate &coord)
{
    coord_ = coord;
}

int LogicBodyComponent::angle() const
{
    return angle_;
}

void LogicBodyComponent::setAngle(int angle)
{
    angle_ = angle;
}

LogicBodyComponent::operator std::string()
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
