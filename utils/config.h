#ifndef CONFIG_H
#define CONFIG_H

#include <memory>
#include <utils/loggerinterface.h>

class Config
{
public:
    static const int NO_FINDED_INDEX;

    ~Config();
    Config(const std::shared_ptr<Logger> &logger);

    void upload(const std::string& fileName);

    // PIMPL и шаблоны несовместимы, пришлось перегружать.
    void lookup(const std::string &setting, std::string& var) const;
    void lookup(const std::string &setting, int& var) const;
    void lookup(const std::string &setting, bool& var) const;
    void lookup(const std::string &setting, float& var) const;
    void lookup(const std::string &setting, double& var) const;

    void lookup(const std::string &list, int groupIndex,
                const std::string &setting, std::string& var) const;
    void lookup(const std::string &list, int groupIndex,
                const std::string &setting, int& var) const;
    void lookup(const std::string &list, int groupIndex,
                const std::string &setting, bool& var) const;
    void lookup(const std::string &list, int groupIndex,
                const std::string &setting, double& var) const;
    void lookup(const std::string &list, int groupIndex,
                const std::string &setting, float& var) const;
    int findIndexOfType(const std::string &listNameInConfig, const std::string &type);
    int findIndexOfType(const std::string &listNameInConfig, const int &type);

    int getLengthOfList(const std::string &list);
    bool isConfigUpload() const;
private:
    class ConfigImpl;
    std::unique_ptr<ConfigImpl> pImpl_;
};

#endif // CONFIG_H
