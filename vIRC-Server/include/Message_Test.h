/*
 * Message_Test.h
 *
 *  Created on: Dec 6, 2012
 *      Author: huy
 */

#ifndef MESSAGE_TEST_H_
#define MESSAGE_TEST_H_
#include "CuTest.h"
#include <string.h>
#include <Message.h>


/* String Util test suite */
void TestStrSplit_Case1(CuTest *tc);
void TestStrSplit_Case2(CuTest *tc);
void TestStrSplit_Case3(CuTest *tc);
void TestStrSplit_Case4(CuTest *tc);
void TestTrim(CuTest *tc);

CuSuite* StrUtilGetSuite();

/* Message construction test suite */
void TestPreConstr_Case1(CuTest *tc);
void TestCmdConstr_Case1(CuTest *tc);
void TestContentConstr_Case1(CuTest *tc);
CuSuite* MsgConstrGetSuite();

#endif /* MESSAGE_TEST_H_ */
