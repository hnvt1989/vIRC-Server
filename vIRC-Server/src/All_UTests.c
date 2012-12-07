/*
 * All_UTests.c
 *
 *  Created on: Dec 6, 2012
 *      Author: huy
 */


#include "All_UTests.h"


void RunAllTests(void) {
		printf("====================== RUN TESTS ========================== \n");
		printf("String utilility test cases \n\n");
        CuString *output_StrUtil = CuStringNew();
        CuSuite* suite_StrUtil = CuSuiteNew();

        CuSuiteAddSuite(suite_StrUtil, StrUtilGetSuite());

        CuSuiteRun(suite_StrUtil);
        CuSuiteSummary(suite_StrUtil, output_StrUtil);
        CuSuiteDetails(suite_StrUtil, output_StrUtil);
        printf("%s\n", *output_StrUtil->buffer);
        printf("=================== END OF TESTS ========================== \n");

}

