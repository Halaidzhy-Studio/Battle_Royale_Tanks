#ifndef BODYINFOCOMPONENT_H
#define BODYINFOCOMPONENT_H

#include <utils/data/bodyinfostruct.h>
#include <utils/coordinate.h>
#include <objects/possibilityinterfaces.h>
#include <memory>
class BodyInfoComponent : public Moveable, public Turnable
{
public:
    BodyInfoComponent() = delete;
    ~BodyInfoComponent() = default;
    BodyInfoComponent(const TankBodyInfo& bodyInfo) : bodyInfoConst_(bodyInfo), bodyInfoDynamic_(bodyInfo) {}

    TankBodyInfo bodyInfoConst() const;

    TankBodyInfo bodyInfoDynamic() const;
    void setBodyInfoDynamic(const TankBodyInfo &bodyInfoDynamic);


    // Turnable interface
    void turnR() override;
    void turnL() override;
    void turnTo(int angle) override;

    // Moveable interface
    void moveF() override;
    void moveB() override;
    void moveTo(int x, int y) override;

    Coordinate coord() const;
    void setCoord(const Coordinate &coord);

    int angle() const;
    void setAngle(int angle);

private:
    const TankBodyInfo bodyInfoConst_;
    TankBodyInfo bodyInfoDynamic_;
    Coordinate coord_;

    int angle_;
};

#endif // BODYINFOCOMPONENT_H
