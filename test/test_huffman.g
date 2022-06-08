#include <stdbool.h>
#include <stdio.h>

#include "../src/huffman/helpers.h"
#include "./framework/CuTest.h"
#include "./global_tests.h"

void test_new_queue(CuTest *tc)
{
    binaryheapQueue *heap = newBinaryQueue();
    CuAssertPtrNotNullMsg(tc,"Error, não foi possível cirar a fila com heap.",heap);
}


void test_enqueue(CuTest *tc)
{
    binaryheapQueue *heap = newBinaryQueue();
    binary_enqueue(heap,10,NULL);
    CuAssertIntEquals_Msg(tc,"Error, heap queue valor inesperado.",10,item_of(heap,1));
}

void test_enqueue_multiple(CuTest *tc)
{
    binaryheapQueue *heap = newBinaryQueue();
    binary_enqueue(heap,1,NULL);
    binary_enqueue(heap,3,NULL);
    binary_enqueue(heap,2,NULL);
    CuAssertIntEquals_Msg(tc,"Error, heap queue produziu um resultado inesperado.",3,heap->data[1]);
}

void test_dequeue_multiple(CuTest *tc)
{
    binaryheapQueue *heap = newBinaryQueue();
    binary_enqueue(heap,1,NULL);
    binary_enqueue(heap,3,NULL);
    binary_enqueue(heap,2,NULL);
    binary_enqueue(heap,4,NULL);
    binary_enqueue(heap,5,NULL);

    int resp = binary_dequeue(heap);

    CuAssertIntEquals_Msg(tc,"Error, heap queue produziu um resultado inesperado.",5,resp);
}


CuSuite *Test_Huffman()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite,test_new_queue);
    SUITE_ADD_TEST(suite,test_enqueue);
    SUITE_ADD_TEST(suite,test_enqueue_multiple);
    SUITE_ADD_TEST(suite,test_dequeue_multiple);
    return suite;
}


void test_huffman_run()
{

    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite,Test_Huffman());

    CuSuiteRun(suite);
    CuSuiteSummary(suite,output);
    CuSuiteDetails(suite,output);
    printf("%s\n",output->buffer);
}