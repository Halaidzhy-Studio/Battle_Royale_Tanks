#ifndef OFFLINEBUILDER_H
#define OFFLINEBUILDER_H

#include <builders/interfaces/builder.h>
#include <builders/interfaces/offlinebuilderimpl.h>

class OfflineBuilder : public Builder
{
public:
    OfflineBuilder(const std::shared_ptr<OfflineBuilderImpl>&);
    std::shared_ptr<HandleInputComponent> getHandleInputComponent() override;
    std::shared_ptr<PhysicsComponent> getPhysicsComponent() override;
    std::shared_ptr<ViewComponent> getViewComponent() override;
    std::shared_ptr<ContactComponent> getContactComponent() override;

private:
    std::shared_ptr<OfflineBuilderImpl> impl_;

};

#endif // OFFLINEBUILDER_H
