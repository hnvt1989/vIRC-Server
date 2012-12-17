/*
 * Channel.h
 *
 *  Created on: Dec 3, 2012
 *      Author: huy
 */

#ifndef CHANNEL_H_
#define CHANNEL_H_

struct chan{
	struct Server			owner_server; //the server this room belong to
	struct User				owner_user;	//the user owner of this room
	struct chan				*next;//point to the next room
};

struct chan_mode{
	unsigned int join_any		: 0; 			//anyone can join
	unsigned int join_oper		: 0; 			//only operator can join
	unsigned int join_priv		: 0;			//only privilege user can join
	unsigned int join_on_invite : 0;			//only can join upon invite
};


struct chan_stat{
	unsigned int			is_ready: 0;
	unsigned int 			is_open : 0;
	unsigned int 			cur_capacity;
	unsigned int			cur_clients; //the number of current clients
	struct chan_info		info;


};

struct chan_info{
	char* 					name;
	unsigned int 			capacity;
	struct User				owner;

};




/*
 * Action the channel operators can perform on a channel
 */
typedef enum {
	KICK, //Eject a client from the channel
	MODE, //Change the channel's mode
	INVITE, //Invite a client to an invite-only channel (mode +i)
	TOPIC //Change the channel topic in a mode +t channel
}	chanop;


#endif /* CHANNEL_H_ */
