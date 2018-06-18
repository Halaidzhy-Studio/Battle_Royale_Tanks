#include "contactcomponentbodyimpl.h"
#include <objects/commands/damagecommand.h>
#include <components/circle/logiccirclecomponent.h>

ContactComponentBodyImpl::ContactComponentBodyImpl(
        const std::shared_ptr<LogicBodyComponent> &logicComponent,
        const std::shared_ptr<Logger> &logger) :
    logicComponent_(logicComponent), logger_(logger)
{
}

void ContactComponentBodyImpl::contactObject(std::shared_ptr<ContactEntity> entity)
{
    switch (entity->getEntityType()) {
    case ContactEntityTypes::CIRCLE:{
        circleContact(entity);
    }
    default:
        break;
    }
}

void ContactComponentBodyImpl::circleContact(const std::shared_ptr<ContactEntity> &entity)
{
    auto circle = std::dynamic_pointer_cast<LogicCircleComponent>(entity);
    if (circle){
        int dmg = circle->getDmg();
        auto dmgDist = std::dynamic_pointer_cast<Damageable>(logicComponent_);
        if (dmgDist){
            DamageCommand dmgcmd(dmgDist, dmg);
            dmgcmd.execute();
        }else{
            logger_->printLog("Can't cast LogicBodyComponent* to Damageable*", "[GAME]");
        }
    }else{
        logger_->printLog("Can't cast ContactEntity* to LogicCircleComponent*", "[GAME]");
    }
}

