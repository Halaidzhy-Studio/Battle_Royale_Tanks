#include "logicturretcomponent.h"

LogicTurretComponent::LogicTurretComponent(
        const TankTurretInfo& info,
        const std::shared_ptr<Logger>& logger) :
    turretInfoConst_(info), turretInfoDynamic_(info), logger_(logger), angle_(0)
{

}

void LogicTurretComponent::shoot()
{
}

void LogicTurretComponent::turnR()
{
    turretInfoDynamic_.turnSpeed = turretInfoConst_.turnSpeed;
}

void LogicTurretComponent::turnL()
{
    turretInfoDynamic_.turnSpeed = -turretInfoConst_.turnSpeed;
}

void LogicTurretComponent::turnTo(int angle)
{
    angle_ = angle;
}

int LogicTurretComponent::bulletRechargeTime()
{
    return bulletRechargeTime_;
}

int LogicTurretComponent::getAngle()
{
    return angle_;
}
