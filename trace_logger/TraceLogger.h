#ifndef TRACE_LOGGER_H
#define TRACE_LOGGER_H

#include <string>
#include <fstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class TraceLogger {
public:
    enum LogLevel {
        INFO,
        WARNING,
        ERROR,
        FINISH
    };

    TraceLogger(const std::string& filename, const std::string& serverIP, int serverPort);
    ~TraceLogger();

    void log(LogLevel level, const std::string& message);

private:
    std::ofstream file;
    int sockfd;
    struct sockaddr_in serverAddr;
};

#endif
