#ifndef MOVEFORWARDCOMMAND_H
#define MOVEFORWARDCOMMAND_H

#include "command.h"
#include <objects/possibilityinterfaces.h>
#include <memory>

class MoveForwardCommand : public Command{
public:
    MoveForwardCommand() = default;
    ~MoveForwardCommand() = default;

    MoveForwardCommand(const std::shared_ptr<Moveable>& object) : object_(object) { }

    void execute(){
        object_->moveF();
    }

    void setObject(const std::shared_ptr<Moveable> &object) {
        object_ = object;
    }

private:
    std::shared_ptr<Moveable> object_;
};


#endif // MOVEFORWARDCOMMAND_H
