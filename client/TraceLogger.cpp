#include "TraceLogger.h"
#include <iostream>

TraceLogger::TraceLogger(const std::string& filename, const std::string& serverIP, int serverPort) {
    // Open file in append mode
    file.open(filename, std::ios_base::app);
    if (!file.is_open()) {
        std::cerr << "Error opening log file." << std::endl;
    }

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error creating socket." << std::endl;
        return;
    }

    // Set up the server address structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    serverAddr.sin_addr.s_addr = inet_addr(serverIP.c_str());

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error connecting to server." << std::endl;
    }
}

TraceLogger::~TraceLogger() {
    file.close();
    close(sockfd);
}

void TraceLogger::log(LogLevel level, const std::string& message) {
    // Log to file for INFO and WARNING levels
    if (level == INFO || level == WARNING) {
        file << "[" << level << "] " << message << std::endl;
    }

    // Log to server for ERROR and FINISH levels
    if (level == ERROR || level == FINISH) {
        std::string logMessage = "[" + std::to_string(level) + "] " + message;
        send(sockfd, logMessage.c_str(), logMessage.length(), 0);
    }
}
