#include "tankcomplexobject.h"
#include "tankbody.h"

void TankComplexObject::setBody(const std::shared_ptr<TankBody> &body)
{
    body_ = body;
}

void TankComplexObject::setTurret(const std::shared_ptr<TankTurret> &turret)
{
    turret_ = turret;
}
