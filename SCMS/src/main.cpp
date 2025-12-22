#include "Logger.h"
#include <iostream>

int main() {
    Logger logger;

    logger.init();

    //  start
    logger.log("INFO", "SYSTEM", "Smart Campus Management System Started");

    // Login attempt
    logger.log("INFO", "AUTH", "Admin login attempt");

    // Course addition
    logger.log("INFO", "COURSE", "Course added: Operating Systems");

    // Error 
    logger.log("ERROR", "SYSTEM", "Unexpected error occurred");

    //  shutdown
    logger.log("INFO", "SYSTEM", "System shutting down");

    logger.close();
    return 0;
}