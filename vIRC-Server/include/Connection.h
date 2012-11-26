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


typedef struct {
	struct Connection			*next; //next connection
	struct User					*owner;//owner of this connection
	struct Client				*client;//the client this connection resides on

} Connection;

void *conn_handler (void *vargp);
void echo(int connfd);

#endif /* CONNECTION_H_ */
