/*
 * Connection.c
 *
 *  Created on: Nov 24, 2012
 *      Author: huy
 */
#include "Connection.h"

/*
 * connection handler as a thread for each connection
 * */
void *conn_handler (void *vargp){
    int connfd = *((int *)vargp);
    Pthread_detach(pthread_self()); //line:conc:echoservert:detach
    Free(vargp);                    //line:conc:echoservert:free
    echo(connfd);
    Close(connfd);
    return NULL;
}

void echo(int connfd)
{
    size_t n;
    char buf[MAXLINE];
    rio_t rio;

    Rio_readinitb(&rio, connfd);
    while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) { //line:netp:echo:eof
		printf("server received %d bytes\n", n);
		Rio_writen(connfd, buf, n);
    }
}
