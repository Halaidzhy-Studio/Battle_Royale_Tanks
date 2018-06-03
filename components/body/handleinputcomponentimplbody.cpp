#include "handleinputcomponentimplbody.h"

#include <objects/commands/moveforwardcommand.h>
#include <objects/commands/movebackwardcommand.h>
#include <objects/commands/turnleftcommand.h>
#include <objects/commands/turnrightcommand.h>

HandleInputComponentImplBody::HandleInputComponentImplBody(GraphicsItem *item,
                                                           const std::shared_ptr<BodyInfoComponent> bodyInfoComponent,
                                                           const std::shared_ptr<Logger> &logger) :
    item_(item), bodyInfoComponent_(bodyInfoComponent), logger_(logger)
{
}

void HandleInputComponentImplBody::update(Controlable *gameObject)
{
    keys_ = item_->getActiveKeys();
    if (keys_ & KEY_W){
        keyW_->execute();
    } else if (keys_ & KEY_S){
        keyS_->execute();
    }

    if (keys_ & KEY_A){
        keyA_->execute();
    }else if (keys_ & KEY_D){
        keyD_->execute();
    }

    logger_->printLog(*bodyInfoComponent_, "[GAME]");
}

void HandleInputComponentImplBody::setObject(Controlable *gameObject)
{

}


void HandleInputComponentImplBody::initCommand()
{
    keyW_ = std::make_shared<MoveForwardCommand>(std::static_pointer_cast<Moveable>(bodyInfoComponent_));
    keyS_ = std::make_shared<MoveBackwardCommand>(std::static_pointer_cast<Moveable>(bodyInfoComponent_));
    keyA_ = std::make_shared<TurnLeftCommand>(std::static_pointer_cast<Turnable>(bodyInfoComponent_));
    keyD_ = std::make_shared<TurnRightCommand>(std::static_pointer_cast<Turnable>(bodyInfoComponent_));
}

