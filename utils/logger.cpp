#include "logger.h"
#include <memory>
#include <QDebug>

const std::string Logger::loggerGame = "[GAME]";
const std::string Logger::loggerNet = "[NET]";
const std::string Logger::loggerQt = "[QT]";

std::unique_ptr<Logger> Logger::instance_{};
std::string Logger::loggerDist = "QDEBUG";

Logger &Logger::instance()
{
    if (!instance_){
        instance_.reset( new Logger() );
    }
    return *instance_.get();
}

void Logger::setLoggerDist(const std::string &dist)
{
    loggerDist = dist;
}

void Logger::printLog(const std::string& data, const std::string& loggerType)
{
    if (loggerDist != "QDEBUG"){
        outFile_.write(loggerType.c_str(), loggerType.size());
        outFile_.put(':');
        outFile_.write(data.c_str(), data.size());
        outFile_.put('\n');
    }else{
        qDebug() << loggerType.data() << ":" << data.data() << "\n";
    }
}

Logger::Logger()
{
    if (loggerDist != "QDEBUG"){
        outFile_.open(loggerDist, std::ios_base::app | std::ios_base::out);
        if (!outFile_){
            throw std::runtime_error("Can't initialize Logger");
        }
    }
}

Logger::~Logger()
{
    outFile_.close();
}


