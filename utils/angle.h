#ifndef ANGLE_H
#define ANGLE_H


class Angle
{
public:
    Angle() = delete;

    // Возвращает значение от 1 до 360
    static double normalizeDegreeAngle(double angle);
    static double radToDegree(double rad);
    static double degreeToRad(double degree);
};

#endif // ANGLE_H
