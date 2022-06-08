#include "helpers.h"
#include <stdbool.h>
#include <stdio.h>

binaryheapQueue* newBinaryQueue()
{
    binaryheapQueue *heap = (binaryheapQueue *) malloc(sizeof(binaryheapQueue));
    heap->size = 0;
    return heap;
}

int binary_get_parent_index(binaryheapQueue *heap, int i)
{
    return i/2;
}

int binary_get_left_index(binaryheapQueue *heap, int i)
{
    return 2*i;
}

int binary_get_right_index(binaryheapQueue *heap, int i)
{
    return 2*i+1;
}

char binary_item_of(binaryheapQueue *heap, int i)
{
    return heap->data[i];
}

void binary_enqueue(binaryheapQueue *heap, char item, int *comparacoes)
{
    bool comp = comparacoes != NULL;

    if (heap->size >= MAX_HEAP_SIZE) {
        
        printf("Heap overflow!\n");
        exit(1);

    } else {

        heap->data[++heap->size] = item;

        int key_index = heap->size;
        int parent_index = get_parent_index(heap, heap->size);

        //parent_index >= i.e 'enquando não for a root'
        while (parent_index >= 1 &&
        heap->data[key_index] > heap->data[parent_index]) {
            if(comp) *comparacoes+=1;

            //a função swap estava se comportando de alguma forma errada
            //fazendo o swap 'manualmente' aqui dentro da função resolveu o problema
            //swap(&heap->data[key_index], &heap->data[parent_index]);
            int aux = heap->data[key_index];
            heap->data[key_index] = heap->data[parent_index];
            heap->data[parent_index] = aux;
            key_index = parent_index;
            parent_index = get_parent_index(heap, key_index);

        }
    }
}


void max_heapify(binaryheapQueue *heap, int i)
{
    int largest;
    int left_index = get_left_index(heap, i);
    int right_index = get_right_index(heap, i);

    if (left_index <= heap->size && heap->data[left_index] > heap->data[i]) 
    {
        largest = left_index;
    } 
    else 
        largest = i;

    if (right_index <= heap->size && heap->data[right_index] > heap->data[largest]) 
        largest = right_index;
    
    if (heap->data[i] != heap->data[largest]) 
    {
        //swap(&heap->data[i], &heap->data[largest]);
        int aux = heap->data[i];
        heap->data[i] = heap->data[largest];
        heap->data[largest] = aux;
        max_heapify(heap, largest);
    }
}

char dequeue_heap(binaryheapQueue *heap)
{
    if (heap->size <= 0) {
        printf("Heap underflow!\n");
        return -1;
    }
    
    int item = heap->data[1];
    heap->data[1] = heap->data[heap->size];
    heap->size--;

    // printf("Max heapify em %d\n",heap->data[1]);

    max_heapify(heap, 1);
    return item;
   
}