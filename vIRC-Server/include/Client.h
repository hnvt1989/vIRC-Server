/*
 * Client.h
 *
 *  Created on: Nov 24, 2012
 *      Author: huy
 *
 *  Client is the specific client (the host client), client structure contains connection information, the specific user on this client,
 *
 */

#ifndef CLIENT_H_
#define CLIENT_H_

typedef struct{
	struct Connection			*connection; //point to the head of the connections that this client established
	struct User					*users;		//point to the head of users that resides on this client
	struct client_info			*info;

} Client;

typedef struct {
	struct platform_info		*platform;
	char*						ip_addr;//char* for now
	char*						location; //char* for now
} client_info;

typedef struct{
	char*						comp_name;
	char*						owner;
	char*						description;
} platform_info;
#endif /* CLIENT_H_ */
