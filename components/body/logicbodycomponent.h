#ifndef BODYINFOCOMPONENT_H
#define BODYINFOCOMPONENT_H

#include <utils/data/bodyinfostruct.h>
#include <utils/coordinate.h>
#include <objects/possibilityinterfaces.h>
#include <memory>

class HandleInputComponentImplBody;
class ViewComponentBodyImpl;
class PhysicsComponentBodyImpl;

class LogicBodyComponent : public Moveable, public Turnable
{
public:
    LogicBodyComponent() = delete;
    ~LogicBodyComponent() = default;
    LogicBodyComponent(const TankBodyInfo& bodyInfo,
                      const std::shared_ptr<Logger>& logger);

    TankBodyInfo bodyInfoConst() const;

    TankBodyInfo bodyInfoDynamic() const;
    TankBodyInfo* bodyInfoDynamicPtr();
    void setBodyInfoDynamic(const TankBodyInfo &bodyInfoDynamic);

    // Turnable interface
    void turnR() override;
    void turnL() override;
    void turnTo(int angle) override;

    // Moveable interface

    // Увеличивает текущую скорость танка на его хар. скорость
    void moveF() override;
    void moveB() override;
    void moveTo(int x, int y) override;

    Coordinate coord() const;
    void setCoord(const Coordinate &coord);

    int angle() const;
    void setAngle(int angle);

    // Чтобы удобно выводить в лог
    operator std::string();
private:
    // Изначальные характеристики объекта
    const TankBodyInfo bodyInfoConst_;

    // Текущие характеристики объекта
    TankBodyInfo bodyInfoDynamic_;
    Coordinate coord_;
    int angle_;

    std::shared_ptr<Logger> logger_;
};

#endif // BODYINFOCOMPONENT_H
