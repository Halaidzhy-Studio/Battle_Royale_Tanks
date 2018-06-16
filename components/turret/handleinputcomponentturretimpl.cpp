#include "handleinputcomponentturretimpl.h"
#include <objects/commands/turnleftcommand.h>
#include <objects/commands/turnrightcommand.h>
#include <objects/commands/shootcommand.h>
#include <engine.h>

HandleInputComponentTurretImpl::HandleInputComponentTurretImpl(
        GraphicsItem *item,
        const std::shared_ptr<LogicTurretComponent> &logicTurret,
        const std::shared_ptr<Logger>& logger) :
    item_(item), logicTurret_(logicTurret), logger_(logger)
{
}
void HandleInputComponentTurretImpl::update()
{
    int keys = item_->getActiveKeys();
    if (keys & static_cast<int>(Engine::Keys::KEY_LEFT)){
        keyLeft_->execute();
    } else if (keys & static_cast<int>(Engine::Keys::KEY_RIGHT)) {
        keyRight_->execute();
    }

    if (keys & static_cast<int>(Engine::Keys::KEY_SPACE)){
        keySpace_->execute();
    }
}

void HandleInputComponentTurretImpl::initCommand()
{
    auto turnable = std::dynamic_pointer_cast<Turnable>(logicTurret_);
    if (turnable){
        keyLeft_ = std::make_shared<TurnLeftCommand>(turnable);
        keyLeft_ = std::make_shared<TurnRightCommand>(turnable);
    }else {
        logger_->printLog("Turret doesn't have Turn Possibility", "[GAME]");
    }

    auto shootable = std::dynamic_pointer_cast<Shootable>(logicTurret_);
    if (shootable){
        keySpace_ = std::make_shared<ShootCommand>(logicTurret_);
    }else{
        logger_->printLog("Turret doesn't have Shoot Possibility", "[GAME]");
    }
}
