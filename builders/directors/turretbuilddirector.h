#ifndef TURRETBUILDDIRECTOR_H
#define TURRETBUILDDIRECTOR_H

#include <builders/interfaces/turretbuilder.h>
#include <objects/tankturret.h>
#include <memory>

class TurretBuilderDirector
{
public:
    TurretBuilderDirector();

    void setBuilder(const std::shared_ptr<TurretBuilder> &builder);

    std::shared_ptr<TankTurret> getTurret();
private:
    std::shared_ptr<TurretBuilder> builder_;
};

#endif // TURRETBUILDDIRECTOR_H
