#ifndef LOGGERINTERFACE_H
#define LOGGERINTERFACE_H

#include<string>

class Logger
{

public:
    virtual void printLog(const std::string&, const std::string&) = 0;
};

#endif // LOGGERINTERFACE_H
