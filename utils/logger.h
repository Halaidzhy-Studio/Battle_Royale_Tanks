#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <string>
#include <fstream>
#include "loggerinterface.h"

class Logger: public LoggerInterface{
public:
    static const std::string loggerGame;
    static const std::string loggerNet;
    static const std::string loggerQt;

    static std::string loggerDist;

    static Logger &instance();

    Logger(const Logger&) = delete;
    Logger(const Logger&&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger& operator=(Logger&&) = delete;

    virtual ~Logger();

    static void setLoggerDist(const std::string& dist);
    void printLog(const std::string& data, const std::string& loggerType) override;

private:

    static std::unique_ptr<Logger> instance_;
    std::string loggerType_;
    std::ofstream outFile_;

    Logger();

};
#endif // LOGGER_H
