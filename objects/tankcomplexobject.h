#ifndef TANKCOMPLEXOBJECT_H
#define TANKCOMPLEXOBJECT_H

#include <utils/data/tankinfostruct.h>
#include "igameobject.h"
#include "tankbody.h"
#include "tankturret.h"
class TankComplexObject: public Object{
public:
    TankComplexObject() = default;

    void update() override {
        body_->update();
        turret_->update();
    }

    void setBody(const std::shared_ptr<TankBody> &body);
    void setTurret(const std::shared_ptr<TankTurret> &turret);

private:
    TankInfo tankInfo;
    std::shared_ptr<TankBody> body_;
    std::shared_ptr<TankTurret> turret_;
};


#endif // TANKCOMPLEXOBJECT_H
