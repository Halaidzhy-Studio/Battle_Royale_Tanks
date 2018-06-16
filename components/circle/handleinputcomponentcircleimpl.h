#ifndef HANDLEINPUTCOMPONENTCIRCLEIMPL_H
#define HANDLEINPUTCOMPONENTCIRCLEIMPL_H

#include <components/interfaces/componentsinterfaces.h>
#include <components/circle/logiccirclecomponent.h>
#include <utils/logger.h>
#include <objects/commands/command.h>
#include <objects/commands/decreasecommand.h>

class HandleInputComponentCircleImpl : public HandleInputComponent
{
public:
    HandleInputComponentCircleImpl() = default;
    HandleInputComponentCircleImpl(const std::shared_ptr<LogicCircleComponent>&,
                         const std::shared_ptr<Logger>&);
    ~HandleInputComponentCircleImpl() = default;
    void update() override;
    void initCommand() override;
private:
    std::shared_ptr<LogicCircleComponent> logicCircle_;
    std::shared_ptr<Logger> logger_;

    bool isCanMoving_;
    bool isNeverMove_;
    int nextRadius_;

    std::shared_ptr<Command> command;

    void calculateNextRadius();
    void canMove();
};

#endif // HANDLEINPUTCOMPONENTCIRCLEIMPL_H
