/*
 * Message.c
 *
 *  Created on: Dec 6, 2012
 *      Author: huy
 */


#include "Message.h"

/********* structure construction *******/
struct message*	create_msg(char*  stream){
	int a;
	return NULL;
}
struct prefix*	create_prefix(char* stream){
	return NULL;
}
struct content* create_content(char* stream){
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

/*************** string utlities ****************
 **********************************************/
/*
 * return char pointer to array of pointers of tokens
 */
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
