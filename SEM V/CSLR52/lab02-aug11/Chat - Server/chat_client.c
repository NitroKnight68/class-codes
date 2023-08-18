#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int sockfd;
    struct sockaddr_in server_addr;


    // Creates a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialises a socket
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    // Establishes a connection
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server.\n");

    // Recieve the message from the user
    char message[256];
    while (1) {
        printf("Enter message (or 'exit' to quit): ");
        fgets(message, sizeof(message), stdin);

        // Exits the client
        if (strcmp(message, "exit\n") == 0) {
            break;
        }
        send(sockfd, message, strlen(message), 0);
    }

    // Closes the connection
    close(sockfd);
    printf("Connection closed.\n");
    return 0;
}