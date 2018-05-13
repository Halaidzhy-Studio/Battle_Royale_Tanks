#include "logger.h"
#include <memory>
#include <QDebug>

const std::string QtLogger::loggerGame = "[GAME]";
const std::string QtLogger::loggerNet = "[NET]";
const std::string QtLogger::loggerQt = "[QT]";

std::unique_ptr<QtLogger> QtLogger::instance_{};
std::string QtLogger::loggerDist = "QDEBUG";

void QtLogger::setLoggerDist(const std::string &dist)
{
    loggerDist = dist;
}

void QtLogger::printLog(const std::string& data, const std::string& loggerType)
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

QtLogger::QtLogger()
{
    if (loggerDist != "QDEBUG"){
        outFile_.open(loggerDist, std::ios_base::app | std::ios_base::out);
        if (!outFile_){
            throw std::runtime_error("Can't initialize Logger");
        }
    }
}

QtLogger::~QtLogger()
{
    outFile_.close();
}


