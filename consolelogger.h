#ifndef CONSOLELOGGER_H_
#define CONSOLELOGGER_H_

#include <fstream>
#include <string>
#include <chrono>
#include <time.h>

class ConsoleLogger{
private:
    std::string m_FileName;
public:
    ConsoleLogger(std::string m_FileName = "log.txt");
    std::string getCurrentTime();
    void log(std::string str);
};

#endif