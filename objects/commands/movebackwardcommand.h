#ifndef MOVEBACKWARDCOMMAND_H
#define MOVEBACKWARDCOMMAND_H

#include <objects/commands/command.h>
#include <objects/possibilityinterfaces.h>
#include <memory>
class MoveBackwardCommand : public Command{
public:
    MoveBackwardCommand() = default;
    ~MoveBackwardCommand() = default;

    MoveBackwardCommand(const std::shared_ptr<Moveable>& object) : object_(object) {}

    void execute() override {
        object_->moveB();
    }

private:
    std::shared_ptr<Moveable> object_;
};

#endif // MOVEBACKWARDCOMMAND_H
