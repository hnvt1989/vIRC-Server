/*
 * Message_Test.c
 *
 *  Created on: Dec 6, 2012
 *      Author: huy
 */

#include "Message_Test.h"
#include <stdlib.h>
/*
 * message := <prefix> <command> <content>
 * delimiter (between components)        =    |
 * -----------------
 * prefix := <server name>  <channel>  <user> <time received>
 * delimiter           					=    ~
 * -----------------
 * command := <send_code> <param_length> <param>
 * delimiter 							=    ~
 * delimiter (between param)			=   :
 * -----------------
 * content := <color> <style> <text>
 * delimiter 							=    ~
 * ----------------
 */


/*********************************  Begin of String Ultility Test cases ****************************/

	//input: 	Server 1 ~ Channel A ~ huy2 ~ 242423 | ROOM_MSG  ~ 1 ~ All | RED ~ BOLD ~ Wassup room
	//expect:	Server 1 ~ Channel A ~ huy2 ~ 242423  ROOM_MSG  ~ 1 ~ All  RED ~ BOLD ~ Wassup room
    void TestStrSplit_Case1(CuTest *tc) {
        char* input = strdup("Server 1 ~ Channel A ~ huy2 ~ 242423 | ROOM_MSG  ~ 1 ~ All | RED ~ BOLD ~ Wassup room");
        char* actual = (char*) malloc(sizeof(char) * (strlen(input) + 1));
        char** output = str_split(input, '|');


        size_t idx;
        for(idx = 0; *(output + idx) != NULL; idx++){
        	actual = strcat(actual,*(output + idx));
        }
        char* expected = "Server 1 ~ Channel A ~ huy2 ~ 242423  ROOM_MSG  ~ 1 ~ All  RED ~ BOLD ~ Wassup room";
        //printf("actual = %s \n", actual);

        CuAssertStrEquals(tc, expected, actual);
        free(actual);
    }

    //input:	Server 1 ~ Channel A ~ huy2 ~ 242423
    //expect:	Server 1  Channel A  huy2  242423
    void TestStrSplit_Case2(CuTest *tc) {
        char* input = strdup("Server 1 ~ Channel A ~ huy2 ~ 242423");
        char* actual = (char*) malloc(sizeof(char) * (strlen(input) + 1));
        char** output = str_split(input, '~');


        size_t idx;
        for(idx = 0; *(output + idx) != NULL; idx++){
        	actual = strcat(actual,*(output + idx));
        }

        char* expected = "Server 1  Channel A  huy2  242423";
        //printf("actual = %s \n", actual);

        CuAssertStrEquals(tc, expected, actual);
        free(actual);
    }

    //input:	CREATE_USER_ACC  ~ 2 ~ huy2 : pwd1234
    //expect:	CREATE_USER_ACC   2  huy2 : pwd1234
    void TestStrSplit_Case3(CuTest *tc) {
        char* input = strdup("CREATE_USER_ACC  ~ 2 ~ huy2 : pwd1234");
        char* actual = (char*) malloc(sizeof(char) * (strlen(input) + 1));
        char** output = str_split(input, '~');


        size_t idx;
        for(idx = 0; *(output + idx) != NULL; idx++){
        	actual = strcat(actual,*(output + idx));
        }

        char* expected = "CREATE_USER_ACC   2  huy2 : pwd1234";
        //printf("actual = %s \n", actual);

        CuAssertStrEquals(tc, expected, actual);
        free(actual);
    }

    //input:	huy2 : pwd1234
    //expect:	huy2  pwd1234
    void TestStrSplit_Case4(CuTest *tc) {
        char* input = strdup("huy2 : pwd1234");
        char* actual = (char*) malloc(sizeof(char) * (strlen(input) + 1));
        char** output = str_split(input, ':');

        size_t idx;
        for(idx = 0; *(output + idx) != NULL; idx++){
        	actual = strcat(actual,*(output + idx));
        }

        char* expected = "huy2  pwd1234";
        //printf("actual = %s \n", actual);

        CuAssertStrEquals(tc, expected, actual);
        free(actual);

    }

    //input:   [  huy2  age4 ]
    //expect:  [huy2age4]
   void TestTrim(CuTest *tc){
	   char* input = strdup("   huy2  age4  ");
	   char* actual = trim(input);
	   char* expected =  "huy2  age4";

	   //printf("actual = %s \n", actual);
	   CuAssertStrEquals(tc, expected, actual);
   }


    CuSuite* StrUtilGetSuite() {
        CuSuite* suite = CuSuiteNew();

        SUITE_ADD_TEST(suite, TestStrSplit_Case1);
        SUITE_ADD_TEST(suite, TestStrSplit_Case2);
        SUITE_ADD_TEST(suite, TestStrSplit_Case3);
        SUITE_ADD_TEST(suite, TestStrSplit_Case4);

        SUITE_ADD_TEST(suite, TestTrim);

        return suite;
    }

    /*********************************  End of String Ultility Test cases ****************************/


    /*********************************  Begin of Message Construction Test cases ****************************/

    //input:	" Server 1 ~ Channel A ~ huy2 ~ 242423 "
    //output:	struct pref	:	server_name = Server 1
    //							channel		= Channel A
    //							user		= huy2
    void TestPreConstr_Case1(CuTest *tc)
    {
    	char* input = strdup(" Server 1 ~ Channel A ~ huy2 ~ 242423 ");
    	struct prefix* pref = create_prefix(input);

    	char* exp_server_name = "Server 1";
    	char* exp_channel = "Channel A";
    	char* exp_user = "huy2";

    	CuAssertStrEquals(tc, exp_server_name, pref->server_name);
    	CuAssertStrEquals(tc, exp_channel, pref->channel);
    	CuAssertStrEquals(tc, exp_user, pref->user);
    }


    //input:	" ROOM_MSG  ~ 2 ~ All : Hey "
    //output:	struct cmd : send_code = LOG_IN
    //						 param_length = 2
    //						 param list = All
    //									  Hey
    void TestCmdConstr_Case1(CuTest *tc){
    	char* input = strdup(" ROOM_MSG  ~ 2 ~ All : Hey ");
    	struct command* cmd = create_command(input);
    	if (!cmd){
        	printf("Error > TestCmdConstr_Case1 : create_command failed\n");
        	return;
    	}
    	send_code exp_sc = LOG_IN;
    	int exp_param_ln = 2;
    	char* exp_param_list[2] = { "All", "Hey"};

    	CuAssertStrEquals(tc, exp_param_list[0], *(cmd->param));
    	CuAssertStrEquals(tc, exp_param_list[1], *(cmd->param + 1));

    	CuAssertIntEquals(tc,exp_param_ln,cmd->param_length);

    	CuAssertIntEquals(tc,(int)exp_sc,(int)(cmd->code)); //failed here
    }
    void TestContentConstr_Case1(CuTest *tc){

    }




    CuSuite* MsgConstrGetSuite() {
        CuSuite* suite = CuSuiteNew();

        SUITE_ADD_TEST(suite, TestPreConstr_Case1);
        SUITE_ADD_TEST(suite, TestCmdConstr_Case1);
        //SUITE_ADD_TEST(suite, TestContentConstr_Case1);

        return suite;
    }

    /*********************************  End of Message Construction Test cases ****************************/
