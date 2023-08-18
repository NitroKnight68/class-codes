#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>

main() {
    int i, sockfd, a, b, p = 6, q = 7, r;
    char buf[100];
    struct sockaddr_in sa;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("10.1.22.132");
    sa.sin_port = 60018;

    i = connect(sockfd,(struct sockaddr *)&sa, sizeof(sa));

    for(i = 0; i < 100; i++) buf[i] = '\0';
    recv(sockfd, buf, 100, 0);
    printf("%s\n", buf);

    for(i = 0; i < 100; i++) buf[i] = '\0';
    strcpy(buf, "Message from client");
    send(sockfd, buf, 100, 0);

    close(sockfd);    
}

