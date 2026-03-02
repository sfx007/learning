#include "../include/logger.hpp"



int main(int ac, char *av[])
{
    if(ac < 2)
    {
        std::cout << "Error: Invalid Arguments" << std::endl;
        return 1;
    }
    std::string cmd(av[1]);
    std::string file;
    std::string level;
    std::string component;
    std::string message;
    std::string request_id;

    if(cmd == "--help" || cmd == "-h")
    {
        std::cout << R"(
trustlog v0.1.0 — structured log writer and reader

Usage:
  trustlog append --file PATH --level LEVEL --component NAME --message TEXT
  trustlog --help
  trustlog --version

Commands:
  append    Write one log entry to the file
  read      Print log entries (with optional filters)

Options:
  --file        Path to log file (required)
  --level       DEBUG, INFO, WARN, or ERROR
  --component   Source component name (max 32 chars)
  --message     Log message text (max 1024 chars)
  --request-id  Correlation ID (optional)

Exit codes:
  0  Success
  1  Invalid arguments
  2  File error
)" << std::endl;
    }
    else if (cmd == "append")
    {
        for(int i = 1; i < ac; i++)
        {
            if(strcmp(av[i], "--file") == 0)
                file = av[++i];
            else if (strcmp(av[i], "--level") == 0)
                level = av[++i];
            else if(strcmp(av[i], "--component") == 0)
                component = av[++i];
            else if(strcmp(av[i], "--message") == 0)
                message = av[++i];
            else if (strcmp(av[i], "--request-id") == 0)
                request_id = av[++i]; 
        }
        TrustLog log(file);
        log.write(level,component,message);   
    }
    else
    {
        std::cerr << "ERROR: Invalid Arguments" << std::endl;
        return 1;
    }
    return 0;
}
