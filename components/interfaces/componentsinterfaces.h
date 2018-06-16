#ifndef COMPONENTSINTERFACES_H
#define COMPONENTSINTERFACES_H

#include <objects/possibilityinterfaces.h>
class GameObject;

class HandleInputComponent{
public:
    virtual void update(Controlable* gameObject) = 0;
    virtual void initKeyBoardCommand() = 0;
    virtual void setObject(Controlable* gameObject) { }
};

class ViewComponent{
public:
    virtual void update(GameObject* gameObject) = 0;
};

class PhysicsComponent{
public:
    virtual void update(GameObject* gameObject) = 0;
};


#endif // COMPONENTSINTERFACES_H
