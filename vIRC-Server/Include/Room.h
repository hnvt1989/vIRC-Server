/*
 * Room.h
 *
 *  Created on: Nov 24, 2012
 *      Author: huy
 */

#ifndef ROOM_H_
#define ROOM_H_

typedef struct Room{
	struct Server		owner_server; //the server this room belong to
	struct User			owner_user;	//the user owner of this room
	struct Room			*next;//point to the next room
};

typedef struct room_stat{
	unsigned int		is_ready: 0;
	unsigned int 		is_open : 0;
	unsigned int 		cur_capacity;
	unsigned int		cur_clients; //the number of current clients
	struct room_info	info;


};

typedef struct room_info{
	char* 				name;
	unsigned int 		capacity;
	struct User			owner;

};
#endif /* ROOM_H_ */
