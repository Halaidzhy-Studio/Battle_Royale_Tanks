#ifndef CONFIGTANKTURRETBUILDER_H
#define CONFIGTANKTURRETBUILDER_H

#include "interfaces/turretbuilder.h"
#include "objects/tankturret.h"

#include <QGraphicsScene>
#include <Box2D.h>

class ConfigTankTurretBuilder : public TurretBuilder
{
public:
    ConfigTankTurretBuilder() = default;
    ConfigTankTurretBuilder(const TankTurretInfo& tankTurretInfo,
                            const std::shared_ptr<QGraphicsScene>& scene,
                            const std::shared_ptr<b2World>& world) :
        tankTurretInfo_(tankTurretInfo), scene_(scene), world_(world) {}
private:
    TankTurretInfo tankTurretInfo_;
    std::shared_ptr<QGraphicsScene> scene_;
    std::shared_ptr<b2World> world_;
};

#endif // CONFIGTANKTURRETBUILDER_H
