#ifndef TANKBUILDER_H
#define TANKBUILDER_H

#include <objects/igameobject.h>
#include <objects/tankcomplexobject.h>
#include <builders/directors/bodybuilderdirector.h>
#include <builders/directors/turretbuilddirector.h>

#include <QGraphicsScene>
#include <Box2D.h>

class TankBuilder
{

public:
    TankBuilder() {
    }

    virtual ~TankBuilder() = default;
    virtual std::shared_ptr<TankBody> getBody() = 0;
    virtual std::shared_ptr<TankTurret> getTurret() = 0;
protected:
    std::shared_ptr<BodyBuilderDirector> bodyDirector_;
    std::shared_ptr<TurretBuilderDirector> turretDirector_;
};

#endif // TANKBUILDER_H
