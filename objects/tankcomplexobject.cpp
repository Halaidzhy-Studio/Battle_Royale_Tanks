#include "tankcomplexobject.h"
#include "tankbody.h"

TankComplexObject::TankComplexObject(
        const std::shared_ptr<TankBody> &body,
        const std::shared_ptr<TankTurret> &turret) :
    body_(body), turret_(turret), isJointsCreated_(false)
{
    createTank();
}

void TankComplexObject::setBody(const std::shared_ptr<TankBody> &body)
{
    body_ = body;
}

void TankComplexObject::setTurret(const std::shared_ptr<TankTurret> &turret)
{
    turret_ = turret;
}

void TankComplexObject::createTank()
{
    if (!isJointsCreated_){
        turret_->viewComponent()->getGraphicsItem()->setParent(
            body_->viewComponent()->getGraphicsItem()
        );

        isJointsCreated_ = true;
    }
}

void TankComplexObject::setPos(const Coordinate &coord)
{

}
