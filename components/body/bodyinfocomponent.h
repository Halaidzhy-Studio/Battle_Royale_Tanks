#ifndef BODYINFOCOMPONENT_H
#define BODYINFOCOMPONENT_H

#include <utils/data/bodyinfostruct.h>
#include <utils/coordinate.h>
#include <objects/possibilityinterfaces.h>

#include <components/body/handleinputcomponentimplbody.h>
#include <components/body/physicscomponentbodyimpl.h>
#include <components/body/viewcomponentbodyimpl.h>
#include <memory>

class HandleInputComponentImplBody;
class ViewComponentBodyImpl;
class PhysicsComponentBodyImpl;

class BodyInfoComponent : public Moveable, public Turnable
{
public:
    BodyInfoComponent() = delete;
    ~BodyInfoComponent() = default;
    BodyInfoComponent(const TankBodyInfo& bodyInfo,
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

    std::shared_ptr<HandleInputComponentImplBody> handleInputComponentImpl_;
    std::shared_ptr<ViewComponentBodyImpl> viewComponentImlp_;
    std::shared_ptr<PhysicsComponentBodyImpl> physicsComponentImpl_;

};

#endif // BODYINFOCOMPONENT_H
