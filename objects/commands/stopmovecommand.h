#ifndef STOPMOVECOMMAND_H
#define STOPMOVECOMMAND_H

#include <objects/commands/command.h>
#include <objects/possibilityinterfaces.h>
#include <memory>

class StopMoveCommand : public Command{
public:
    StopMoveCommand() = default;
    ~StopMoveCommand() = default;

    StopMoveCommand(const std::shared_ptr<Moveable>& object) : object_(object) { }

    void execute(){
        object_->stopMove();
    }

private:
    std::shared_ptr<Moveable> object_;
};

#endif // STOPMOVECOMMAND_H
