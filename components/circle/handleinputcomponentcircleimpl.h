#ifndef HANDLEINPUTCOMPONENTCIRCLEIMPL_H
#define HANDLEINPUTCOMPONENTCIRCLEIMPL_H

#include <components/interfaces/componentsinterfaces.h>
#include <components/circle/logiccirclecomponent.h>
#include <utils/logger.h>
#include <objects/commands/command.h>
#include <objects/commands/decreasecommand.h>
#include <QObject>
#include <QTimer>

class HandleInputComponentCircleImpl : public HandleInputComponent, public QObject
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
    std::unique_ptr<QTimer> timer_;
    std::unique_ptr<QTimer> commandTimer_;

    bool isCanMoving_;
    bool isNeverMove_;
    bool isCanDecrease_;
    int nextRadius_;

    std::shared_ptr<Command> command;

    void calculateNextRadius();
    void canMove();
    void startTimer();
    void timeDecrease();
    void commandCall();
};

#endif // HANDLEINPUTCOMPONENTCIRCLEIMPL_H
