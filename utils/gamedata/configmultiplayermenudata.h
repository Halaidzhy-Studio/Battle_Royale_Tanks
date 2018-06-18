#ifndef CONFIGMULTIPLAYERMENUDATA_H
#define CONFIGMULTIPLAYERMENUDATA_H

#include "configextractor.h"

class ConfigMultiplayerMenuData : public ConfigExtractor
{
public:
    ConfigMultiplayerMenuData(const std::shared_ptr<Config>& config,
                              const std::shared_ptr<Logger>& logger);

    MultiplayerMenuInfo getMultiplayerMenuInfo() override;

private:
    template<typename T>
    void lookupWrapper(const std::string &setting, T &var);
};

#endif // CONFIGMULTIPLAYERMENUDATA_H
