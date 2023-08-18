#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void string_freq(char message[], int n, int map[]) {
	for(int i = 0; i < n; i++)
		map[message[i] - 'a']++;
}

int main() {
	int sockfd, clientfd, struct_size, read_size;
	struct sockaddr_in server_addr, client_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("Socket creation failed");
        exit(EXIT_FAILURE);
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(8000);

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

	char message[100];
	for(int i = 0; i < 100; i++)
		message[i] = '~';
	int map[26] = {0};
		
	while ((read_size = recv(clientfd, &message, sizeof(message), 0)) > 0) {
		string_freq(message, sizeof(message) / sizeof(char), map);
		write(clientfd, &map, 26 * sizeof(int));
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