#include "contactcomponentcircleimpl.h"
#include <QObject>
#include <QTimer>

ContactComponentCircleImpl::ContactComponentCircleImpl(
        const std::shared_ptr<LogicCircleComponent> &logicComponent,
        const std::shared_ptr<Logger> &logger,
        const std::vector<std::shared_ptr<TankComplexObject> > &tanks) :
    logicComponent_(logicComponent), logger_(logger), tanks_(tanks)
{
    checkTimer_ = std::make_unique<QTimer>();
    connect(checkTimer_.get(), &QTimer::timeout, this, &ContactComponentCircleImpl::checkContactsWithTanks);

    checkTimer_->start(1000*logicComponent_->getCircleInfo().check_interval);
}


void ContactComponentCircleImpl::contactObject(std::shared_ptr<ContactEntity>)
{
}

void ContactComponentCircleImpl::checkContactsWithTanks()
{
    for (const auto& tank: tanks_){
        Coordinate tankCoord = tank->getPos();
        tankCoord.toQt();
        Coordinate circleCenter = logicComponent_->getCenter();
        circleCenter.toQt();

        if (Coordinate::length(tankCoord, circleCenter) > logicComponent_->getRadius()){
            auto contactCircle = std::dynamic_pointer_cast<ContactEntity>(logicComponent_);
            if (contactCircle)
                tank->getBody()->contactComponent()->contactObject(contactCircle);
            else
                logger_->printLog("Can't cast LogicCircleComponent* to ContactEntity*", "[GAME]");
        }
    }
}
