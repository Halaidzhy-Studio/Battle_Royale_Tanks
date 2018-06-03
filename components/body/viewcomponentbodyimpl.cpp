#include "viewcomponentbodyimpl.h"

void ViewComponentBodyImpl::update(GameObject *gameObject)
{
    graphicsItem_->setPos(bodyInfo_->coord());
    graphicsItem_->setRotation(bodyInfo_->angle());

}

