#ifndef COMPONENTSINTERFACES_H
#define COMPONENTSINTERFACES_H

#include <objects/possibilityinterfaces.h>
class GameObject;
class BodyInfoComponent;

class HandleInputComponent{
public:
    virtual ~HandleInputComponent() = default;

    virtual void update(Controlable* gameObject) = 0;
    virtual void initCommand() = 0;
    virtual void setObject(Controlable* gameObject) { }
};

class ViewComponent{
public:
    virtual ~ViewComponent() = default;

    virtual void update(GameObject* gameObject) = 0;
};

class PhysicsComponent{
public:
    virtual ~PhysicsComponent() = default;

    virtual void update() = 0;
};

class NetworkComponent {
public:
    virtual ~NetworkComponent() = default;

    virtual void update() = 0;
    virtual void setId() = 0;
};


#endif // COMPONENTSINTERFACES_H
