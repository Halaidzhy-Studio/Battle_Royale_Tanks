#ifndef CONFIGGAMEDATA_H
#define CONFIGGAMEDATA_H

#include "gamedata.h"
#include "memory"
#include <utils/logger.h>
#include "configextractor.h"
#include <libconfig.h++>

// TODO PIMPL
class ConfigExtractorLibconfig : public ConfigExtractor, public std::enable_shared_from_this<ConfigExtractorLibconfig>
{
public:
    ConfigExtractorLibconfig(const std::shared_ptr<Logger>& logger) :
        configIsUpload_(false), logger_(logger)
    { config_ = std::make_shared<libconfig::Config>(); }

    ConfigExtractorLibconfig(const ConfigExtractorLibconfig&) = delete;
    ConfigExtractorLibconfig&operator= (const ConfigExtractorLibconfig&) = delete;

    ConfigExtractorLibconfig(ConfigExtractorLibconfig&& other) : config_(std::move(other.config_)),
        logger_(std::move(other.logger_)), configIsUpload_(other.configIsUpload_),
        data_(std::move(other.data_)){ }

    ~ConfigExtractorLibconfig() {}
    void upload(const std::string& configName) override;

    TankInfo getTankInfoByType(TankTypes type) override;
    TankBodyInfo getBodyInfoByType(BodyTypes type) override;
    TankTurretInfo getTurretInfoByType(TurretTypes type) override;
    BulletInfo getBulletInfoByType(BulletTypes type) override;
    MenuWindowInfo getMenuWindowInfo() override;
    SingleplayerMenuInfo getSingleplayerMenuInfo() override;
    MultiplayerMenuInfo getMultiplayerMenuInfo() override;
    GameWindowInfo getGameWindowInfo() override;
    GameInfo getGameInfo() override;
    ServerInfo getServerInfo() override;

private:
    // Переменная для хранения класса наследника
    std::unique_ptr<ConfigExtractorLibconfig> data_;
    std::shared_ptr<libconfig::Config> config_;

protected:
    bool configIsUpload_;
    std::shared_ptr<Logger> logger_;

    // Вызывает из наседников
    ConfigExtractorLibconfig(const std::shared_ptr<libconfig::Config>& config,
                   const std::shared_ptr<Logger>& logger,
                   bool configIsUpload) : config_(config),
                   configIsUpload_(configIsUpload), logger_(logger){}

    // Перенес реализацию в класс. Так как иначе в наследниках undefined reference к методу lookup
    void lookup(const std::string & setting, std::string& var) const{
        try{
            var = config_->lookup(setting).c_str();
        } catch(const libconfig::SettingNotFoundException& ex){
            std::string totalMsg = "No '" + setting + "' in config file";
            logger_->printLog(totalMsg, "[CONFIG]");
        }
    }

    template<class T>
    void lookup(const std::string &setting, T& var) const
    {
        try{
            var = config_->lookup(setting);
        } catch(const libconfig::SettingNotFoundException& ex){
            std::string totalMsg = "No '" + setting + "' in config file";
            logger_->printLog(totalMsg, "[CONFIG]");
        }
    }

};


#endif // CONFIGGAMEDATA_H
