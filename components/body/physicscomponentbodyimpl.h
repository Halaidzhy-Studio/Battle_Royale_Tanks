#ifndef PHYSICSCOMPONENTBODYIMPL_H
#define PHYSICSCOMPONENTBODYIMPL_H

#include <components/interfaces/componentsinterfaces.h>
#include <components/body/logicbodycomponent.h>
#include <objects/commands/movetocommand.h>
#include <utils/data/infostruct.h>
#include <Physics/physics.h>
#include <Physics/physicsbody.h>
#include <Physics/vec2d.h>
#include <objects/commands/command.h>
#include <objects/commands/movetocommand.h>
#include <objects/commands/turntocommand.h>

class PhysicsComponentBodyImpl : public PhysicsComponent
{
public:
    PhysicsComponentBodyImpl() = default;
    PhysicsComponentBodyImpl(const std::shared_ptr<Physics>&,
                             const std::shared_ptr<LogicBodyComponent>&,
                             const std::shared_ptr<Logger>&);

    ~PhysicsComponentBodyImpl() = default;
    void update() override;
    void setPos(const Coordinate&) override;
private:
    std::shared_ptr<Physics> physics_;
    std::shared_ptr<LogicBodyComponent> logicComponent_;
    std::shared_ptr<PhysicsBody> body_;
    std::shared_ptr<Logger> logger_;
    std::shared_ptr<MoveToCommand> move_;
    std::shared_ptr<TurnToCommand> turn_;

    void updateTurn(double turnSpeed);
    void updateDrive(int speed);
    void initCommand();

};

#endif // PHYSICSCOMPONENTBODYIMPL_H
