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


void TestStrSplit_Case1(CuTest *tc);
void TestStrSplit_Case2(CuTest *tc);
void TestStrSplit_Case3(CuTest *tc);
void TestStrSplit_Case4(CuTest *tc);

CuSuite* StrUtilGetSuite();

#endif /* MESSAGE_TEST_H_ */
