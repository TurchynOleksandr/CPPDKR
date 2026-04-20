#include "consolelogger.h"

ConsoleLogger::ConsoleLogger(std::string m_FileName):m_FileName(m_FileName){}

std::string ConsoleLogger::getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        
    char buffer[30];
    std::strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M:%S", std::localtime(&now_c));

    return std::string(buffer);
}

 void ConsoleLogger::log(std::string str){
    std::ofstream fout(m_FileName,std::ios::app);
    fout << " [ " << getCurrentTime() << " ] " << str << std::endl;
 }