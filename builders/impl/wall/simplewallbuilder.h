#ifndef SIMPLEWALLBUILDER_H
#define SIMPLEWALLBUILDER_H

#include <builders/interfaces/offlinebuilderimpl.h>
#include <Graphics/graphics.h>
#include <Physics/physics.h>
#include <utils/logger.h>
#include <utils/data/wallinfostruct.h>

class SimpleWallBuilder : public OfflineBuilderImpl
{
public:
    SimpleWallBuilder(const std::shared_ptr<Graphics>&,
                      const std::shared_ptr<Physics>&,
                      const std::shared_ptr<Logger>&,
                      const WallInfo&);

    std::shared_ptr<HandleInputComponent> getHandleInputComponent() override;
    std::shared_ptr<PhysicsComponent> getPhysicsComponent() override;
    std::shared_ptr<ViewComponent> getViewComponent() override;
private:
    std::shared_ptr<Graphics> graphics_;
    std::shared_ptr<Physics> physics_;
    std::shared_ptr<Logger> logger_;
    WallInfo info_;
};

#endif // SIMPLEWALLBUILDER_H
