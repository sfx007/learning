#ifndef LOGGER_HPP
#define LOGGER_HPP

/*--------[Libraries]--------*/
#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <chrono>
#include <cstring>

enum class Level{INFO,ERROR,WARN,UNKNOWN};

class TrustLog {

private:
    std::ofstream _logger;

public:
    TrustLog(const std::string&);
    ~TrustLog();
    void write(std::string level,const std::string& component,const std::string& message);
};


/*------------[Helpers Functions]-------*/
std::string level_to_string(Level level);
Level   string_to_level(std::string level);
std::string now_ms();
