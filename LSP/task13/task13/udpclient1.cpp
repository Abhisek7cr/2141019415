#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <port>" << std::endl;
        return 1;
    }

    int sockfd;
    struct sockaddr_in servaddr{};
    socklen_t len = sizeof(servaddr);
    char recvline[1024] = {0};

   
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

   
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[1]));
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

   
    int number;
    std::cout << "Give a number for server: ";
    std::cin >> number;

    if (sendto(sockfd, &number, sizeof(number), 0,
               (struct sockaddr*)&servaddr, len) < 0) {
        perror("sendto failed");
        close(sockfd);
        return 1;
    }

   
    ssize_t bytes_received = recvfrom(sockfd, recvline, sizeof(recvline) - 1, 0,
                                      (struct sockaddr*)&servaddr, &len);

    if (bytes_received < 0) {
        perror("recvfrom failed");
        close(sockfd);
        return 1;
    }

    recvline[bytes_received] = '\0'; 
    std::cout << "\nServer sent: " << recvline << std::endl;

    close(sockfd);
    return 0;
}
