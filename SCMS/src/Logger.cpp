#include "Logger.h"
#include <iostream>
#include <ctime>
#include <cstring>


void Logger::init() {
    logFile.open("logs/scms.log", std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file!" << std::endl;
    }
}


void Logger::log(const std::string& level,
                 const std::string& module,
                 const std::string& message) {

    time_t now = time(0);
    char* dt = ctime(&now);
    dt[strlen(dt) - 1] = '\0'; 

    logFile << "[" << dt << "] "
            << "[" << level << "] "
            << "[" << module << "] "
            << message << std::endl;
}


void Logger::close() {
    if (logFile.is_open()) {
        logFile.close();
    }
}