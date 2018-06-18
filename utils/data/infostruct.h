#ifndef INFOSTRUCT_H
#define INFOSTRUCT_H
#include <string>
#include <Physics/physicsbody.h>

// Структура, которая описывает физические свойства объекта. Общая для всех.
struct PhysicsInfo{
    BodyType type;
    float density;
    float restitution;
    float friction;
    float mass;
    float linearDumping;
    double w;
    double h;
    float I;
};

// Структура, которая описывает все прямоугольные объекты
struct RectShapeInfo
{
    int w; // ширина
    int h; // высота
};

// Структура, описывает все круглые объекты
struct CircleShapeInfo
{
    int r; // радиус
};

struct StyleInfo{
    std::string pathToTexture;
    int width;
    int height;
    bool default_rect_pos;
    int x;
    int y;
    bool is_scalable;
    double opacity;
};

struct InfoStruct{
    PhysicsInfo physicsInfo;
    StyleInfo styleInfo;
};

#endif // INFOSTRUCT_H
