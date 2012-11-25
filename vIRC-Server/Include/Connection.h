/*
 * Connection.h
 *
 *  Created on: Nov 24, 2012
 *      Author: huy
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_

typedef struct Connection{
	struct Connection			*next; //next connection
	struct User					*owner;//owner of this connection
	struct Client				*client;//the client this connection resides on

};


#endif /* CONNECTION_H_ */
