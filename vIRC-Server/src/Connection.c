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
	unsigned int thread_id = pthread_self();
	printf("NET*** [ 0x%x ] *** New connection \n" , thread_id);
    int connfd = *((int *)vargp);
    Pthread_detach(pthread_self()); //line:conc:echoservert:detach
    Free(vargp);                    //free allocated descriptor in main thread to prevent memory leak
    echo(connfd, thread_id);
    Close(connfd);
    return NULL;
}

void echo(int connfd, unsigned int thread_id)
{
    size_t n;
    char buf[MAXLINE];
    rio_t rio;

    Rio_readinitb(&rio, connfd);
    while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) { //line:netp:echo:eof
		printf("NET*** [ 0x%x ] *** Received %d bytes\n", thread_id,n);
		Rio_writen(connfd, buf, n);
    }
}
