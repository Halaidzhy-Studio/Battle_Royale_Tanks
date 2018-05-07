#ifndef TANKINFOSTRUCT_H
#define TANKINFOSTRUCT_H

#include "bodyinfostruct.h"
#include "turretinfostruct.h"

// Сложный объект Танк
struct TankInfo
{
    TankBodyInfo bodyInfo;
    TankTurretInfo turretInfo;

};

#endif // TANKINFOSTRUCT_H
