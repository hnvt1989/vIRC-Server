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
//message := <prefix> <command> <content>
//delimiter (between components)        =    |
struct message
{
	struct prefix			prefix;
	struct command			command;
	struct content			content;

};


/*
 * prefix := <server name>  <channel>  <user> <time received>
 * delimiter 							=    ~
 */
struct prefix
{
	char*					server_name;
	char*					channel;
	char*					user;
	time_t					received;
};




/*
 * command := <send_code> <param_length> <param>
 * delimiter 							=    ~
 * delimiter (between param)			=   :
 */
struct command
{
	send_code				code;

	int						param_length;
	char*					param[]; //param of this command
};


typedef enum
{
	CREATE_USER_ACC,
	LOG_IN,
	LOG_OUT,

	JOIN_ROOM,
	QUIT_ROOM,

	ROOM_MSG,
	ROOM_PRIVATE_CHAT,

	PRIVATE_CHAT

}	send_code;


/*
 * The text based content of the message
 * content := <color> <style> <text>
 * delimiter 							=    ~
 *
 */
struct content
{
	char*					text;
	color					color;
	style					style;

	int						cnt;	//number of content's components
};

typedef enum{
	RED,
	BLACK,

}	color;

typedef enum
{
	BOLD,
	ITALIC,
	BOLD_ITALIC,
	REGULAR
}	style;




/* *****************************************************************************
 *                   Reply code from server to client
 * *****************************************************************************/
typedef enum
{
	/********** ERRORS ************
	 ******************************/

	INVALID_USER, 				//invalid user account , failure on verification
	INVALID_CHAN_NAME,			//invalid channel name , failure on creating channel

	CHANNEL_FULL, 				//channel is full

	MAX_CHAN_ALLOWED,			//reach the maximum of joinable channel


	/********** SUCCESS ************
	 ******************************/
	CHAN_CREATE_SUCC,			//sucessfuly created the channel
	CHAN_EXIT_SUCC,				//sucessfuly exit the channel
	INV_SENT_SUCC,				//sucessfully sent the join invitation
	INV_REFUSED,				//client declined the join invitation



}re_code;


/*
 * reply := <re_code> <prev_send_code> <time prev_code>
 * Note: upon receipt of the reply, client verify the reply with its prev request
 */
struct reply
{
	re_code					code;
	send_code				prev_scode;
	time_t					tprev_code;
};










#endif /* MESSAGE_H_ */
