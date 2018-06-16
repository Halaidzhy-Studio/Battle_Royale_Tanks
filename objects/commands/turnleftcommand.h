#ifndef TURNLEFTCOMMAND_H
#define TURNLEFTCOMMAND_H

#include <objects/commands/command.h>
#include <objects/possibilityinterfaces.h>
#include <memory>

class TurnLeftCommand : public Command{
public:
    TurnLeftCommand() = default;
    ~TurnLeftCommand() = default;

    TurnLeftCommand(std::shared_ptr<Turnable> object) : object_(object) {}

    void execute() override{
        object_->turnL();
    }
private:
    std::shared_ptr<Turnable> object_;
};

#endif // TURNLEFTCOMMAND_H
