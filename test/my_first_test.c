#include "../src/lib/lib_test.h"
#include "./framework/CuTest.h"

void test_helloworld(CuTest *tc)
{
    int resp = helloworld();
    int expected = 42;
    CuAssertIntEquals_Msg(tc,"Error, valor inesperado em helloworld.",expected,resp);
}

CuSuite *BasicSuite()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite,test_helloworld);
    return suite;
}

void testRun()
{
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite,BasicSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite,output);
    CuSuiteDetails(suite,output);
    printf("%s\n",output->buffer);
}