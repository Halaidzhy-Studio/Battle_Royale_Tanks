#ifndef HANDLEINPUTCOMPONENTTURRETIMPL_H
#define HANDLEINPUTCOMPONENTTURRETIMPL_H

#include <Graphics/graphics.h>
#include <components/interfaces/componentsinterfaces.h>
#include <components/turret/logicturretcomponent.h>
#include <memory>
#include <objects/commands/command.h>

class HandleInputComponentTurretImpl : public HandleInputComponent
{
public:
    HandleInputComponentTurretImpl() = default;
    HandleInputComponentTurretImpl(const std::shared_ptr<Graphics>& graphics,
                            const std::shared_ptr<LogicTurretComponent>&,
                            const std::shared_ptr<Logger>&);
    ~HandleInputComponentTurretImpl() = default;

    void update() override;
    void initCommand() override;
private:
    std::shared_ptr<Graphics> graphics_;
    std::shared_ptr<LogicTurretComponent> logicTurret_;
    std::shared_ptr<Logger> logger_;
    std::shared_ptr<Command> keyRight_;
    std::shared_ptr<Command> keyLeft_;
    std::shared_ptr<Command> keySpace_;
};

#endif // HANDLEINPUTCOMPONENTTURRETIMPL_H
