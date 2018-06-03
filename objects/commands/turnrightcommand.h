#ifndef TURNRIGHTCOMMAND_H
#define TURNRIGHTCOMMAND_H

#include <objects/commands/command.h>
#include <objects/possibilityinterfaces.h>
#include <memory>
class TurnRightCommand : public Command{
public:
    TurnRightCommand() = default;
    ~TurnRightCommand() = default;

    TurnRightCommand(const std::shared_ptr<Turnable>& object) : object_(object) {}

    void execute() override{
        object_->turnR();
    }

private:
    std::shared_ptr<Turnable> object_;
};

#endif // TURNRIGHTCOMMAND_H
