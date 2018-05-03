#include <Box2D.h>
#include "utils/logger.h"
#include "gamephysicsengineimpl.h"

GamePhysicsEngineImpl::GamePhysicsEngineImpl(const std::shared_ptr<libconfig::Config> config): config_(config),
    timeStep_(1.0f/30),
    velocityIteration_(6),
    positionIterations_(2)
{
    try{
        timeStep_ = config_->lookup("box2d.world.time_step").c_str();
    }catch(const libconfig::SettingNotFoundException& e){
        Logger::instance().printLog("No 'box2d.world.time_step' setting in configuration file", Logger::loggerGame);
    }
    try{
        velocityIteration_ = config_->lookup("box2d.world.velocity_iteration").c_str();
    }catch(const libconfig::SettingNotFoundException& e){
        Logger::instance().printLog("No 'box2d.world.velocity_iteration' setting in configuration file", Logger::loggerGame);
    }
    try{
        positionIterations_ = config_->lookup("box2d.world.position_iteration").c_str();
    }catch(const libconfig::SettingNotFoundException& e){
        Logger::instance().printLog("No 'box2d.world.position_iteration' setting in configuration file", Logger::loggerGame);
    }
    b2Vec2 gravity(0.0f, 0.0f);
    b2World_ = std::make_unique<b2World>(gravity);
}

void GamePhysicsEngineImpl::updateGame(){
    b2World_ ->Step( timeStep_, velocityIteration_, positionIterations_);
}

void GamePhysicsEngineImpl::test(){

}
