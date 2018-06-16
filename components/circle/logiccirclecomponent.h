#ifndef LOGICCIRCLECOMPONENT_H
#define LOGICCIRCLECOMPONENT_H

#include <utils/data/circleinfostruct.h>
#include <objects/possibilityinterfaces.h>
class LogicCircleComponent : public Modifiable
{
public:
    LogicCircleComponent() = delete;
    LogicCircleComponent(const CircleInfo&);
    ~LogicCircleComponent() = default;

    int getRadius() const;
    void decrease() override;
    CircleInfo getCircleInfo() const;

    int circleToMoveTime() const;
private:
    const CircleInfo circleInfoConst_;
    CircleInfo circleInfoDynamic_;

    int timeToMove_;
};

#endif // LOGICCIRCLECOMPONENT_H
