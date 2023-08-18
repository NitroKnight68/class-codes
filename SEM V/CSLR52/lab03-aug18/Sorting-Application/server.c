#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void bubble_sort(int nums[], int n) {
	for (int i = 0; i <  n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (nums[j] > nums[j + 1]) {
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
}

int main() {
	int sockfd, clientfd, struct_size, read_size;
	struct sockaddr_in server_addr, client_addr;

	// Create socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("Socket creation failed");
        exit(EXIT_FAILURE);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(8010);

	if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		perror("Bind failed");
		exit(EXIT_FAILURE);
	}

	listen(sockfd, 3);

	printf("Waiting for incoming connections...\n");
	struct_size = sizeof(struct sockaddr_in);

	clientfd = accept(sockfd, (struct sockaddr*)&client_addr, (socklen_t*)&struct_size);

	if (clientfd < 0) {
		perror("Accept failed");
		exit(EXIT_FAILURE);
	}

	printf("Connection accepted\n");

	int message[10000];
	for(int i = 0; i < 10000; i++)
		message[i] = 10000;
		
	while ((read_size = recv(clientfd, &message, sizeof(message), 0)) > 0) {
		bubble_sort(message, sizeof(message) / sizeof(int));
		write(clientfd, &message, sizeof(message));
	}

	if (read_size == 0)
		printf("Client disconnected\n");
	else if (read_size == -1) {
		perror("Message receive failed");
		exit(EXIT_FAILURE);
	}

    close(sockfd);
	return 0;
}