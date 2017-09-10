#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <time.h>
//#include <sys/types.h>

#define BUFF_SIZE 512
#define LISTEN_PORT 1099
#define LISTEN_NUM 10 


int main(int argc, char * argv[])
{
	int listen_fd = 0;
	int conn_fd = 0;
	time_t ticks;
	struct sockaddr_in  server_addr;

	/*
 	 * On stack
         */
	//char send_buffer[BUFF_SIZE];
	//char recv_buffer[BUFF_SIZE];

	/* Socket 
	 */
	listen_fd = socket(AF_INET, SOCK_STREAM, 0);

	/*
         * On heap
	 */
	char * send_buffer = (char*)malloc(BUFF_SIZE);
	char * recv_buffer = (char*)malloc(BUFF_SIZE);

	/*
	 * init buffer 
	 * 
	*/
	bzero(send_buffer, BUFF_SIZE);
	bzero(recv_buffer, BUFF_SIZE);
	
	/*
	 * init socket address  with a structure
	*/
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(LISTEN_PORT);
	/*
	 * Bind the addrsss to scoket with Port
	*/
	bind(listen_fd, (struct sockaddr*)&server_addr, sizeof server_addr);
	
	/* 
	 * Listen the port witch bind before 
	 */
	listen(listen_fd, LISTEN_NUM);


	while (1){
		conn_fd= accept(listen_fd, (struct sockaddr*)NULL, NULL);
		int read_len = read(conn_fd, recv_buffer, BUFF_SIZE);
		if (read_len > 0)
			puts(recv_buffer);
		ticks = time(NULL);
		snprintf(send_buffer, sizeof send_buffer, "%.24s", ctime(&ticks));
		write(conn_fd, send_buffer, strlen(send_buffer));
		close(conn_fd);
		sleep(1);
	}
	/*
	 * Free memory
	 */
	free(send_buffer);
	free(recv_buffer);

	return 0;

}
