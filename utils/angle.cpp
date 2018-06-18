#include "angle.h"
#include <cmath>


double Angle::normalizeDegreeAngle(double angle)
{
    while (angle <= 0){
       angle += 360;
    }
    while (angle > 360){
       angle -= 360;
    }

    return angle;
}

double Angle::radToDegree(double rad)
{
    return rad/M_PI * 180.0;
}

double Angle::degreeToRad(double degree)
{
    return degree * M_PI / 180.0;
}
