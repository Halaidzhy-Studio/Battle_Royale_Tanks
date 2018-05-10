#include "igameobject.h"

std::shared_ptr<ViewComponent> GameObject::viewComponent() const
{
    return viewComponent_;
}

void GameObject::setViewComponent(const std::shared_ptr<ViewComponent> &viewComponent)
{
    viewComponent_ = viewComponent;
}

std::shared_ptr<PhysicsComponent> GameObject::physicsComponent() const
{
    return physicsComponent_;
}

void GameObject::setPhysicsComponent(const std::shared_ptr<PhysicsComponent> &physicsComponent)
{
    physicsComponent_ = physicsComponent;
}

Coordinate GameObject::getCoord() const
{
    return coord_;
}

void GameObject::setCoord(const Coordinate &value)
{
    coord_ = value;
}
