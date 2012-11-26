/*
 * User.h
 *
 *  Created on: Nov 24, 2012
 *      Author: huy
 */

#ifndef USER_H_
#define USER_H_

typedef struct User{
	struct Connection 			*connection;//head of the list of connections this user established
	struct user_info			info;

};

typedef struct user_info{
	struct user_iden			iden;
};

typedef struct user_iden{
	char*						user_id;
	char*						user_pwd;
	struct user_level			level;

};

typedef struct user_level{
	//4 level : 00: admin ; 01: premium user ; 02: registered user ; 03: unregistered user ; 04: blocked user
	unsigned int level	: 00;

};
#endif /* USER_H_ */
