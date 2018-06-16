#ifndef INFOSTRUCT_H
#define INFOSTRUCT_H
#include <string>

// Структура, которая описывает физические свойства объекта. Общая для всех.
struct PhysicsInfo{
    int type;
    float density;
    float restitution;
    float friction;
    float mass;
    float linearDumping;
};

// Структура, которая описывает все прямоугольные объекты
struct RectInfo
{
    int w; // ширина
    int h; // высота
};

// Структура, описывает все круглые объекты
struct CircleInfo
{
    int r; // радиус
};

struct StyleInfo{
    std::string pathToTexture;
};

struct InfoStruct{
    PhysicsInfo physicsInfo;
    StyleInfo styleInfo;
};

#endif // INFOSTRUCT_H
