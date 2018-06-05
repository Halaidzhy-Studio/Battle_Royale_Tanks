#include "offlinebodybuilder.h"

OfflineBodyBuilder::OfflineBodyBuilder()
{

}


std::shared_ptr<HandleInputComponent> OfflineBodyBuilder::getHandleInputComponent()
{
    return bodyBuilderImpl_->getHandleInputComponent();
}

std::shared_ptr<PhysicsComponent> OfflineBodyBuilder::getPhysicsComponent()
{
    return bodyBuilderImpl_->getPhysicsComponent();
}

std::shared_ptr<ViewComponent> OfflineBodyBuilder::getViewComponent()
{
    return bodyBuilderImpl_->getViewComponent();
}
