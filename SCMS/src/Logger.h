#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>

class Logger {
private:
    std::ofstream logFile;

public:
    void init();
    void log(const std::string& level,
             const std::string& module,
             const std::string& message);
    void close();
};

#endif