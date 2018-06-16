#include "handleinputcomponentimplbody.h"

#include <objects/commands/moveforwardcommand.h>
#include <objects/commands/movebackwardcommand.h>
#include <objects/commands/turnleftcommand.h>
#include <objects/commands/turnrightcommand.h>
#include <engine.h>

HandleInputComponentImplBody::HandleInputComponentImplBody(GraphicsItem *item,
                                                           const std::shared_ptr<LogicBodyComponent> bodyInfoComponent,
                                                           const std::shared_ptr<Logger> &logger) :
    item_(item), bodyInfoComponent_(bodyInfoComponent), logger_(logger)
{
}

void HandleInputComponentImplBody::update()
{
    keys_ = item_->getActiveKeys();
    if (keys_ & static_cast<int>(Engine::Keys::KEY_W)){
        keyW_->execute();
    } else if (keys_ & static_cast<int>(Engine::Keys::KEY_S)){
        keyS_->execute();
    }

    if (keys_ & static_cast<int>(Engine::Keys::KEY_A)){
        keyA_->execute();
    }else if (keys_ & static_cast<int>(Engine::Keys::KEY_D)){
        keyD_->execute();
    }

    logger_->printLog(*bodyInfoComponent_, "[GAME]");
}

void HandleInputComponentImplBody::initCommand()
{
    auto moveable = std::dynamic_pointer_cast<Moveable>(bodyInfoComponent_);
    if (moveable){
        keyW_ = std::make_shared<MoveForwardCommand>(std::static_pointer_cast<Moveable>(bodyInfoComponent_));
        keyS_ = std::make_shared<MoveBackwardCommand>(std::static_pointer_cast<Moveable>(bodyInfoComponent_));
    }else{
        logger_->printLog("Body doesn't have Move Possibility", "[GAME]");
    }

    auto turnable = std::dynamic_pointer_cast<Turnable>(bodyInfoComponent_);
    if (turnable){
        keyA_ = std::make_shared<TurnLeftCommand>(std::static_pointer_cast<Turnable>(bodyInfoComponent_));
        keyD_ = std::make_shared<TurnRightCommand>(std::static_pointer_cast<Turnable>(bodyInfoComponent_));
    }else {
        logger_->printLog("Body doesn't have Turn Possibility", "[GAME]");
    }

}

