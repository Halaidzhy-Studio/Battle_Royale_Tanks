#ifndef TURRETINFOSTRUCT_H
#define TURRETINFOSTRUCT_H
#include "infostruct.h"

struct TankTurretInfo : CircleInfoStruct
{
    int turnSpeed;
    int rechargeSpeed;
};

#endif // TURRETINFOSTRUCT_H
