#include "handleinputcomponentimplbody.h"

#include <objects/commands/moveforwardcommand.h>
#include <objects/commands/movebackwardcommand.h>
#include <objects/commands/turnleftcommand.h>
#include <objects/commands/turnrightcommand.h>
#include <objects/commands/stopmovecommand.h>
#include <objects/commands/stopturncommand.h>
#include <engine.h>

HandleInputComponentImplBody::HandleInputComponentImplBody(const std::shared_ptr<Graphics>& graphics,
                                                           const std::shared_ptr<LogicBodyComponent>& bodyInfoComponent,
                                                           const std::shared_ptr<Logger> &logger) :
    graphics_(graphics), bodyInfoComponent_(bodyInfoComponent), logger_(logger)
{
}

void HandleInputComponentImplBody::update()
{
    keys_ = graphics_->getActiveKeys();
    if (keys_ & static_cast<int>(Engine::Keys::KEY_W)){
        keyW_->execute();
    } else if (keys_ & static_cast<int>(Engine::Keys::KEY_S)){
        keyS_->execute();
    }else {
        stopMove_->execute();
    }

    if (keys_ & static_cast<int>(Engine::Keys::KEY_A)){
        keyA_->execute();
    }else if (keys_ & static_cast<int>(Engine::Keys::KEY_D)){
        keyD_->execute();
    }else{
        stopTurn_->execute();
    }

}

void HandleInputComponentImplBody::initCommand()
{
    auto moveable = std::dynamic_pointer_cast<Moveable>(bodyInfoComponent_);
    if (moveable){
        keyW_ = std::make_shared<MoveForwardCommand>(moveable);
        keyS_ = std::make_shared<MoveBackwardCommand>(moveable);
        stopMove_ = std::make_shared<StopMoveCommand>(moveable);
    }else{
        logger_->printLog("Body doesn't have Move Possibility", "[GAME]");
    }

    auto turnable = std::dynamic_pointer_cast<Turnable>(bodyInfoComponent_);
    if (turnable){
        keyA_ = std::make_shared<TurnLeftCommand>(turnable);
        keyD_ = std::make_shared<TurnRightCommand>(turnable);
        stopTurn_ = std::make_shared<StopTurnCommand>(turnable);
    }else {
        logger_->printLog("Body doesn't have Turn Possibility", "[GAME]");
    }

}

