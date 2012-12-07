/*
 * All_UTests.c
 *
 *  Created on: Dec 6, 2012
 *      Author: huy
 */


#include "Message_Test.h"
#include "CuTest.h"

CuSuite* StrUtilGetSuite();

void RunAllTests(void) {
        CuString *output = CuStringNew();
        CuSuite* suite = CuSuiteNew();

        CuSuiteAddSuite(suite, StrUtilGetSuite());

        CuSuiteRun(suite);
        CuSuiteSummary(suite, output);
        CuSuiteDetails(suite, output);
        printf("%s\n", output->buffer);
}

