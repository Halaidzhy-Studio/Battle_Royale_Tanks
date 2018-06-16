#ifndef DECREASECOMMAND_H
#define DECREASECOMMAND_H

#include <objects/commands/command.h>
#include <objects/possibilityinterfaces.h>
#include <memory>

class DecreaseCommand : public Command{
public:
    DecreaseCommand() = default;
    DecreaseCommand(const std::shared_ptr<Modifiable>& object) : object_(object) {}
    void execute() override{
        object_->decrease();
    }
    ~DecreaseCommand() = default;

private:
    std::shared_ptr<Modifiable> object_;

};
#endif // DECREASECOMMAND_H
