#ifndef LOGICTURRETCOMPONENT_H
#define LOGICTURRETCOMPONENT_H

#include <objects/possibilityinterfaces.h>
#include <utils/data/turretinfostruct.h>
#include <utils/loggerinterface.h>
#include <memory>

class LogicTurretComponent : public Turnable, public Shootable
{
public:

    LogicTurretComponent() = delete;
    LogicTurretComponent(const TankTurretInfo&,
                         const std::shared_ptr<Logger>&);
    ~LogicTurretComponent() = default;


    void shoot() override;
    void turnR() override;
    void turnL() override;
    void turnTo(int angle) override;
    void turnTo(double angle) override;
    int bulletRechargeTime();
    int getAngle();
private:
    const TankTurretInfo turretInfoConst_;
    TankTurretInfo turretInfoDynamic_;
    std::shared_ptr<Logger> logger_;
    int angle_;
    int bulletRechargeTime_;

};

#endif // LOGICTURRETCOMPONENT_H
