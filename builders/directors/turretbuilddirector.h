#ifndef TURRETBUILDDIRECTOR_H
#define TURRETBUILDDIRECTOR_H

#include <builders/interfaces/turret/turretbuilder.h>
#include <objects/tankturret.h>
#include <memory>

#include <QGraphicsScene>
#include <Box2D.h>

class TurretBuilderDirector
{
public:
    TurretBuilderDirector(const std::shared_ptr<QGraphicsScene>& scene,
                          const std::shared_ptr<b2World>& world) : scene_(scene), world_(world) {}

    void setBuilder(const std::shared_ptr<TurretBuilder> &builder);

    std::shared_ptr<TankTurret> getTurret();
private:
    std::shared_ptr<TurretBuilder> builder_;

    std::shared_ptr<QGraphicsScene> scene_;
    std::shared_ptr<b2World> world_;
};

#endif // TURRETBUILDDIRECTOR_H
