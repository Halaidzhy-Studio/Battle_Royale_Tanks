#ifndef TURNTOCOMMAND_H
#define TURNTOCOMMAND_H

#include <objects/commands/command.h>
#include <objects/possibilityinterfaces.h>
#include <memory>

class TurnToCommand : public Command{
public:
    TurnToCommand() = default;
    ~TurnToCommand() = default;

    TurnToCommand(const std::shared_ptr<Turnable>& object, int angle) :
        object_(object), angle_(angle) {}

    void execute() override{
        object_->turnTo(angle);
    }

private:
    std::shared_ptr<Turnable> object_;
    int angle_;
};

#endif // TURNTOCOMMAND_H
