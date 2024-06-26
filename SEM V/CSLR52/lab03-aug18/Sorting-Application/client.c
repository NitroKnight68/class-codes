#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
	int sockfd, message_size;
	struct sockaddr_in server_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("Socket creation failed");
        exit(EXIT_FAILURE);
	}

	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(8010);

	if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		perror("Connection failed");
		exit(EXIT_FAILURE);
	}

	printf("Connected to server at port 8010\n");

    printf("Enter the size of the array: ");
    scanf("%d", &message_size);

    int server_reply[message_size], message[message_size];
    printf("Enter the elements in the array: ");
    for(int i = 0; i < message_size; i++)
        scanf("%d", &message[i]);

	if (send(sockfd, &message, message_size * sizeof(int), 0) < 0) {
		printf("Message send failed");
		exit(EXIT_FAILURE);
	}

	if (recv(sockfd, &server_reply, message_size * sizeof(int), 0) < 0) {
		printf("Message receive failed");
		exit(EXIT_FAILURE);
	}

	printf("Sorted array from server : ");
	for (int i = 0; i < message_size; i++) {
		printf("%d ", server_reply[i]);
	}
    printf("\n");

	close(sockfd);
	return 0;
}
