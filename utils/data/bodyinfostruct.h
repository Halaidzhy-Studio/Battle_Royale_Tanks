#ifndef BODYINFOSTRUCT_H
#define BODYINFOSTRUCT_H

#include "infostruct.h"

struct TankBodyInfo : public RectInfoStruct {
    int speed;
    int turnSpeed;
    int hp;
};

#endif // BODYINFOSTRUCT_H
