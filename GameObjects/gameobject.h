#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include<Box2D.h>

class GameObject
{
public:
    virtual void createInWorld(b2World*& world) = 0;
};

#endif // GAMEOBJECT_H
