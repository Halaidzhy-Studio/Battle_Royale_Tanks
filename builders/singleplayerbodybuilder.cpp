#include "singleplayerbodybuilder.h"

SingleplayerBodyBuilder::SingleplayerBodyBuilder()
{

}


std::shared_ptr<HandleInputComponent> SingleplayerBodyBuilder::getHandleInputComponent()
{
    bodyBuilderImpl_->getHandleInputComponent();
}

std::shared_ptr<PhysicsComponent> SingleplayerBodyBuilder::getPhysicsComponent()
{
    bodyBuilderImpl_->getPhysicsComponent();
}

std::shared_ptr<ViewComponent> SingleplayerBodyBuilder::getViewComponent()
{
    bodyBuilderImpl_->getViewComponent();
}
