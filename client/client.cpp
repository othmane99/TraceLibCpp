#include "TraceLogger.h"

int main() {
    TraceLogger logger("client_log.txt", "127.0.0.1", 1234);

    logger.log(TraceLogger::INFO, "This is an information.");
    logger.log(TraceLogger::WARNING, "This is a warning.");
    logger.log(TraceLogger::ERROR, "This is an error.");
    logger.log(TraceLogger::FINISH, "Application finished.");

    return 0;
}
