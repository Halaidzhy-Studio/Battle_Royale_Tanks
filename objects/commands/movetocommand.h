#ifndef MOVETOCOMMAND_H
#define MOVETOCOMMAND_H

#include "command.h"
#include <memory>
#include <objects/possibilityinterfaces.h>
class MoveToCommand : public Command{
public:
    MoveToCommand() = default;
    ~MoveToCommand() = default;

    MoveToCommand(const std::shared_ptr<Moveable>& object, int x, int y)
        : object_(object), x_(x), y_(y) { }

    void execute() override{
        object_->moveTo(x_, y_);
    }
private:
    std::shared_ptr<Moveable> object_;
    int x_, y_;
};
#endif // MOVETOCOMMAND_H
