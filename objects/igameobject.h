#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H

#include <memory>
#include "possibilityinterfaces.h"
#include "components/interfaces/componentsinterfaces.h"
#include <utils/coordinate.h>

class Object{
public:
    virtual void update() = 0;
    virtual ~Object() {}
};

class GameObject : public Object
{
public:
    GameObject() = default;
    GameObject(const std::shared_ptr<ViewComponent>& viewComponent,
               const std::shared_ptr<PhysicsComponent>& physicsComponent) :
               viewComponent_(viewComponent), physicsComponent_(physicsComponent){}

    virtual ~GameObject() = default;

    void update() override {
        if (viewComponent_)
            viewComponent_->update();

        if (physicsComponent_)
            physicsComponent_->update();
    }

    std::shared_ptr<ViewComponent> viewComponent() const;
    void setViewComponent(const std::shared_ptr<ViewComponent> &viewComponent);

    std::shared_ptr<PhysicsComponent> physicsComponent() const;
    void setPhysicsComponent(const std::shared_ptr<PhysicsComponent> &physicsComponent);

protected:
    std::shared_ptr<ViewComponent> viewComponent_;
    std::shared_ptr<PhysicsComponent> physicsComponent_;

};

#endif // IGAMEOBJECT_H
