#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class TCPServer {
private:
    int sockfd;
    struct sockaddr_in serverAddr;

public:
    TCPServer(int port) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            std::cerr << "Error creating socket." << std::endl;
            return;
        }

        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(port);
        serverAddr.sin_addr.s_addr = INADDR_ANY;

        if (bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
            std::cerr << "Error binding socket." << std::endl;
            return;
        }

        if (listen(sockfd, 5) < 0) {
            std::cerr << "Error listening for connections." << std::endl;
            return;
        }
    }

    ~TCPServer() {
        close(sockfd);
    }

    void start() {
        while (true) {
            struct sockaddr_in clientAddr;
            socklen_t clientLen = sizeof(clientAddr);
            int clientSockfd = accept(sockfd, (struct sockaddr*)&clientAddr, &clientLen);
            if (clientSockfd < 0) {
                std::cerr << "Error accepting connection." << std::endl;
                continue;
            }

            std::cout << "New connection accepted." << std::endl;

            close(clientSockfd);
        }
    }
};

int main() {
    TCPServer server(1234);
    server.start();

    return 0;
}
