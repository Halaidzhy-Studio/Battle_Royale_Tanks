#ifndef HANDLEINPUTCOMPONENTTURRETIMPL_H
#define HANDLEINPUTCOMPONENTTURRETIMPL_H

#include <components/interfaces/componentsinterfaces.h>
#include <Graphics/graphicsitem.h>
#include <components/turret/logicturretcomponent.h>
#include <memory>
#include <objects/commands/command.h>

class HandleInputComponentTurretImpl : public HandleInputComponent
{
public:
    HandleInputComponentTurretImpl() = default;
    HandleInputComponentTurretImpl(GraphicsItem*,
                            const std::shared_ptr<LogicTurretComponent>&,
                            const std::shared_ptr<Logger>&);
    ~HandleInputComponentTurretImpl() = default;

    void update() override;
    void initCommand() override;
private:
    GraphicsItem* item_;
    std::shared_ptr<LogicTurretComponent> logicTurret_;
    std::shared_ptr<Logger> logger_;
    std::shared_ptr<Command> keyRight_;
    std::shared_ptr<Command> keyLeft_;
    std::shared_ptr<Command> keySpace_;
};

#endif // HANDLEINPUTCOMPONENTTURRETIMPL_H
