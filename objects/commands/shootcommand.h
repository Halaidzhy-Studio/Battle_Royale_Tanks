#ifndef SHOOTCOMMAND_H
#define SHOOTCOMMAND_H
#include <objects/commands/command.h>
#include <objects/possibilityinterfaces.h>
#include <memory>

class ShootCommand : public Command{
public:
    ShootCommand() = default;
    ~ShootCommand() = default;
    ShootCommand(const std::shared_ptr<Shootable>& object) : object_(object) {}

    void execute() override {
        object_->shoot();
    }

private:
    std::shared_ptr<Shootable> object_;
};
#endif // SHOOTCOMMAND_H
