#ifndef TANKCOMPLEXOBJECT_H
#define TANKCOMPLEXOBJECT_H

#include <utils/data/tankinfostruct.h>
#include "igameobject.h"
#include "tankbody.h"
#include "tankturret.h"
#include <components/body/logicbodycomponent.h>
#include <components/turret/logicturretcomponent.h>
#include <Graphics/graphics.h>
#include <Physics/physics.h>

class TankComplexObject: public Object{
public:
    TankComplexObject() = default;
    TankComplexObject(const std::shared_ptr<TankBody> &,
                      const std::shared_ptr<TankTurret> &,
                      const std::shared_ptr<LogicBodyComponent>&,
                      const std::shared_ptr<LogicTurretComponent>&);

    void update() override {
        body_->update();
        turret_->update();
    }

    void setBody(const std::shared_ptr<TankBody> &body);
    void setTurret(const std::shared_ptr<TankTurret> &turret);
    void createTank();
    Coordinate getPos();
    std::shared_ptr<TankBody> getBody() const;
    void setPos(const Coordinate& coord);

    bool isTankAlive() const;
private:
    TankInfo tankInfo;
    std::shared_ptr<TankBody> body_;
    std::shared_ptr<TankTurret> turret_;

    std::shared_ptr<LogicBodyComponent> logicBodyComponent_;
    std::shared_ptr<LogicTurretComponent> logicTurretComponent_;

    bool isJointsCreated_;
};


#endif // TANKCOMPLEXOBJECT_H
