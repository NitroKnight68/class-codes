#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>

int client_num = 0;
int sockfds[5];
pthread_t threads[5];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *client_util(void *arg) {
    int fd1 = *((int *)arg);
    char buf[256];

    while (1) {
        // Receives number of bytes from Socket
        int bytes_num = recv(fd1, buf, sizeof(buf), 0);
        
        // Removes client if it fails, skips to the next working client
        if (bytes_num <= 0) {
            pthread_mutex_lock(&mutex);
            for (int i = 0; i < client_num; i++) {
                if (sockfds[i] == fd1) {
                    client_num--;
                    for (int j = i; j < client_num; j++) {
                        sockfds[j] = sockfds[j + 1];
                    }
                    break;
                }
            }

            //Closes the failed connection
            pthread_mutex_unlock(&mutex);
            close(fd1);
            pthread_exit(NULL);
        }

        // Prints the valid message
        buf[bytes_num] = '\0';
        printf("Received: %s", buf);

        // Sends the address to Bind function
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < client_num; i++) {
            if (sockfds[i] != fd1) {
                send(sockfds[i], buf, bytes_num, 0);
            }
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main() { 
    int sockfd;
    struct sockaddr_in sa;

    // Creates a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialises the socket
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = INADDR_ANY;
    sa.sin_port = htons(8080);


    // Checks if port is binded 
    if (bind(sockfd, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Checks if there are more than 5 clients
    if (listen(sockfd, 5) == -1) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", 8080);


    while (1) {
        if (client_num < 5) {

            // Accepts connection and opens new socket
            int fd1 = accept(sockfd, NULL, NULL);
            if (fd1 == -1) {
                perror("Accepting connection failed");
                continue;
            }

            // Increments number of clients for a valid client
            pthread_mutex_lock(&mutex);
            sockfds[client_num] = fd1;
            client_num++;
            pthread_mutex_unlock(&mutex);

            // Creates the Pthreads and connects with the clients
            pthread_create(&threads[client_num - 1], NULL, client_util, &fd1);
        }
    }

    // Closes the server socket
    close(sockfd);
    return 0;
}
