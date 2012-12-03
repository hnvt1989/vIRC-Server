/*
 * Message.h
 *
 *  Created on: Dec 2, 2012
 *      Author: huy
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_


//communication mesage between server and client
//message encapsulation by checking a byte at a time
struct Message
{
	//credentials
	message_type 			type;
	struct User 			user;


	char* 					content;
	struct DateTime			datetime;
	time_t 					time;

};

typedef enum
{
	CREATE_USER_ACC,
	JOIN_ROOM,
	QUIT_ROOM,

	ROOM_MSG,
	ROOM_PRIVATE_CHAT,

	PRIVATE_CHAT

}message_type;

struct Content
{
	int						room_num;
	char*					message;
};
#endif /* MESSAGE_H_ */
