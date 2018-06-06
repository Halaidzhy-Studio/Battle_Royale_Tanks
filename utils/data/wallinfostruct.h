#ifndef WALLINFOSTRUCT_H
#define WALLINFOSTRUCT_H

#include <utils/data/infostruct.h>

struct WallInfo : public RectShapeInfo, public InfoStruct
{
    int x;
    int y;
};
#endif // WALLINFOSTRUCT_H
