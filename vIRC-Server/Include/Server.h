/*
 * Server.h
 *
 *  Created on: Nov 24, 2012
 *      Author: huy
 */

#ifndef SERVER_H_
#define SERVER_H_

typedef struct Server{
	struct server_type 		type;
	struct server_status	stat;
	struct server_info		info;
	struct Room				room_list; //point to the head of the room list
	struct Server 			*next; //point to the next server in list

};

typedef struct server_type{
	unsigned int 			is_main_server   : 0;
	unsigned int 			is_reg_server    : 0;
	unsigned int 			is_status_server : 0;
};

typedef struct server_status{
	unsigned int 			is_running	: 0;
	unsigned int 			is_busy 	: 0;
	unsigned int 			is_started : 0;
	unsigned int 			cur_connection;
	unsigned int 			cur_client;
	unsigned int 			cur_room;
};

typedef struct server_info{
	char* 					name;			//the name of the server
	unsigned int 			id;	//9 digits identification of the server
	char* 					location;		//location of this server
	unsigned int 			max_clients; //maximum number of clients the server can handle
	unsigned int 			max_connection; //maximum number of connections
	unsigned int 			max_rooms; //maximum number of room
};
#endif /* SERVER_H_ */
