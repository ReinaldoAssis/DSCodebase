#include <stdbool.h>
#include <stdio.h>

#include "../src/huffman/priorityQ.h"
#include "./framework/CuTest.h"
#include "./global_tests.h"

void test_new_queue(CuTest *tc)
{
    huffheapQueue *heap = newHuffQueue();
    CuAssertPtrNotNullMsg(tc,"Error, não foi possível cirar a fila com heap.",heap);
}

void test_swap(CuTest *tc)
{
    heapq_node *a = newHeapNode('R',1);
    heapq_node *b = newHeapNode('C',1);
    
    swap(&a,&b);
    CuAssertIntEquals(tc,'R',b->value);
}

void test_enqueue(CuTest *tc)
{
    huffheapQueue *heap = newHuffQueue();
    
    huff_enqueue(heap,'C',3);
    huff_enqueue(heap,'E',5);
    huff_enqueue(heap,'D',4);
    huff_enqueue(heap,'G',7);
    huff_enqueue(heap,'A',1);
    huff_enqueue(heap,'B',2);
    huff_enqueue(heap,'F',6);
    huff_enqueue(heap,'H',8);


    // printf("Deq da heap\n");
    // for(int i=1; i<=heap->size-1; i++)
    //     printf("%c ",huff_dequeue(heap)->value);
    // printf("\n");

    CuAssertIntEquals_Msg(tc,"Error, heap queue valor inesperado.",'A',huff_item_of(heap,1)->value);
}

// void test_enqueue_multiple(CuTest *tc)
// {
//     binaryheapQueue *heap = newBinaryQueue();
//     binary_enqueue(heap,1,NULL);
//     binary_enqueue(heap,3,NULL);
//     binary_enqueue(heap,2,NULL);
//     CuAssertIntEquals_Msg(tc,"Error, heap queue produziu um resultado inesperado.",3,heap->data[1]);
// }

// void test_dequeue_multiple(CuTest *tc)
// {
//     binaryheapQueue *heap = newBinaryQueue();
//     binary_enqueue(heap,1,NULL);
//     binary_enqueue(heap,3,NULL);
//     binary_enqueue(heap,2,NULL);
//     binary_enqueue(heap,4,NULL);
//     binary_enqueue(heap,5,NULL);

//     int resp = binary_dequeue(heap);

//     CuAssertIntEquals_Msg(tc,"Error, heap queue produziu um resultado inesperado.",5,resp);
// }


CuSuite *Test_Huffman()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite,test_new_queue);
    SUITE_ADD_TEST(suite,test_swap);
    SUITE_ADD_TEST(suite,test_enqueue);
    //SUITE_ADD_TEST(suite,test_enqueue_multiple);
    //SUITE_ADD_TEST(suite,test_dequeue_multiple);
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