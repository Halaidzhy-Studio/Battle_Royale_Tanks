#ifndef TANKBODY_H
#define TANKBODY_H

#include <utils/data/bodyinfostruct.h>
#include "igameobject.h"

class TankBody: public GameObject
{
public:
    TankBody() = default;
    TankBody(const std::shared_ptr<ViewComponent>& viewComponent,
             const std::shared_ptr<PhysicsComponent>& physicsComponent,
             const std::shared_ptr<HandleInputComponent>& handleInputComponent):
            GameObject(viewComponent, physicsComponent),
            handleInputComponent_(handleInputComponent) {}

    void update() override {
        if (handleInputComponent_)
            handleInputComponent_->update(nullptr);

        GameObject::update();
    }

    std::shared_ptr<HandleInputComponent> handleInputComponent() const;
    void setHandleInputComponent(const std::shared_ptr<HandleInputComponent> &handleInputComponent);

    std::shared_ptr<NetworkComponent> networkComponent() const;
    void setNetworkComponent(const std::shared_ptr<NetworkComponent> &networkComponent);

protected:
    std::shared_ptr<HandleInputComponent> handleInputComponent_;
    std::shared_ptr<NetworkComponent> networkComponent_;
};


#endif // TANKBODY_H
