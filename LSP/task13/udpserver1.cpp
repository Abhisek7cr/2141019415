#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int sockfd;
    struct sockaddr_in servaddr{}, clientaddr{};
    socklen_t len = sizeof(clientaddr);
    char buffer[1024];

   
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

   
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(0);  

   
    if (::bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        return 1;
    }

   
    if (getsockname(sockfd, (struct sockaddr*)&servaddr, &len) == 0) {
        std::cout << "After bind, ephemeral port: " << ntohs(servaddr.sin_port) << std::endl;
    } else {
        perror("getsockname failed");
        close(sockfd);
        return 1;
    }

   
    int receivedNumber;
    if (recvfrom(sockfd, &receivedNumber, sizeof(receivedNumber), 0,
                 (struct sockaddr*)&clientaddr, &len) < 0) {
        perror("recvfrom failed");
        close(sockfd);
        return 1;
    }

    std::cout << "\nClient sent: " << receivedNumber << std::endl;

    
    std::cout << "\nEnter a string to send to client: ";
    std::cin.ignore();  
    std::cin.getline(buffer, sizeof(buffer));

    
    if (sendto(sockfd, buffer, strlen(buffer), 0,
               (struct sockaddr*)&clientaddr, len) < 0) {
        perror("sendto failed");
    }

    close(sockfd);
    return 0;
}
