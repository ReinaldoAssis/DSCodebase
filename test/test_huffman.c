#include <stdbool.h>
#include <stdio.h>

#include "../src/huffman/priorityQ.h"
#include "./framework/CuTest.h"
#include "./global_tests.h"
#include "../src/huffman/helpers.h"

void test_new_queue(CuTest *tc)
{
    huffheapQueue *heap = newHuffQueue();
    CuAssertPtrNotNullMsg(tc,"Error, não foi possível cirar a fila com heap.",heap);
}

void test_swap(CuTest *tc)
{
    hufftree_node *a = newHeapNode('R',1);
    hufftree_node *b = newHeapNode('C',1);
    
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

void test_dequeue_multiple(CuTest *tc)
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
    CuAssertIntEquals_Msg(tc,"Error, heap queue valor inesperado.",'A',huff_dequeue(heap)->value);
    CuAssertIntEquals_Msg(tc,"Error, heap queue valor inesperado.",'B',huff_dequeue(heap)->value);
    CuAssertIntEquals_Msg(tc,"Error, heap queue valor inesperado.",'C',huff_dequeue(heap)->value);
    CuAssertIntEquals_Msg(tc,"Error, heap queue valor inesperado.",'D',huff_dequeue(heap)->value);
    CuAssertIntEquals_Msg(tc,"Error, heap queue valor inesperado.",'E',huff_dequeue(heap)->value);
    CuAssertIntEquals_Msg(tc,"Error, heap queue valor inesperado.",'F',huff_dequeue(heap)->value);
    CuAssertIntEquals_Msg(tc,"Error, heap queue valor inesperado.",'G',huff_dequeue(heap)->value);
    CuAssertIntEquals_Msg(tc,"Error, heap queue valor inesperado.",'H',huff_dequeue(heap)->value);


}

void test_hashtable(CuTest *tc)
{
    hashtable *tb = newhashtable();
    put_hashtable(tb,'R',0,'0',0);
    put_hashtable(tb,'E',0,'0',0);
    put_hashtable(tb,'I',0,'0',0);
    
    //print_hashtable(tb);
    CuAssertIntEquals_Msg(tc,"Error, hashtable valor inesperado.",0,get_hashtable(tb,'E')->level);
}


CuSuite *Test_Huffman()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite,test_new_queue);
    SUITE_ADD_TEST(suite,test_swap);
    SUITE_ADD_TEST(suite,test_enqueue);
    SUITE_ADD_TEST(suite,test_hashtable);
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