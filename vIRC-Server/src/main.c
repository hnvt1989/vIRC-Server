#include <stdlib.h>
#include <Utilities.h>
#include <Connection.h>

int main(int argc, char **argv)
{
    int listenfd, *connfdp, port;
    socklen_t clientlen=sizeof(struct sockaddr_in);
    struct sockaddr_in clientaddr;
    pthread_t tid;

    /*
    if (argc != 2) {
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(0);
    }
    port = atoi(argv[1]);
	*/
    port = 2222;
    listenfd = Open_listenfd(port);
    while (1) {
		connfdp = Malloc(sizeof(int)); //line:conc:echoservert:beginmalloc
		*connfdp = Accept(listenfd, (SA *) &clientaddr, &clientlen); //line:conc:echoservert:endmalloc
		Pthread_create(&tid, NULL, conn_handler, connfdp);
    }
}
