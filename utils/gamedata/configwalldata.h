#ifndef CONFIGWALLDATA_H
#define CONFIGWALLDATA_H

#include <utils/gamedata/configextractor.h>

class ConfigWallData : public ConfigExtractor
{
public:
    ConfigWallData() = delete;
    ConfigWallData(const std::shared_ptr<Config> &config,
                       const std::shared_ptr<Logger> &logger);
    ~ConfigWallData() = default;

    WallInfo getWallInfo() override;
private:
    template<typename T>
    void lookupWrapper(const std::string &setting, T &var);
};

#endif // CONFIGWALLDATA_H
