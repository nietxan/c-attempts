#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define PORT 8080


int main()
{
	int opt = 1;
	ssize_t valread;
	struct sockaddr_in address;
	char buffer[1024] = {0};
	int serverfd, newsocket;
	char* hello = "HELLO FROM SERVER";
	socklen_t addrlen = sizeof(address);


	if ((serverfd = socket(AF_LOCAL, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}

	if (setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_LOCAL;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	if (bind(serverfd, (struct sockaddr*)&address, sizeof(address)) < 0) {
		perror("bind");
		exit(EXIT_FAILURE);
	}

	if (listen(serverfd, 3) < 0) {
		perror("accept");
		exit(EXIT_FAILURE);
	}

	if ((newsocket = accept(serverfd, (struct sockaddr*)&address, &addrlen)) < 0) {
		perror("accept");
		exit(EXIT_FAILURE);
	}	

	valread = read(serverfd, buffer, 1024 - 1);

	printf("%s\n", buffer);
    send(newsocket, hello, strlen(hello), 0);

	close(newsocket);
	close(serverfd);
	return 0;
}

