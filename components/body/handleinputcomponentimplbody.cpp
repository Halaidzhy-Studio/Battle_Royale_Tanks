#include "handleinputcomponentimplbody.h"
#include <objects/commands/moveforwardcommand.h>

HandleInputComponentImplBody::HandleInputComponentImplBody(const std::shared_ptr<BodyInfoComponent> bodyInfoComponent)
    : bodyInfoComponent_(bodyInfoComponent)
{

}


void HandleInputComponentImplBody::update(Controlable *gameObject)
{
    if ( keys_ & KEY_W){
        keyW_->execute();
    }
}

void HandleInputComponentImplBody::setObject(Controlable *gameObject)
{
    gameObject_ = gameObject;
}

void HandleInputComponentImplBody::initCommand()
{
    keyW_ = std::make_shared<MoveForwardCommand>(std::static_pointer_cast<Moveable>(bodyInfoComponent_));
}

