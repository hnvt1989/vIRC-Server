/*
 * Message_Test.c
 *
 *  Created on: Dec 6, 2012
 *      Author: huy
 */

#include "Message_Test.h"
#include <../src/Message.c>



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
 * -----------------
 * Test 1) Server 1 ~ Channel A ~ huy2 ~ 242423 | ROOM_MSG  ~ 1 ~ All | RED ~ BOLD ~ Wassup room
 */
    void TestStrSplit(CuTest *tc) {
        char* input = strdup("Server 1 ~ Channel A ~ huy2 ~ 242423 | ROOM_MSG  ~ 1 ~ All | RED ~ BOLD ~ Wassup room");
        char** actual = str_split(input, "|");
        char* expected = "Server 1 ~ Channel A ~ huy2 ~ 242423 | ROOM_MSG  ~ 1 ~ All | RED ~ BOLD ~ Wassup room";
        CuAssertStrEquals(tc, expected, *actual);
    }

    CuSuite* StrUtilGetSuite() {
        CuSuite* suite = CuSuiteNew();
        SUITE_ADD_TEST(suite, TestStrSplit);
        return suite;
    }
