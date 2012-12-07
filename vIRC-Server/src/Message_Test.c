/*
 * Message_Test.c
 *
 *  Created on: Dec 6, 2012
 *      Author: huy
 */

#include "Message_Test.h"

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
	//input: 	Server 1 ~ Channel A ~ huy2 ~ 242423 | ROOM_MSG  ~ 1 ~ All | RED ~ BOLD ~ Wassup room
	//expect:	Server 1 ~ Channel A ~ huy2 ~ 242423  ROOM_MSG  ~ 1 ~ All  RED ~ BOLD ~ Wassup room
    void TestStrSplit_Case1(CuTest *tc) {
        char* input = strdup("Server 1 ~ Channel A ~ huy2 ~ 242423 | ROOM_MSG  ~ 1 ~ All | RED ~ BOLD ~ Wassup room");
        char** output = str_split(input, '|');
        char* actual = malloc(strlen(input));

        size_t idx;
        for(idx = 0; *(output + idx) != NULL; idx++){
        	actual = strcat(actual,*(output + idx));
        }

        char* expected = "Server 1 ~ Channel A ~ huy2 ~ 242423  ROOM_MSG  ~ 1 ~ All  RED ~ BOLD ~ Wassup room";
        //printf("actual = %s \n", actual);

        CuAssertStrEquals(tc, expected, actual);

    }

    //input:	Server 1 ~ Channel A ~ huy2 ~ 242423
    //expect:	Server 1  Channel A  huy2  242423
    void TestStrSplit_Case2(CuTest *tc) {
        char* input = strdup("Server 1 ~ Channel A ~ huy2 ~ 242423");
        char** output = str_split(input, '~');
        char* actual = malloc(strlen(input));

        size_t idx;
        for(idx = 0; *(output + idx) != NULL; idx++){
        	actual = strcat(actual,*(output + idx));
        }

        char* expected = "Server 1  Channel A  huy2  242423";
        //printf("actual = %s \n", actual);

        CuAssertStrEquals(tc, expected, actual);

    }

    //input:	CREATE_USER_ACC  ~ 2 ~ huy2 : pwd1234
    //expect:	CREATE_USER_ACC   2  huy2 : pwd1234
    void TestStrSplit_Case3(CuTest *tc) {
        char* input = strdup("CREATE_USER_ACC  ~ 2 ~ huy2 : pwd1234");
        char** output = str_split(input, '~');
        char* actual = malloc(strlen(input));

        size_t idx;
        for(idx = 0; *(output + idx) != NULL; idx++){
        	actual = strcat(actual,*(output + idx));
        }

        char* expected = "CREATE_USER_ACC   2  huy2 : pwd1234";
        printf("actual = %s \n", actual);

        CuAssertStrEquals(tc, expected, actual);

    }

    //input:	huy2 : pwd1234
    //expect:	huy2  pwd1234
    void TestStrSplit_Case4(CuTest *tc) {
        char* input = strdup("huy2 : pwd1234");
        char** output = str_split(input, ':');
        char* actual = malloc(strlen(input));

        size_t idx;
        for(idx = 0; *(output + idx) != NULL; idx++){
        	actual = strcat(actual,*(output + idx));
        }

        char* expected = "huy2  pwd1234";
        printf("actual = %s \n", actual);

        CuAssertStrEquals(tc, expected, actual);

    }

    CuSuite* StrUtilGetSuite() {
        CuSuite* suite = CuSuiteNew();
        SUITE_ADD_TEST(suite, TestStrSplit_Case1);
        SUITE_ADD_TEST(suite, TestStrSplit_Case2);
        SUITE_ADD_TEST(suite, TestStrSplit_Case3);
        SUITE_ADD_TEST(suite, TestStrSplit_Case4);
        return suite;
    }
