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
    enqueue_sh(&fila,10,1,NULL);
    CuAssertIntEquals_Msg(tc,"Error, valor inesperado para valor na fila com linked list.",10,fila->head->value);
}

void test_enqueue_sh_multiple(CuTest *tc)
{
    priorityQueue *fila = newPriorityQueue();
    enqueue_sh(&fila,10,10,NULL);
    enqueue_sh(&fila,3,3,NULL);
    enqueue_sh(&fila,24,20,NULL);
    CuAssertIntEquals_Msg(tc,"Error, valor inesperado para valor na fila com linked list.",24,fila->head->value);
}

void test_dequeue_sh(CuTest *tc)
{
    priorityQueue *fila = newPriorityQueue();
    enqueue_sh(&fila,10,1,NULL);
    CuAssertIntEquals_Msg(tc,"Error, valor inesperado para valor na fila com linked list.",10,dequeue_sh(fila)->value);

}

void test_new_heap(CuTest *tc)
{
    heapQueue *heap = newHeapQueue();
    CuAssertPtrNotNullMsg(tc,"Error, não foi possível cirar a fila com heap.",heap);
}

void test_swap(CuTest *tc)
{
    int ar[2] = {20,10};
    swap(&ar[0],&ar[1]);
    CuAssertIntEquals_Msg(tc, "Error, função swap produziu um resultado inesperado.",10,ar[0]);
}

void test_enqueue_heap(CuTest *tc)
{
    heapQueue *heap = newHeapQueue();
    enqueue_heap(heap,10,NULL);
    CuAssertIntEquals_Msg(tc,"Error, heap queue valor inesperado.",10,item_of(heap,1));
}

void test_enqueue_heap_multiple(CuTest *tc)
{
    heapQueue *heap = newHeapQueue();
    enqueue_heap(heap,1,NULL);
    enqueue_heap(heap,3,NULL);
    enqueue_heap(heap,2,NULL);
    CuAssertIntEquals_Msg(tc,"Error, heap queue produziu um resultado inesperado.",3,heap->data[1]);
}

void test_dequeue_heap_multiple(CuTest *tc)
{
    heapQueue *heap = newHeapQueue();
    enqueue_heap(heap,1,NULL);
    enqueue_heap(heap,3,NULL);
    enqueue_heap(heap,2,NULL);
    enqueue_heap(heap,4,NULL);
    enqueue_heap(heap,5,NULL);

    for(int i=0; i<=heap->size; i++)
        printf("%d(%d) ",i,heap->data[i]);

    printf("\n");

    int resp = dequeue_heap(heap);

    for(int i=0; i<=heap->size; i++)
        printf("%d(%d) ",i,heap->data[i]);

    printf("\n");

    CuAssertIntEquals_Msg(tc,"Error, heap queue produziu um resultado inesperado.",5,resp);
}


CuSuite *Test_Fila_Sh()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite,test_new_queue_sh);
    SUITE_ADD_TEST(suite,test_enqueue_sh);
    SUITE_ADD_TEST(suite,test_dequeue_sh);
    SUITE_ADD_TEST(suite,test_enqueue_sh_multiple);
    SUITE_ADD_TEST(suite,test_new_heap);
    SUITE_ADD_TEST(suite,test_enqueue_heap);
    SUITE_ADD_TEST(suite,test_swap);
    SUITE_ADD_TEST(suite,test_enqueue_heap_multiple);
    SUITE_ADD_TEST(suite,test_dequeue_heap_multiple);
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