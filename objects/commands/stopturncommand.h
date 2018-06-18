#ifndef STOPTURNCOMMAND_H
#define STOPTURNCOMMAND_H

#include <objects/commands/command.h>
#include <objects/possibilityinterfaces.h>
#include <memory>

class StopTurnCommand : public Command{
public:
    StopTurnCommand() = default;
    ~StopTurnCommand() = default;

    StopTurnCommand(const std::shared_ptr<Turnable>& object) : object_(object) { }

    void execute(){
        object_->stopTurn();
    }

private:
    std::shared_ptr<Turnable> object_;
};

#endif // STOPTURNCOMMAND_H
