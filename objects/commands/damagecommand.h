#ifndef DAMAGECOMMAND_H
#define DAMAGECOMMAND_H

#include <objects/commands/command.h>
#include <objects/possibilityinterfaces.h>
#include <memory>

class DamageCommand : public Command{
public:
    DamageCommand() = default;
    DamageCommand(const std::shared_ptr<Damageable>& object, int dmg) : object_(object), dmg_(dmg) {}
    void execute() override{
        if (object_)
            object_->hit(dmg_);
    }

    void execute(int dmg){
        object_->hit(dmg);
    }
    ~DamageCommand() = default;

private:
    std::shared_ptr<Damageable> object_;
    int dmg_;

};

#endif // DAMAGECOMMAND_H
