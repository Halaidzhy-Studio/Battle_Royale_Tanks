#ifndef COMPONENTSINTERFACES_H
#define COMPONENTSINTERFACES_H

class GameObject;

class HandleInputComponent{
public:
    virtual void update(GameObject* gameObject) = 0;
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
