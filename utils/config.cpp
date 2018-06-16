#include "config.h"
#include <libconfig.h++>
#include <utils/loggerinterface.h>

class Config::ConfigImpl{
public:
    ConfigImpl() = default;
    ConfigImpl(const std::shared_ptr<Logger>& logger) : logger_(logger),
    config_(std::make_unique<libconfig::Config>()), configIsUpload_(false){}

    void upload(const std::string& configName){
        try{
            config_->readFile(configName.c_str());
            configIsUpload_ = true;
        } catch ( const libconfig::FileIOException &ex){
            std::string total = "I/O erorr while reading file: " + configName + " in " + __FUNCTION__;
            logger_->printLog(total, "[CONFIG]");
        } catch (const libconfig::ParseException &ex){

            std::string total = "Parse error at " + std::string(ex.getFile()) + " : " + std::to_string(ex.getLine())
                    + " - "  + ex.getError() + " in " + __FUNCTION__;
            logger_->printLog(total, "[CONFIG]");
        }
    }
    void lookup(const std::string & setting, std::string& var) const
    {
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

    void lookup(const std::string &listSetting, int groupIndex,
                const std::string &setting, std::string& var) const{
        try{
            const libconfig::Setting& list = config_->lookup(listSetting);
            const libconfig::Setting& listElement = list[groupIndex];
            var = listElement.lookup(setting).c_str();
        }catch (const libconfig::SettingNotFoundException& ex){
            std::string totalMsg = "No '" + listSetting + "[" + std::to_string(groupIndex)
                    + "]" + setting + "' in config file";
            logger_->printLog(totalMsg, "[CONFIG]");
        }
    }

    template<class T>
    void lookup(const std::string &listSetting, int groupIndex,
                const std::string &setting, T& var) const{
        try{
            const libconfig::Setting& list = config_->lookup(listSetting);
            const libconfig::Setting& listElement = list[groupIndex];
            var = listElement.lookup(setting);
        }catch (const libconfig::SettingNotFoundException& ex){
            std::string totalMsg = "No '" + listSetting + "[" + std::to_string(groupIndex)
                    + "]" + setting + "' in config file";
            logger_->printLog(totalMsg, "[CONFIG]");
        }
    }

    int getLengthOfList(const std::string &listSetting) {
        int length = 0;
        try{
            const libconfig::Setting& list = config_->lookup(listSetting);
            length = list.getLength();
        }catch (const libconfig::SettingNotFoundException& ex){
            std::string totalMsg = "No '" + listSetting  + "' in config file";
            logger_->printLog(totalMsg, "[CONFIG]");
        }

        return length;
    }
    bool isConfigUpload() const{
        return configIsUpload_;
    }
private:
    std::unique_ptr<libconfig::Config> config_;
    std::shared_ptr<Logger> logger_;
    bool configIsUpload_;
};

Config::~Config() = default;

Config::Config(const std::shared_ptr<Logger>& logger)
{
    pImpl_ = std::make_unique<ConfigImpl>(logger);
}

void Config::upload(const std::string &fileName)
{
    pImpl_->upload(fileName);
}

void Config::lookup(const std::string &setting, std::string &var) const
{
    pImpl_->lookup(setting, var);
}

void Config::lookup(const std::string &setting, int &var) const
{
    pImpl_->lookup(setting, var);
}

void Config::lookup(const std::string &setting, bool &var) const
{
    pImpl_->lookup(setting, var);
}

void Config::lookup(const std::string &setting, float &var) const
{
    pImpl_->lookup(setting, var);
}

void Config::lookup(const std::string &list, int groupIndex, const std::string &setting, std::string &var) const
{
    pImpl_->lookup(list, groupIndex, setting, var);
}

void Config::lookup(const std::string &list, int groupIndex, const std::string &setting, int &var) const
{
    pImpl_->lookup(list, groupIndex, setting, var);
}

int Config::getLengthOfList(const std::string &list)
{
    pImpl_->getLengthOfList(list);
}

bool Config::isConfigUpload() const
{
    pImpl_->isConfigUpload();
}


