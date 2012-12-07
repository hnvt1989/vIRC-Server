/*
 *
 * Server - Main
 */

#include <stdlib.h>
#include <Utilities.h>
#include <Connection.h>
#include <stdbool.h>
#include "test/All_UTests.c"

int main(int argc, char **argv)
{
	//test
	bool runTest = true;
	if(runTest)
		RunAllTests();

    int listenfd, *connfdp, port;
    socklen_t clientlen = sizeof(struct sockaddr_in);
    socklen_t serverlen = sizeof(struct sockaddr_in);

    struct sockaddr_in clientaddr;
    struct sockaddr_in serveraddr;

    char* server_ip_address = 0;

    pthread_t tid;

    /*
    if (argc != 2) {
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(0);
    }
    port = atoi(argv[1]);
	*/
    port = 49000;

    listenfd = Open_listenfd(port);


    while (1) {
		connfdp = Malloc(sizeof(int)); //line:conc:echoservert:beginmalloc
		*connfdp = Accept(listenfd, (SA *) &clientaddr, &clientlen); //line:conc:echoservert:endmalloc

		//filling the serveraddr socket address
		if (!server_ip_address)
		{
			//char *server_ip_address = inet_ntoa(clientaddr.sin_addr);
			if (getsockname(*connfdp, (SA *) &serveraddr, &serverlen ) == 0){
				server_ip_address = inet_ntoa(serveraddr.sin_addr);
				printf("LOG*** Server ip address %s \n", server_ip_address);
			}
		}

		Pthread_create(&tid, NULL, conn_handler, connfdp);
    }
}
