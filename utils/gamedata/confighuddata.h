#ifndef CONFIGHUDDATA_H
#define CONFIGHUDDATA_H

#include <utils/gamedata/configextractor.h>
class ConfigHudData : public ConfigExtractor
{
public:
    ConfigHudData() = delete;
    ~ConfigHudData() = default;
    ConfigHudData(const std::shared_ptr<Config>& config,
                         const std::shared_ptr<Logger>& logger);

    HudInfo getHudInfo() override;
private:
    template<typename T>
    void lookupWrapper(const std::string &setting, T &var);
};

#endif // CONFIGHUDDATA_H
