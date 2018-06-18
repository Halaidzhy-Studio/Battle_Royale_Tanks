#ifndef CONFIGCIRCLEDATA_H
#define CONFIGCIRCLEDATA_H

#include <utils/gamedata/configextractor.h>

class ConfigCircleData : public ConfigExtractor
{
public:
    ConfigCircleData() = delete;
    ConfigCircleData(const std::shared_ptr<Config>& config,
                     const std::shared_ptr<Logger>& logger);

    ~ConfigCircleData() = default;

    CircleInfo getCircleInfo() override;
private:
    template<typename T>
    void lookupWrapper(const std::string &setting, T &var);
};

#endif // CONFIGCIRCLEDATA_H
