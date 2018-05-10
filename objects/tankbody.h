#ifndef TANKBODY_H
#define TANKBODY_H

#include <utils/data/bodyinfostruct.h>
#include "igameobject.h"

class TankBody: public GameObject, public Moveable, public Turnable
{
public:
    TankBody() = default;
    TankBody(const std::shared_ptr<ViewComponent>& viewComponent,
             const std::shared_ptr<PhysicsComponent>& physicsComponent,
             const std::shared_ptr<HandleInputComponent>& handleInputComponent):
            GameObject(viewComponent, physicsComponent),
            handleInputComponent_(handleInputComponent) {}

    void update() override {
        GameObject::update();
        handleInputComponent_->update(this);
    }

    std::shared_ptr<HandleInputComponent> handleInputComponent() const;
    void setHandleInputComponent(const std::shared_ptr<HandleInputComponent> &handleInputComponent);

    // Turnable interface
    void turnR() override;
    void turnL() override;
    void turnTo(int angle) override;

    // Moveable interface
    void moveF() override;
    void moveB() override;
    void moveTo(int x, int y) override;

protected:
    // 1) handleinput move
    // 2) physic get move

    TankBodyInfo bodyInfo;
    /*
    BodyInfoRect tankBodyInfo_; // ViewComponent + PhysicsComoponent
    StyleInfo tankBodyStyleInfo_; // ViewComponent
    PhysicsInfoTankBody tankBodyPhysicsInfo_; // PhysicsInfo
    GameplayInfoTankBody tankBodyDynamicInfo_; // Here + PhysicsInfo
    */
    std::shared_ptr<HandleInputComponent> handleInputComponent_;

};


#endif // TANKBODY_H
