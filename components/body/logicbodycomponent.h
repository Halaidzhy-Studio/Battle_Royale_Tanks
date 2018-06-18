#ifndef BODYINFOCOMPONENT_H
#define BODYINFOCOMPONENT_H

#include <utils/data/bodyinfostruct.h>
#include <utils/coordinate.h>
#include <objects/possibilityinterfaces.h>
#include <memory>
#include <components/interfaces/componentsinterfaces.h>

class LogicBodyComponent : public Moveable, public Turnable, public Damageable, public ContactEntity
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

    int hp() const;

    // Turnable interface
    void turnR() override;
    void turnL() override;
    void turnTo(int angle) override;
    void turnTo(double angle) override;
    void stopTurn() override;
    // Moveable interface

    // Увеличивает текущую скорость танка на его хар. скорость
    void moveF() override;
    void moveB() override;
    void moveTo(int x, int y) override;
    void moveTo(const Coordinate& coord) override;
    void stopMove() override;

    // Damageable interface
    void hit(int) override;

    // ContactEntity interface
    ContactEntityTypes getEntityType() override;

    Coordinate coord() const;
    void setCoord(const Coordinate &coord);

    double angle() const;
    void setAngle(int angle);

    // Чтобы удобно выводить в лог
    operator std::string();
private:
    // Изначальные характеристики объекта
    const TankBodyInfo bodyInfoConst_;

    // Текущие характеристики объекта
    TankBodyInfo bodyInfoDynamic_;
    Coordinate coord_;
    double angle_;

    std::shared_ptr<Logger> logger_;



};

#endif // BODYINFOCOMPONENT_H
