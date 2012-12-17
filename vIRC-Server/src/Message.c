/*
 * Message.c
 *
 *  Created on: Dec 6, 2012
 *      Author: huy
 */


#include "Message.h"

/********* structure construction *******/
struct message*	create_msg(const char* str){

}


struct prefix*	create_prefix(const char* str){
	char* string = strdup(str);
	string = trim(string);
	struct prefix* pre = (struct prefix*) malloc(sizeof(struct prefix));

	char** output = str_split(string, '~');

    char* server_name = *(output + 0);
    server_name = trim(server_name);

    char* channel = *(output + 1);
    channel = trim(channel);

    char* user = *(output + 2);
    user = trim(user);

    //time is auto generated at server end

    time_t time_received;
    time_received = time (NULL);

    //check server_name, channel and user (?)
    pre->server_name = server_name;
    pre->channel = channel;
    pre->user = user;
    pre->received = time_received;

	return pre;
}

/*
 * command := <send_code> <param_length> <param>
 * delimiter 							=    ~
 * delimiter (between param)			=   :
 */
struct command*	create_command(const char* str){
	char* string = strdup(str);
	string = trim(string);
	struct command* cmd = (struct command*) malloc(sizeof(struct command));
	char** output = str_split(string, '~');

	//getting the send_code entry from send_code tables
    char* sd_str = *(output + 0);
    struct sc_struct *sc_entry = find_sc(trim(sd_str));
    int sd =  sc_entry->value;

    //getting param length
    char* param_ln_str = *(output + 1);
    int param_ln = atoi(trim(param_ln_str));

    //geting param string
    char* pl_str = *(output + 2);
    pl_str = trim(pl_str);

    char** pl   = (char**)malloc(sizeof(char* ) * param_ln);
    if(!pl){
    	printf("Error: malloc %s\n", strerror(errno));
    	return NULL;
    }
    char** pl_tmp =	str_split(pl_str, ':');

    int i;
    for(i = 0; i < param_ln ; i++){
    	*(pl + i) = trim(*(pl_tmp + i));
    }

    //assigning value for the returning command struct
    cmd->code = sd;
    cmd->param_length = param_ln;
    cmd->param = (char**)malloc(sizeof(char*) * param_ln);
    if (!(cmd->param)){
    	printf("Error: malloc %s\n", strerror(errno));
    	return NULL;
    }
    cmd->param = pl;

	return cmd;
}
struct content* create_content(const char* str){
	char* string = strdup(str);
	string = trim(string);
	return NULL;
}

/************ validation ************/
bool is_valid_msg(struct message* msg){
	return false;
}
bool is_valid_prefix(struct prefix* pre)
{
	return false;
}
bool is_valid_content(struct content* cont){
	return false;
}

/*********** enum table utility *************/
void add_sc(struct sc_struct *s){
    HASH_ADD_STR( send_codes, key, s );
}

struct sc_struct *find_sc(char* id) {
    struct sc_struct *s;

    HASH_FIND_STR(send_codes , id, s );
    return s;
}

/** for security reason, the value of the send_code table are hard coded **/
void build_sc_tabl()
{
	struct sc_struct *tmp;
	if (!strcpy(tmp->value, "CREATE_USER_ACC")){
		printf("Error in build_sc_tabl \n");
		return;
	}
	tmp->value = 0;
	add_sc(tmp);

	if (!strcpy(tmp->value, "LOG_IN")){
		printf("Error in build_sc_tabl \n");
		return;
	}
	tmp->value = 1;
	add_sc(tmp);
}




/*************** string utlities ****************
 **********************************************/


//split the string, return char* to array of ptr to literal string
char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_delim = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_delim = tmp;
        }
        tmp++;
    }

    /* Add space for trailing (end) token. */
    count += last_delim < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, &a_delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, &a_delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}


//trim left
char *ltrim(char *s)
{
	if (!s)
		return NULL;   // handle NULL string
	if (!*s)
		return s;      // handle empty string
    while(isspace(*s)) s++;
    return s;
}

//trim right
char *rtrim(char *s)
{
	if (!s)
		return NULL;   // handle NULL string
	if (!*s)
		return s;      // handle empty string

    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

//trim left and right
char *trim(char *s)
{
	if (!s)
		return NULL;   // handle NULL string
	if (!*s)
		return s;      // handle empty string
    return rtrim(ltrim(s));
}
