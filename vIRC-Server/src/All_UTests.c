/*
 * All_UTests.c
 *
 *  Created on: Dec 6, 2012
 *      Author: huy
 */


#include "All_UTests.h"


void RunAllTests(void) {
		printf("====================== RUN TESTS ========================== \n");



        printf("************** String utilility test cases *****************\n\n");
        CuSuite* suite_StrUtil = CuSuiteNew();
        CuString *output_StrUtil = CuStringNew();
        CuSuiteAddSuite(suite_StrUtil, StrUtilGetSuite());

        CuSuiteRun(suite_StrUtil);
        CuSuiteSummary(suite_StrUtil, output_StrUtil);
        CuSuiteDetails(suite_StrUtil, output_StrUtil);
        printf("%s\n", output_StrUtil->buffer);

        printf("************** Message construction test cases **************\n\n");
        CuSuite* suite_MsgConst = CuSuiteNew();
        CuString *output_MsgConst = CuStringNew();
        CuSuiteAddSuite(suite_MsgConst, MsgConstrGetSuite());

        CuSuiteRun(suite_MsgConst);
        CuSuiteSummary(suite_MsgConst, output_MsgConst);
        CuSuiteDetails(suite_MsgConst, output_MsgConst);
        printf("%s\n", output_MsgConst->buffer);
        printf("=================== END OF TESTS ========================== \n");

}

