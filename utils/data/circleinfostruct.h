#ifndef CIRCLEINFOSTRUCT_H
#define CIRCLEINFOSTRUCT_H

#include <utils/data/infostruct.h>
struct CircleInfo : public InfoStruct, public CircleShapeInfo {
    int speed;
    int r_k;
    int min_r;
    int max_r;
    int start_delay;
    int simple_delay;
    int dmg;
    int check_interval;
    int center_x;
    int center_y;

    struct CircleShapeInfo{
        double opacity;
    } circleShape;
};

#endif // CIRCLEINFOSTRUCT_H
