#ifndef CONFIGTANKBUILDER_H
#define CONFIGTANKBUILDER_H


#include "interfaces/tankbuilder.h"
#include "interfaces/bodybuilder.h"
#include "interfaces/turretbuilder.h"
#include <objects/tankcomplexobject.h>

class ConfigTankBuilder : public TankBuilder
{
public:
    ConfigTankBuilder() = default;
    ConfigTankBuilder(const ConfigTankBuilder&) = delete;
    ConfigTankBuilder(ConfigTankBuilder&&) = delete;
    ConfigTankBuilder&operator=(const ConfigTankBuilder&) = delete;
    ConfigTankBuilder&operator=(ConfigTankBuilder&&) = delete;
    
    ConfigTankBuilder(const TankInfo& tankInfo,
                      const std::shared_ptr<QGraphicsScene>& scene,
                      const std::shared_ptr<b2World>& world) :
        tankInfo_(tankInfo), scene_(scene), world_(world) {}

    // TankBuilder interface
public:
    std::shared_ptr<TankBody> getBody() override;
    std::shared_ptr<TankTurret> getTurret() override;

private:
    TankInfo tankInfo_;

    std::shared_ptr<QGraphicsScene> scene_;
    std::shared_ptr<b2World> world_;
};

#endif // CONFIGTANKBUILDER_H
