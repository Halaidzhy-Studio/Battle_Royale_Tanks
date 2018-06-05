#ifndef TURRETINFOSTRUCT_H
#define TURRETINFOSTRUCT_H
#include "infostruct.h"

struct TankTurretInfo : public InfoStruct, public RectShapeInfo
{
    int turnSpeed;
    int rechargeSpeed;
};

#endif // TURRETINFOSTRUCT_H
