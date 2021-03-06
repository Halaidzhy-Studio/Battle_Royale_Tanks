#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <string>
#include <fstream>
#include "loggerinterface.h"

class QtLogger: public Logger{
public:
    static const std::string loggerGame;
    static const std::string loggerNet;
    static const std::string loggerQt;

    static std::string loggerDist;
    QtLogger();
    QtLogger(const QtLogger&) = delete;
    QtLogger(const QtLogger&&) = delete;
    QtLogger& operator=(const QtLogger&) = delete;
    QtLogger& operator=(QtLogger&&) = delete;

    virtual ~QtLogger();

    static void setLoggerDist(const std::string& dist);
    void printLog(const std::string& data, const std::string& loggerType) override;

private:
    std::string loggerType_;
    std::ofstream outFile_;

    static const std::string QDEBUG_DIST;

};
#endif // LOGGER_H
