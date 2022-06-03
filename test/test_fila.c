#include <stdbool.h>
#include <stdio.h>

#include "../src/lib/fila.h"
#include "./framework/CuTest.h"
#include "./global_tests.h"

void test_new_queue_sh(CuTest *tc)
{
    priorityQueue *fila = newPriorityQueue();
    CuAssertPtrNotNullMsg(tc,"Error, não foi possível cirar a fila com linked list.",fila);
}

void test_enqueue_sh(CuTest *tc)
{
    priorityQueue *fila = newPriorityQueue();
    enqueue_sh(fila,10,1);
    CuAssertIntEquals_Msg(tc,"Error, valor inesperado para valor na fila com linked list.",10,fila->head->value);
}

void test_enqueue_sh_multiple(CuTest *tc)
{
    priorityQueue *fila = newPriorityQueue();
    enqueue_sh(fila,10,10);
    enqueue_sh(fila,24,2);
    enqueue_sh(fila,3,3);
    CuAssertIntEquals_Msg(tc,"Error, valor inesperado para valor na fila com linked list.",10,fila->head->value);
}

void test_dequeue_sh(CuTest *tc)
{
    priorityQueue *fila = newPriorityQueue();
    enqueue_sh(fila,10,1);
    CuAssertIntEquals_Msg(tc,"Error, valor inesperado para valor na fila com linked list.",10,dequeue_sh(fila)->value);

}

void test_new_heap(CuTest *tc)
{
    heapQueue *heap = newHeapQueue();
    CuAssertPtrNotNullMsg(tc,"Error, não foi possível cirar a fila com heap.",heap);
}

CuSuite *Test_Fila_Sh()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite,test_new_queue_sh);
    SUITE_ADD_TEST(suite,test_enqueue_sh);
    SUITE_ADD_TEST(suite,test_dequeue_sh);
    SUITE_ADD_TEST(suite,test_enqueue_sh_multiple);
    SUITE_ADD_TEST(suite,test_new_heap);
    return suite;
}

void test_fila_run()
{

    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite,Test_Fila_Sh());

    CuSuiteRun(suite);
    CuSuiteSummary(suite,output);
    CuSuiteDetails(suite,output);
    printf("%s\n",output->buffer);

}