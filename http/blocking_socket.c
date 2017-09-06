#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

#define BUFF_SIZE 1025
#define LISTEN_PORT 5600


int main(int argc, char * argv[])
{
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr;

    char sendBuff[BUFF_SIZE];
    time_t ticks;

    /*
     * AF_INET      : IP Version 4
     * SOCK_STREAM  : Used TCP 
     * 0            : Default protocol
     */
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(LISTEN_PORT);

    /*
     * Bind the port & address on any address
     * on the machine !
     */
    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    /*
     * Listen the bind port! for 10 connection as max!
     */
    listen(listenfd, 10);

    /*
     * Loop wait to new connection come!
     */
    while(1)
    {
        /*
         * If you wish to fetch the client-side address
         * you should declare a effective address structure
         * instead of NULL!
         */
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
        ticks = time(NULL);
        snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks));
        write(connfd, sendBuff, strlen(sendBuff));
        close(connfd);
        sleep(1);
    }
}
