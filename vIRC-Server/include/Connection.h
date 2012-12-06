/*
 * Connection.h
 *
 *  Created on: Nov 24, 2012
 *      Author: huy
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <stdlib.h>
#include <Utilities.h>

/*
 * Structure Connection resembles physical connection from the client.
 * A client can have more than one Connection to the Server
 * Each chat room the user join is a
 */
struct Connecton {
	struct Connection			*next; //next connection
	struct User					*owner;//owner of this connection
	struct Client				*client;//the client this connection resides on

	struct sockaddr_in 			*connection_addr;//
};

/*
 * Session is from the time the client intialized the first connection until the last connection to the server
 * ended.
 *
 */
struct Session
{
	time_t						begin; //session is initialized
	time_t						end;//session is ended

	int							conn_cnt;//total of the connection this session has

};

void *conn_handler (void *vargp);
void echo(int connfd, unsigned int thread_id);

#endif /* CONNECTION_H_ */
