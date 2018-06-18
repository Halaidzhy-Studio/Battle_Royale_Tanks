#ifndef TANKTURRET_H
#define TANKTURRET_H

#include "igameobject.h"
#include <utils/data/turretinfostruct.h>


class TankTurret : public GameObject
{
public:
    TankTurret() = default;
    TankTurret(const std::shared_ptr<ViewComponent>& viewComponent,
             const std::shared_ptr<PhysicsComponent>& physicsComponent,
             const std::shared_ptr<HandleInputComponent>& handleInputComponent):
            GameObject(viewComponent, physicsComponent),
            handleInputComponent_(handleInputComponent) {}

    void update() override {
        GameObject::update();
        handleInputComponent_->update();
    }

    std::shared_ptr<HandleInputComponent> handleInputComponent() const;
    void setHandleInputComponent(const std::shared_ptr<HandleInputComponent> &handleInputComponent);

protected:
    TankTurretInfo tankTUrretInfo_;
    std::shared_ptr<HandleInputComponent> handleInputComponent_;
    std::shared_ptr<NetworkComponent> networkComponent_;

};

#endif // TANKTURRET_H
