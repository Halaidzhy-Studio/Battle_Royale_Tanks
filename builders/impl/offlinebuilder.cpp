#include "offlinebuilder.h"

OfflineBuilder::OfflineBuilder(const std::shared_ptr<OfflineBuilderImpl> &impl) :
    impl_(impl)
{
}

std::shared_ptr<HandleInputComponent> OfflineBuilder::getHandleInputComponent()
{
    return impl_->getHandleInputComponent();
}

std::shared_ptr<PhysicsComponent> OfflineBuilder::getPhysicsComponent()
{
    return impl_->getPhysicsComponent();
}

std::shared_ptr<ViewComponent> OfflineBuilder::getViewComponent()
{
    return impl_->getViewComponent();
}

std::shared_ptr<ContactComponent> OfflineBuilder::getContactComponent()
{
    return impl_->getContactComponent();
}
