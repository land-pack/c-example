#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <fcntl.h>


#define LISTEN_PORT 9982
#define QUEUE 20
#define BUFFER_SIZE 1024

int main(int argc, char * argv[]){

	// declare socket file describer 
	int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

	// declare socket address struct point
	struct sockaddr_in sockaddr;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(LISTEN_PORT);
	sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	// Bind 
	if (bind(sock_fd, (struct sockaddr *) & sockaddr, sizeof(sockaddr)) == -1){
		perror("Bind");
		exit(-1);
	}

	// Listen, if success return 0 else -1
	if (listen(sock_fd, QUEUE) == -1) {
		perror("Listen");
		exit(-1);
	}

	// Client socket

	char buffer[BUFFER_SIZE];
	struct sockaddr_in client_addr;
	socklen_t length = sizeof(client_addr);

	// Return client file describer if success else -1
	int conn = accept(sock_fd, (struct sockaddr*)&client_addr, &length);

	if (conn < 0){
		perror("Connect");
		exit(-1);
	}

	while (1){
		memset(buffer, 0, sizeof(buffer));
		int len = recv(conn, buffer, sizeof(buffer), 0);
		printf(">>>>>>>>>%d\n", conn);
		if(strcmp(buffer, "exit\n") == 0 || strcmp(buffer, "")==0)
			break;

		fputs(buffer, stdout);
		send(conn, buffer, len, 0);
	}

	close(conn);
	close(sock_fd);
	return 0;

}
