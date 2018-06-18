#include "tankcomplexobject.h"
#include "tankbody.h"

TankComplexObject::TankComplexObject(
        const std::shared_ptr<TankBody> &body,
        const std::shared_ptr<TankTurret> &turret,
        const std::shared_ptr<LogicBodyComponent>& logicBodyComponent,
        const std::shared_ptr<LogicTurretComponent>&logicTurretComponent) :
    body_(body), turret_(turret), isJointsCreated_(false),
    logicBodyComponent_(logicBodyComponent), logicTurretComponent_(logicTurretComponent)
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

Coordinate TankComplexObject::getPos()
{
    return body_->viewComponent()->getPos();
}

std::shared_ptr<TankBody> TankComplexObject::getBody() const
{
    return body_;
}

void TankComplexObject::setPos(const Coordinate &coord)
{
    logicBodyComponent_->setCoord(coord);
}

bool TankComplexObject::isTankAlive() const
{
    if (logicBodyComponent_->hp() > 0)
        return true;

    return false;
}
