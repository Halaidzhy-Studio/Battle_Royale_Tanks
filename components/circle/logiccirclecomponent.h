#ifndef LOGICCIRCLECOMPONENT_H
#define LOGICCIRCLECOMPONENT_H

#include <utils/data/circleinfostruct.h>
#include <objects/possibilityinterfaces.h>
#include <Graphics/graphics.h>
#include <Graphics/graphicsitem.h>
#include <components/interfaces/componentsinterfaces.h>

class Circle;
class LogicCircleComponent : public Modifiable, public ContactEntity
{
public:
    LogicCircleComponent() = delete;
    LogicCircleComponent(const CircleInfo&,
                         const std::shared_ptr<Graphics>& graphics,
                         const std::shared_ptr<Logger>& logger);
    ~LogicCircleComponent() = default;

    int getRadius() const;
    void decrease() override;
    CircleInfo getCircleInfo() const;
    const CircleInfo* getCircleInfoPtr();

    void createShapeCircle(int radius);
    void closeShapeCircle();

    int circleToMoveTime() const;
    void setCircleTimeToMove(int time);
    void setGraphics(const std::shared_ptr<Graphics> &graphics);
    Coordinate getCenter();
    int getDmg() const;

    ContactEntityTypes getEntityType() override;
private:
    const CircleInfo circleInfoConst_;
    CircleInfo circleInfoDynamic_;
    std::shared_ptr<Graphics> graphics_;
    std::shared_ptr<Logger> logger_;
    std::shared_ptr<Circle> shapeCircle_;
    int timeToMove_;

};

#endif // LOGICCIRCLECOMPONENT_H
