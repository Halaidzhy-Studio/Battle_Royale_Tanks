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

void HandleInputComponentImplBody::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {

    case Qt::Key_W: keys_ |= KEY_W; break;
    case Qt::Key_S: keys_ |= KEY_S; break;
    case Qt::Key_A: keys_ |= KEY_A; break;
    case Qt::Key_D: keys_ |= KEY_D; break;

    default:
        break;
    }
}

void HandleInputComponentImplBody::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {

    case Qt::Key_W: keys_ &= ~KEY_W; break;
    case Qt::Key_S: keys_ &= ~KEY_S; break;
    case Qt::Key_A: keys_ &= ~KEY_A; break;
    case Qt::Key_D: keys_ &= ~KEY_D; break;

    default:
        break;
    }
}
