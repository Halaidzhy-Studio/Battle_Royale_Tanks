#ifndef CONFIGGAMEDATA_H
#define CONFIGGAMEDATA_H

#include "gamedata.h"
#include "memory"
#include <utils/logger.h>
#include <libconfig.h++>

using namespace libconfig;

class ConfigGameData : public GameData, public std::enable_shared_from_this<ConfigGameData>
{
public:
    ConfigGameData(const std::shared_ptr<Logger>& logger) :
        configIsUpload_(false), logger_(logger)
    { config_ = std::make_shared<Config>(); }
    ConfigGameData(const ConfigGameData&) = delete;
    ConfigGameData&operator= (const ConfigGameData&) = delete;
    ConfigGameData(ConfigGameData&& other) : config_(std::move(other.config_)),
        logger_(std::move(other.logger_)), configIsUpload_(other.configIsUpload_),
        data_(std::move(other.data_)){ }

    ~ConfigGameData() {}
    void upload(std::string configName);
private:
    std::shared_ptr<Config> config_;
    bool configIsUpload_;

    // Метод для хранения класса наследника
    std::unique_ptr<ConfigGameData> data_;
    std::shared_ptr<Logger> logger_;
    // GameData interface

protected:
    // Перенес реалзацию в класс. Так как иначе в наследниках undefined reference к методу lookup
    void lookup(const std::string & setting, std::string& var){
        try{
            var = config_->lookup(setting).c_str();
        } catch(const SettingNotFoundException& ex){
            std::string totalMsg = "No '" + setting + "' in config file";
            logger_->printLog(totalMsg, "[CONFIG]");
        }
    }

    template<class T>
    void lookup(const std::string &setting, T& var)
    {
        try{
            var = config_->lookup(setting);
        } catch(const SettingNotFoundException& ex){
            std::string totalMsg = "No '" + setting + "' in config file";
            logger_->printLog(totalMsg, "[CONFIG]");
        }
    }

public:
    TankInfo getTankInfoByType(TankTypes type) override;
    TankBodyInfo getBodyInfoByType(BodyTypes type) override;
    TankTurretInfo getTurretInfoByType(TurretTypes type) override;
    BulletInfo getBulletInfoByType(BulletTypes type) override;
    MenuWindowInfo getMenuWindowInfo() override;
    SingleplayerMenuInfo getSingleplayerMenuInfo() override;
    MultiplayerMenuInfo getMultiplayerMenuInfo() override;
    GameWindowInfo getGameWindowInfo() override;
    GameInfo getGameInfo() const override;

    std::shared_ptr<GameData> createGameData() override;

protected:

    // Вызывает из наседников
    ConfigGameData(std::string der, const std::shared_ptr<Config>& config,
                   const std::shared_ptr<Logger>& logger,
                   bool configIsUpload) : config_(config),
                   configIsUpload_(configIsUpload), logger_(logger){
       logger_->printLog(der, QtLogger::loggerQt);
    }

};


#endif // CONFIGGAMEDATA_H
